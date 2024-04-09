#pragma once
#include "DataObjectBase.h"
#include "DataMacro.h"
#include "D2DCommonHeader.h"

class ImageData : public DataObjectBase
{
public:
	std::string imageName{};

public:
	SET_DATA_OBJECT(ImageData, imageName);

	virtual void LoadFromJson(const nlohmann::json& jsonObject) override
	{
		imageName = jsonObject["imageName"];
	}

	virtual bool PostLoad()
	{
		return true;
	}
};