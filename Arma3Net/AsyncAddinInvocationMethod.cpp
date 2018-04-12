

#include "Utils.h"
#include "Addin.h"

using namespace System;
using namespace System::Collections::Concurrent;
using namespace System::Threading::Tasks;

namespace Arma3Net
{
	public ref class AsyncAddinInvocationMethod : public IAddinInvocationMethod
	{
	private:
		initonly Addin^ addin;
		initonly bool storeResults = true;
		ConcurrentQueue<String^>^ results = gcnew ConcurrentQueue<String^>;
		Exception^ exception;

		void InvokeImpl(Object^ obj)
		{
			auto tuple = (Tuple<String^, int>^)obj;
			auto result = addin->Invoke(tuple->Item1, tuple->Item2);
			if (storeResults)
				results->Enqueue(result);
		}

		bool HandleException(Exception^ e)
		{
			exception = e;
			return true;
		}

		String^ TaskFaulted(Task^ task)
		{
			task->Exception->Handle(gcnew Func<Exception^, bool>(this, &AsyncAddinInvocationMethod::HandleException));
			return nullptr;
		}
	public:
		AsyncAddinInvocationMethod(Addin^ addin)
		{
			this->addin = addin;
		}

		AsyncAddinInvocationMethod(Addin^ addin, bool storeResults)
		{
			this->addin = addin;
			this->storeResults = storeResults;
		}

		virtual String^ Invoke(String^ args, int maxResultSize)
		{
			if (exception != nullptr)
			{
				Exception^ e = exception;
				exception = nullptr;
				throw e;
			}

			if (args != nullptr)
			{
				if (args->Equals("getresult", StringComparison::OrdinalIgnoreCase))
				{
					String^ result;
					results->TryDequeue(result);
					return result;
				}
				if (args->Equals("clearresults", StringComparison::OrdinalIgnoreCase))
				{
					results = gcnew ConcurrentQueue<String^>;
					return nullptr;
				}
			}

			auto tuple = Tuple::Create(args, maxResultSize);
			auto task = gcnew Task(gcnew Action<Object^>(this, &AsyncAddinInvocationMethod::InvokeImpl), tuple);
			task->ContinueWith(gcnew Func<Task^, String^>(this, &AsyncAddinInvocationMethod::TaskFaulted), TaskContinuationOptions::OnlyOnFaulted);
			task->Start();
			return nullptr;
		}
	};
}