

#pragma once

#include "Addin.h"

namespace Arma3Net
{
	ref class AddinManager
	{
	private:
		System::Collections::Generic::Dictionary<System::String^, Addin^>^ loadedAddins;
	internal:
		AddinManager(void);
		void LoadAddins(void);
		System::String^ InvokeAddin(System::String^ name, System::String^ args, int maxResultSize);
	};
}