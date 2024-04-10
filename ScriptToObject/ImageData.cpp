#include "PreCompile.h"
#include "ImageData.h"

#define CHECK_LOAD_RESULT(result) \
if (FAILED(result) == true) \
	return false;

ImageManager::ImageManager()
{
	HRESULT retval;

	retval = CoInitialize(NULL);
	if (FAILED(retval) == true)
	{
		std::cout << "CoInitialize() failed " << retval << std::endl;
		throw;
	}

	retval = CoCreateInstance(CLSID_WICImagingFactory
		, NULL
		, CLSCTX_INPROC_SERVER
		, IID_PPV_ARGS(&imagingFactory));
	if (FAILED(retval) == true)
	{
		std::cout << "CoCreateInstance() failed " << retval << std::endl;
		throw;
	}
}

bool ImageManager::LoadTargetImage(const std::wstring& imageFileName, ID2D1Bitmap* bitmapTarget)
{
	CHECK_LOAD_RESULT(imagingFactory->CreateDecoderFromFilename(
		imageFileName.c_str(),
		NULL,
		GENERIC_READ,
		WICDecodeMetadataCacheOnDemand,
		&bitmapDecoder));

	CHECK_LOAD_RESULT(bitmapDecoder->GetFrame(0, &frameDecoder));

	CHECK_LOAD_RESULT(imagingFactory->CreateFormatConverter(&formatConverter));

	CHECK_LOAD_RESULT(formatConverter->Initialize(
		frameDecoder,
		GUID_WICPixelFormat32bppPBGRA,
		WICBitmapDitherTypeNone,
		NULL,
		0.0f,
		WICBitmapPaletteTypeCustom));

	renderTarget->CreateBitmapFromWicBitmap(formatConverter, NULL, &bitmapTarget);

	return true;
}

bool ImageData::LoadTargetImage()
{
	std::wstring fileName;
	fileName.assign(imageName.begin(), imageName.end());

	return ImageManager::GetInst().LoadTargetImage(fileName, bitmapImage);
}