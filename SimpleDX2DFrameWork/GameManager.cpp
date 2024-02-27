#include "PreCompile.h"
#include "GameManager.h"
#include "InputManager.h"
#include "Camera.h"
#include "SoundManager.h"
#include "ObjectManager.h"
#include "TextManager.h"
#include "ImageManager.h"
#include "GameClient.h"
#include "NetServerSerializeBuffer.h"
#include "Define.h"

#define CHECK_REST_TIME() \
if (restTime >= oneFrameMaxTime) \
{ \
	restTime -= oneFrameMaxTime; \
	return true; \
}

void GameManager::Initialize(HWND hwnd)
{
	InitializeD2D(hwnd);
	InitializeAllManager();

	beforeTime = timeGetTime();
	checkTime = beforeTime;

	gameClient = new GameClient();

	gameClient->Start();
}

void GameManager::InitializeAllManager()
{
	InputManager::GetInst().Initialize();
	Camera::GetInst().Initialize();
	SoundManager::GetInst().Initialize();
	ObjectManager::GetInst().Initialize();
	TextManager::GetInst().Initialize();
	ImageManager::GetInst().Initialize(d2dRenderTarget);
}

void GameManager::InitializeD2D(HWND hwnd)
{
	if (FAILED(D2D1CreateFactory(D2D1_FACTORY_TYPE_MULTI_THREADED, &d2dFactory)) == true)
	{
		throw;
	}

	if (FAILED(d2dFactory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties()
		, D2D1::HwndRenderTargetProperties(hwnd, D2D1::SizeU(windowSizeX, windowSizeY))
		, &d2dRenderTarget)) == true)
	{
		throw;
	}
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
		ObjectManager::GetInst().ObjectNetworkProc(buffer);
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
	d2dRenderTarget->BeginDraw();

	// �� ������
	
	// ������Ʈ ������
	ObjectManager::GetInst().RenderObjects();

	// ���콺 ������ ������

	d2dRenderTarget->EndDraw();
}