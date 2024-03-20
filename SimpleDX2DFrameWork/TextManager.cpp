#include "PreCompile.h"
#include "TextManager.h"

TextManager::~TextManager()
{
	textBrush->Release();
	writeFactory->Release();
	writeTextFormat->Release();
}

HRESULT TextManager::Initialize(ID2D1HwndRenderTarget* inRenderTarget)
{
	renderTarget = inRenderTarget;

	HRESULT result;
	do
	{
		result = DWriteCreateFactory(DWRITE_FACTORY_TYPE_ISOLATED, __uuidof(writeFactory), (IUnknown**)&writeFactory);
		CHECK_RETVAL_WITH_BREAK(result);

		result = writeFactory->CreateTextFormat(textFormat.data(), NULL, fontWeight, fontStyle, fontStretch,
			fontSize, languageCode.data(), &writeTextFormat);
		CHECK_RETVAL_WITH_BREAK(result);

		renderTarget->CreateSolidColorBrush(D2D1::ColorF(1, 1, 1, 1.0f), &textBrush);
	} while (false);

	return result;
}

void TextManager::SendChattingMessage()
{

}

void TextManager::UserTextRendering(bool userChattingActive)
{
	if (userChattingActive == false)
	{
		return;
	}

	size_t textLength = userText.size();
	if (textLength > userTextMaxSize)
	{
		textLength = userTextMaxSize;
	}

	renderTarget->DrawText(userText.c_str(), (int)textLength, writeTextFormat, &layoutRect, textBrush);
}

void TextManager::TextRendering()
{

}

void TextManager::SetAlignment(Alignment inAlignment)
{
	writeTextFormat->SetTextAlignment((DWRITE_TEXT_ALIGNMENT)inAlignment);
}