#include "PreCompile.h"
#include "ImageManager.h"

#define CHECK_RETVAL_WITH_BREAK(input) \
if (FAILED(input) == true) \
{ \
	break; \
}

HRESULT ImageManager::Initialize(ID2D1HwndRenderTarget* inRenderTarget)
{
	renderTarget = inRenderTarget;

	HRESULT retval;
	do
	{
		retval = CoInitialize(NULL);
		CHECK_RETVAL_WITH_BREAK(retval);

		retval = CoCreateInstance(CLSID_WICImagingFactory
			, NULL
			, CLSCTX_INPROC_SERVER
			, IID_PPV_ARGS(&imagingFactory));
		CHECK_RETVAL_WITH_BREAK(retval);
	} while (false);

	return retval;
}