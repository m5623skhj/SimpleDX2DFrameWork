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
	HRESULT Initialize();

private:

#pragma endregion Rendering
};