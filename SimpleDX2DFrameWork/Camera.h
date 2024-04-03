#pragma once
#include "Define.h"
#include "ManagerDefine.h"

enum class FadeInOut : BYTE
{
	Normal = 0,
	FadeIn,
	FadeOut
};

class Camera
{
	NON_COPYABLE(Camera);

public:
	void Initialize();

public:
	void InitPositionFromPlayer(const Position& playerPos);
	void SetPositionFromPlayer(const Position& playerPos);

	Position GetCameraPosition();
	void SetMapRange(const MapRange& inMapRange);

private:
	Position cameraPos;

private:
	MapRange mapRange;

#pragma region FadeIn/Out
public:
	void UpdateFadeInOut();
	void RenderFadeInOut();

	bool IsFadeInOutRunning();
	FadeInOut GetFadeInOutOrder();

private:
	void FadeIn();
	void FadeOut();

private:
	FadeInOut fadeInOutOrder = FadeInOut::Normal;
	float fadeInOutAlpha = 0.0f;

#pragma endregion FadeIn/Out
};