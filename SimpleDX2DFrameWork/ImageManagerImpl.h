#pragma once
#include "D2DCommonHeader.h"
#include "ManagerDefine.h"
#include "ImageData.h"

class ImageManagerImpl
{
	NON_COPYABLE(ImageManagerImpl);

#pragma region Rendering
public:
	[[nodiscard]]
	HRESULT Initialize(HWND hwnd);

public:
	ID2D1HwndRenderTarget* GetRenderTarget()
	{
		return d2dRenderTarget;
	}

public:
	void BeginDraw();
	void EndDraw();

private:
	ID2D1Factory* d2dFactory;
	ID2D1HwndRenderTarget* d2dRenderTarget;
#pragma endregion Rendering
};