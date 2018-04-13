

#pragma once

namespace Arma3Net
{
	public interface class IAddinInvocationMethod
	{
		System::String^ Invoke(System::String^ args, int maxResultSize);
	};
}