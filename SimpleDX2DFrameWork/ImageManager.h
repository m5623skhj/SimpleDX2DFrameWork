#pragma once
#include "D2DCommonHeader.h"

class ImageManager
{
private:
	ImageManager() = default;
	~ImageManager() = default;
	ImageManager(const ImageManager& other) = delete;
	ImageManager& operator=(const ImageManager& other) = delete;

public:
	static ImageManager& GetInst()
	{
		static ImageManager instance;
		return instance;
	}

#pragma region Rendering
public:
	HRESULT Initialize(ID2D1HwndRenderTarget* inRenderTarget);

private:
	ID2D1HwndRenderTarget* renderTarget;
	IWICImagingFactory* imagingFactory;
#pragma endregion Rendering
};