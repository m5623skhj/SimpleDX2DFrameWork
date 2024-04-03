#pragma once
#include <string>
#include "ManagerDefine.h"

namespace Configuration
{
	class Config
	{
		NON_COPYABLE_WITH_NON_DESTRUCTOR(Config);

	public:
		bool LoadConfig();

	private:
		const std::string configFilePath = "";
		std::string scriptFolderPath = "";
	};
}