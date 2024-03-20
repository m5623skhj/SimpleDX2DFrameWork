#pragma once
#include "D2DCommonHeader.h"
#include "ManagerDefine.h"

class ImageManager
{
	NON_COPYABLE(ImageManager);

#pragma region Rendering
public:
	[[nodiscard]]
	HRESULT Initialize(ID2D1HwndRenderTarget* inRenderTarget);

private:
	ID2D1HwndRenderTarget* renderTarget;
	IWICImagingFactory* imagingFactory;
#pragma endregion Rendering
};