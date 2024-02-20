#include "PreCompile.h"
#include "GameManager.h"
#include "InputManager.h"
#include "Camera.h"
#include "SoundManager.h"
#include "GameClient.h"

GameManager::GameManager()
{
	Initialize();
	InputManager::GetInst().Initialize();
	Camera::GetInst().Initialize();
	SoundManager::GetInst().Initialize();
}

void GameManager::Initialize()
{
	gameClient = new GameClient();
}

bool GameManager::Update(bool windowActive)
{
	if (windowActive == true)
	{
		InputManager::GetInst().InputProcess();
	}

	WORD posX, posY;
	Camera::GetInst().GetCameraPosition(posX, posY);

	return true;
}

void GameManager::Render()
{

}