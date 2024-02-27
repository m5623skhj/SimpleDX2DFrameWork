#include "PreCompile.h"
#include "Camera.h"

void Camera::Initialize()
{
	
}

void Camera::InitPositionFromPlayer(WORD playerPosX, WORD playerPosY)
{

}

void Camera::SetPositionFromPlayer(WORD playerPosX, WORD playerPosY)
{

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