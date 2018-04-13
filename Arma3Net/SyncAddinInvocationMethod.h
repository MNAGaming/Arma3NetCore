

#pragma once

#include "Addin.h"

namespace Arma3Net
{
	public ref class SyncAddinInvocationMethod : public IAddinInvocationMethod
	{
	private:
		initonly Addin^ addin;
	public:
		SyncAddinInvocationMethod(Addin^ addin);
		virtual System::String^ Invoke(System::String^ args, int maxResultSize);
	};
}