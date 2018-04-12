#include "Addin.h"

namespace Arma3Net
{
	IAddinInvocationMethod^ Addin::InvocationMethod::get(void)
	{
		return Addin::invocationMethod;
	}

	void Addin::InvocationMethod::set(IAddinInvocationMethod^ value)
	{
		Addin::invocationMethod = value;
	}
}