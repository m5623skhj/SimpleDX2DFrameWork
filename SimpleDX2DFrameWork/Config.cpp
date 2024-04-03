#include "PreCompile.h"
#include "Config.h"
#include <fstream>
#include <nlohmann/json.hpp>

namespace Configuration
{
	bool Config::LoadConfig()
	{
		std::ifstream configFile(configFilePath);
		if (configFile.is_open() == false)
		{
			std::cout << "Invalid configuration path : " << configFilePath << std::endl;
			return false;
		}

		try
		{
			nlohmann::json jsonData;
			configFile >> jsonData;

			Config::GetInst().scriptFolderPath = jsonData["ScriptFolderPath"];
		}
		catch (nlohmann::json::parse_error& e)
		{
			std::cout << "Parsing error : " << e.what() << std::endl;
			return false;
		}

		return true;
	}
}