

#pragma once

#include "Addin.h"

namespace Arma3Net
{
	public ref class Utils abstract sealed
	{
	private:
		static System::IO::StreamWriter^ logWriter;
		static System::String^ baseDirectory;
		static System::String^ addinDirectory;
		static System::String^ logDirectory;
	internal:
		static System::Collections::Generic::Dictionary<System::String^, Addin^>^ LoadedAddins;
	public:
		static property System::String^ BaseDirectory { System::String^ get(void); private: void set(System::String^ value); }
		static property System::String^ AddinDirectory { System::String^ get(void); private: void set(System::String^ value); }
		static property System::String^ LogDirectory { System::String^ get(void); private: void set(System::String^ value); }
		static Utils();
		static void Log(System::String^ format, ... array<Object^>^ args);
		static void Log(System::String^ message);
	};
}