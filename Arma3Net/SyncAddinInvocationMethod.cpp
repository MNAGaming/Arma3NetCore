

#include "SyncAddinInvocationMethod.h"
#include "Addin.h"

using namespace System;

namespace Arma3Net
{
	SyncAddinInvocationMethod::SyncAddinInvocationMethod(Addin^ addin)
	{
		this->addin = addin;
	}

	String^ SyncAddinInvocationMethod::Invoke(String^ args, int maxResultSize)
	{
		return addin->Invoke(args, maxResultSize);
	}
}