#include "PreCompile.h"
#include "ImageManagerImpl.h"
#include "nlohmann/json.hpp"
#include "Define.h"

HRESULT ImageManagerImpl::Initialize(HWND hwnd)
{
	HRESULT result;
	do
	{
		result = D2D1CreateFactory(D2D1_FACTORY_TYPE_MULTI_THREADED, &d2dFactory);
		if (FAILED(result) == true)
		{
			break;
		}

		result = d2dFactory->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties()
			, D2D1::HwndRenderTargetProperties(hwnd, D2D1::SizeU(windowSizeX, windowSizeY))
			, &d2dRenderTarget);
		if (FAILED(result) == true)
		{
			break;
		}

	} while (false);

	return result;
}

void ImageManagerImpl::BeginDraw()
{
	d2dRenderTarget->BeginDraw();
}

void ImageManagerImpl::EndDraw()
{
	d2dRenderTarget->EndDraw();
}