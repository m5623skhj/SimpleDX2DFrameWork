#pragma once
#include "ManagerDefine.h"
#include "D2DCommonHeader.h"
#include "Define.h"
#include <list>
#include <dwrite.h>

enum Alignment : unsigned char
{
	LeftAlign = 0,
	RightAlign,
	CenterAlign
};

class TextManager
{
	NON_COPYABLE_WITH_NON_DESTRUCTOR(TextManager);
	~TextManager();

public:
	[[nodiscard]]
	HRESULT Initialize(ID2D1HwndRenderTarget* inRenderTarget);

	void SendChattingMessage();
	void UserTextRendering(bool userChattingActive);
	void TextRendering();
	void SetAlignment(Alignment inAlignment);

private:
	std::wstring userText;
	std::list<std::wstring_view> chattingList;

private:
	ID2D1HwndRenderTarget* renderTarget;
	IDWriteFactory* writeFactory;
	IDWriteTextFormat* writeTextFormat;
	ID2D1SolidColorBrush* textBrush;

private:
	std::wstring_view textFormat = L"";
	const DWRITE_FONT_WEIGHT fontWeight = DWRITE_FONT_WEIGHT_SEMI_LIGHT;
	const DWRITE_FONT_STYLE fontStyle = DWRITE_FONT_STYLE_NORMAL;
	const DWRITE_FONT_STRETCH fontStretch = DWRITE_FONT_STRETCH_NORMAL;
	const float fontSize = 12;
	std::wstring_view languageCode = L"ko";
	const unsigned char userTextMaxSize = 30;
	const D2D1_RECT_F layoutRect;
};