

#pragma once

#include "AddinAttribute.h"

namespace Arma3Net
{
	ref class AddinInfo
	{
	internal:
		System::Type^ Type;
		AddinAttribute^ Attribute;
	};
}