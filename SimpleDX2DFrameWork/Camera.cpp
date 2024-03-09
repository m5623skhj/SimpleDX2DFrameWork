#include "PreCompile.h"
#include "Camera.h"

void Camera::Initialize()
{
	
}

void Camera::InitPositionFromPlayer(WORD playerPosX, WORD playerPosY)
{
	if (playerPosX <= halfOfCameraX)
	{
		cameraPosX = 0;
	}
	else if (playerPosX >= mapRange.right - halfOfCameraX)
	{
		cameraPosX = mapRange.right - halfOfCameraX;
	}
	else
	{
		cameraPosX = playerPosX - halfOfCameraX;
	}

	if (playerPosY <= halfOfCameraY)
	{
		cameraPosY = 0;
	}
	else if (playerPosY >= mapRange.bottom - halfOfCameraY)
	{
		cameraPosY = mapRange.bottom - halfOfCameraY;
	}
	else
	{
		cameraPosY = playerPosY;
	}
}

void Camera::SetPositionFromPlayer(WORD playerPosX, WORD playerPosY)
{
	int checkX = cameraPosX - halfOfCameraX;
	int checkY = cameraPosY - halfOfCameraY;

	if (checkX >= mapRange.left && checkX + halfOfCameraX <= mapRange.right)
	{
		cameraPosX = checkX;
	}
	else if (checkX < mapRange.left)
	{
		cameraPosX = 0;
	}
	else
	{
		cameraPosX = mapRange.right - halfOfCameraX;
	}

	if (checkY >= mapRange.top && checkY + halfOfCameraY <= mapRange.bottom)
	{
		cameraPosY = checkY;
	}
	else if (checkY < mapRange.top)
	{
		cameraPosY = 0;
	}
	else
	{
		cameraPosY = mapRange.bottom - halfOfCameraY;
	}
}

void Camera::GetCameraPosition(OUT WORD& outPosX, OUT WORD& outPosY)
{
	outPosX = cameraPosX;
	outPosY = cameraPosY;
}

void Camera::SetMapRange(const MapRange& inMapRange)
{
	mapRange = inMapRange;
}