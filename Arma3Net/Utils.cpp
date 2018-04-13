

#include "Utils.h"

using namespace System;
using namespace System::Globalization;
using namespace System::IO;
using namespace System::Reflection;

namespace Arma3Net
{
	void Utils::BaseDirectory::set(String^ value) { Utils::baseDirectory = value; }
	String^ Utils::BaseDirectory::get(void) { return Utils::baseDirectory; }
	void Utils::AddinDirectory::set(String^ value) { Utils::addinDirectory = value; }
	String^ Utils::AddinDirectory::get(void) { return Utils::addinDirectory; }
	void Utils::LogDirectory::set(String^ value) { Utils::logDirectory = value; }
	String^ Utils::LogDirectory::get(void) { return Utils::logDirectory; }

	static Utils::Utils()
	{
		BaseDirectory = Path::GetDirectoryName(Assembly::GetExecutingAssembly()->Location);
		AddinDirectory = Path::Combine(BaseDirectory, "Addins");
		LogDirectory = Path::GetDirectoryName(Assembly::GetExecutingAssembly()->Location); //Path::Combine(Environment::GetFolderPath(Environment::SpecialFolder::LocalApplicationData), "Arma3NET");
		//Directory::CreateDirectory(Utils::LogDirectory);
		logWriter = gcnew StreamWriter(Path::Combine(Utils::LogDirectory, "Arma3NET.log"), true);
	}

	void Utils::Log(String^ format, ... array<Object^>^ args)
	{
		Log(String::Format(format, args));
	}

	void Utils::Log(String^ message)
	{
		try
		{
#if (_DEBUG)
			System::Diagnostics::Debug::WriteLine(message);
#endif
			logWriter->WriteLine(DateTime::Now.ToString(CultureInfo::InvariantCulture) + " " + message);
			logWriter->Flush();
		}
		catch (...) { }
	}
}