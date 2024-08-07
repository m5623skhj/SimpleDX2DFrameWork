#include "PreCompile.h"
#include "GameManager.h"
#include "InputManager.h"
#include "Camera.h"
#include "SoundManagerImpl.h"
#include "ObjectManager.h"
#include "TextManager.h"
#include "ImageManagerImpl.h"
#include "PacketManager.h"
#include "GameClient.h"
#include "MousePointer.h"
#include "NetServerSerializeBuffer.h"

#define CHECK_REST_TIME() \
if (restTime >= oneFrameMaxTime) \
{ \
	restTime -= oneFrameMaxTime; \
	return true; \
}

void GameManager::Initialize(HWND hwnd)
{
	InitializeAllManager(hwnd);

	beforeTime = timeGetTime();
	checkTime = beforeTime;

	GameClient::GetInst().Start();
}

void GameManager::InitializeAllManager(HWND hwnd)
{
	InputManager::GetInst().Initialize();
	Camera::GetInst().Initialize();
	SoundManagerImpl::GetInst().Initialize();
	ObjectManager::GetInst().Initialize();
	if (FAILED(ImageManagerImpl::GetInst().Initialize(hwnd)))
	{
		throw;
	}
	if (FAILED(TextManager::GetInst().Initialize(ImageManagerImpl::GetInst().GetRenderTarget())))
	{
		throw;
	}
	MousePointer::GetInst().Initialize(hwnd);
	PacketManager::GetInst().Initialize();
}

bool GameManager::Update(bool windowActive)
{
	UpdateManagerClass(windowActive);
	UpdateObjectFromNetwork();

	if (CalculateCheckTime() == false)
	{
		return true;
	}
	Render();

	return true;
}

void GameManager::UpdateManagerClass(bool windowActive)
{
	if (windowActive == true)
	{
		InputManager::GetInst().InputProcess();
	}
	if (Camera::GetInst().IsFadeInOutRunning() == true)
	{
		Camera::GetInst().UpdateFadeInOut();
	}
	SoundManagerImpl::GetInst().UpdateSound();
	MousePointer::GetInst().Update();
}

void GameManager::UpdateObjectFromNetwork()
{
	int queueRestSize = GameClient::GetInst().GetRecvQueueUseSize();
	for (int i = 0; i < queueRestSize; ++i)
	{
		CNetServerSerializationBuf* buffer = nullptr;
		if (GameClient::GetInst().RecvPacket(&buffer) == false)
		{
			break;
		}

		// Update object from server packet
		ObjectManager::GetInst().ObjectNetworkProc(*buffer);
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

	if (deltaTime < oneFrameMaxTime)
	{
		CalculateSleepTime(deltaTime);
	}
	else
	{
		restTime += deltaTime - oneFrameMaxTime;
	}

	return true;
}

void GameManager::CalculateSleepTime(DWORD deltaTime)
{
	if (deltaTime + restTime < oneFrameMaxTime)
	{
		deltaTime += restTime;
		restTime = 0;
	}
	Sleep(oneFrameMaxTime - deltaTime);
	beforeTime += oneFrameMaxTime - deltaTime;
}

void GameManager::Render()
{
	auto cameraPos = Camera::GetInst().GetCameraPosition();

	ImageManagerImpl::GetInst().BeginDraw();

	// Render map
	ObjectManager::GetInst().RenderObjects();

	if (Camera::GetInst().IsFadeInOutRunning() == true)
	{
		Camera::GetInst().RenderFadeInOut();
	}

	MousePointer::GetInst().Render();

	ImageManagerImpl::GetInst().EndDraw();
}