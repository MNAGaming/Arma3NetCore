

#pragma once

namespace Arma3Net
{
	[System::AttributeUsageAttribute(System::AttributeTargets::Class)]
	public ref struct AddinAttribute : public System::Attribute
	{
		property System::String^ Name;
		property System::String^ Version;
		property System::String^ Author;
		property System::String^ Description;
		AddinAttribute(System::String^ name);
	};
}