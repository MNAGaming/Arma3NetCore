

#pragma once

#include "AddinManager.h"

namespace Arma3Net
{
	public ref class Bridge abstract sealed
	{
	private:
		static System::Collections::Generic::Dictionary<System::String^, System::Reflection::Assembly^>^ assemblyCache;
		static AddinManager^ addinManager;
		static System::Reflection::Assembly^ ResolveAssembly(System::Object^ sender, System::ResolveEventArgs^ e);
		static Bridge(void);
	public:
		static System::String^ InvokeFunction(System::String^ name, System::String^ args, int maxResultSize);
		static void InvokeFunction(char* output, int outputSize, const char* function);
	};
}