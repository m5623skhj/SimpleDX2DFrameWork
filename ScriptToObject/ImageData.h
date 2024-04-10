#pragma once
#include "DataObjectBase.h"
#include "DataMacro.h"
#include "D2DCommonHeader.h"

class ImageManager
{
	friend class ImageData;
	friend class ImageManagerImpl;

private:
	ImageManager();
	ImageManager(const ImageManager& other) = delete;
	ImageManager& operator=(const ImageManager& other) = delete;
	~ImageManager() = default;

private:
	static ImageManager& GetInst()
	{
		static ImageManager instance;
		return instance;
	}

public:
	bool LoadTargetImage(const std::wstring& imageFileName, ID2D1Bitmap* bitmapTarget);

protected:
	IWICImagingFactory* imagingFactory;
	IWICBitmapDecoder* bitmapDecoder;
	IWICBitmapFrameDecode* frameDecoder;
	IWICFormatConverter* formatConverter;

protected:
	ID2D1HwndRenderTarget* renderTarget;
};

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
		return LoadTargetImage();
	}

private:
	bool LoadTargetImage();

private:
	ID2D1Bitmap* bitmapImage;
};