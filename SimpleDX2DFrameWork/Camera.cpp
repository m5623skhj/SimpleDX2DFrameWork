#include "PreCompile.h"
#include "Camera.h"

void Camera::Initialize()
{
	
}

void Camera::InitPositionFromPlayer(const Position& playerPos)
{
	if (playerPos.posX <= halfOfCameraX)
	{
		cameraPos.posX = 0;
	}
	else if (playerPos.posX >= mapRange.right - halfOfCameraX)
	{
		cameraPos.posX = mapRange.right - halfOfCameraX;
	}
	else
	{
		cameraPos.posX = playerPos.posX - halfOfCameraX;
	}

	if (playerPos.posY <= halfOfCameraY)
	{
		cameraPos.posY = 0;
	}
	else if (playerPos.posY >= mapRange.bottom - halfOfCameraY)
	{
		cameraPos.posY = mapRange.bottom - halfOfCameraY;
	}
	else
	{
		cameraPos.posY = playerPos.posY;
	}
}

void Camera::SetPositionFromPlayer(const Position& playerPos)
{
	int checkX = cameraPos.posX - halfOfCameraX;
	int checkY = cameraPos.posY - halfOfCameraY;

	if (checkX >= mapRange.left && checkX + halfOfCameraX <= mapRange.right)
	{
		cameraPos.posX = checkX;
	}
	else if (checkX < mapRange.left)
	{
		cameraPos.posX = 0;
	}
	else
	{
		cameraPos.posX = mapRange.right - halfOfCameraX;
	}

	if (checkY >= mapRange.top && checkY + halfOfCameraY <= mapRange.bottom)
	{
		cameraPos.posY = checkY;
	}
	else if (checkY < mapRange.top)
	{
		cameraPos.posY = 0;
	}
	else
	{
		cameraPos.posY = mapRange.bottom - halfOfCameraY;
	}
}

Position Camera::GetCameraPosition()
{
	return cameraPos;
}

void Camera::SetMapRange(const MapRange& inMapRange)
{
	mapRange = inMapRange;
}

void Camera::UpdateFadeInOut()
{
	if (fadeInOutOrder == FadeInOut::FadeIn)
	{
		FadeIn();
	}
	else if (fadeInOutOrder == FadeInOut::FadeOut)
	{
		FadeOut();
	}
}

void Camera::RenderFadeInOut()
{
	if (fadeInOutOrder != FadeInOut::Normal)
	{
		// ImageManager::GetInst().TargetRendering(alpha);
	}
}

bool Camera::IsFadeInOutRunning()
{
	return fadeInOutOrder != FadeInOut::Normal;
}

FadeInOut Camera::GetFadeInOutOrder()
{
	return fadeInOutOrder;
}

void Camera::FadeIn()
{
	fadeInOutAlpha -= fadInOutValue;

	if (fadeInOutAlpha <= 0.0f)
	{
		fadeInOutAlpha = FadeInOut::Normal;
		fadeInOutAlpha = 0.0f;
	}
}

void Camera::FadeOut()
{
	fadeInOutAlpha += fadeInOutAlpha;

	if (fadeInOutAlpha >= 1.0f)
	{
		fadeInOutAlpha = FadeInOut::Normal;
		fadeInOutAlpha = 1.0f;
	}
}