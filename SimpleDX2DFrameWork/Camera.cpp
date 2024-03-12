#include "PreCompile.h"
#include "Camera.h"

void Camera::Initialize()
{
	
}

void Camera::InitPositionFromPlayer(WORD playerPosX, WORD playerPosY)
{
	if (playerPosX <= halfOfCameraX)
	{
		cameraPos.posX = 0;
	}
	else if (playerPosX >= mapRange.right - halfOfCameraX)
	{
		cameraPos.posX = mapRange.right - halfOfCameraX;
	}
	else
	{
		cameraPos.posX = playerPosX - halfOfCameraX;
	}

	if (playerPosY <= halfOfCameraY)
	{
		cameraPos.posY = 0;
	}
	else if (playerPosY >= mapRange.bottom - halfOfCameraY)
	{
		cameraPos.posY = mapRange.bottom - halfOfCameraY;
	}
	else
	{
		cameraPos.posY = playerPosY;
	}
}

void Camera::SetPositionFromPlayer(WORD playerPosX, WORD playerPosY)
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