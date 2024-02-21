#include "PreCompile.h"
#include "GameManager.h"
#include "InputManager.h"
#include "Camera.h"
#include "SoundManager.h"
#include "ObjectManager.h"
#include "GameClient.h"
#include "NetServerSerializeBuffer.h"
#include "Define.h"

#define CHECK_REST_TIME() \
if (restTime >= ONE_FRAME_MAX_TIME) \
{ \
	restTime -= ONE_FRAME_MAX_TIME; \
	return true; \
}

GameManager::GameManager()
{
	Initialize();
	InputManager::GetInst().Initialize();
	Camera::GetInst().Initialize();
	SoundManager::GetInst().Initialize();
	ObjectManager::GetInst().Initialize();

	gameClient->Start();
}

void GameManager::Initialize()
{
	beforeTime = timeGetTime();
	checkTime = beforeTime;

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

	UpdateObjectFromNetwork();

	if (CalculateCheckTime() == false)
	{
		return true;
	}
	Render();

	return true;
}

void GameManager::UpdateObjectFromNetwork()
{
	int queueRestSize = gameClient->GetRecvQueueUseSize();
	for (int i = 0; i < queueRestSize; ++i)
	{
		CNetServerSerializationBuf* buffer = nullptr;
		if (gameClient->RecvPacket(&buffer) == false)
		{
			break;
		}

		// Update object from server packet
		CNetServerSerializationBuf::Free(buffer);
	}
}

bool GameManager::CalculateCheckTime()
{
	CHECK_REST_TIME();

	checkTime = timeGetTime();
	CHECK_REST_TIME();

	DWORD nowTime = timeGetTime();
	DWORD deltaTime = nowTime - beforeTime;
	beforeTime = nowTime;

	if (deltaTime < ONE_FRAME_MAX_TIME)
	{
		if (deltaTime + restTime < ONE_FRAME_MAX_TIME)
		{
			deltaTime += restTime;
			restTime = 0;
		}
		Sleep(ONE_FRAME_MAX_TIME - deltaTime);
		beforeTime += ONE_FRAME_MAX_TIME - deltaTime;
	}
	else
	{
		restTime += deltaTime - ONE_FRAME_MAX_TIME;
	}

	return true;
}

void GameManager::Render()
{

}