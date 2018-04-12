

#pragma once

#include "IAddinInvocationMethod.h"

namespace Arma3Net
{
	public ref class Addin abstract
	{
	private:
		IAddinInvocationMethod^ invocationMethod;
	public:
		property IAddinInvocationMethod^ InvocationMethod
		{
			virtual IAddinInvocationMethod^ get(void);
			virtual void set(IAddinInvocationMethod^ value);
		}

		virtual System::String^ Invoke(System::String^ args, int maxResultSize) abstract;
	};
}

