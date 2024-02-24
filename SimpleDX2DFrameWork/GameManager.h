#pragma once
#include "D2DCommonHeader.h"

class GameClient;

class GameManager
{
private:
	GameManager() = default;
	~GameManager() = default;
	GameManager(const GameManager& other) = delete;
	GameManager& operator=(const GameManager& other) = delete;

public:
	static GameManager& GetInst()
	{
		static GameManager instance;
		return instance;
	}

public:
	void Initialize(HWND hwnd);

private:
	void InitializeD2D(HWND hwnd);
	void InitializeAllManager();

private:
	GameClient* gameClient;

#pragma region Update
public:
	bool Update(bool windowActive);

private:
	void UpdateObjectFromNetwork();
	bool CalculateCheckTime();
	void Render();

private:
	DWORD beforeTime;
	DWORD checkTime;
	DWORD restTime;

private:
	ID2D1Factory* d2dFactory;
	ID2D1HwndRenderTarget* d2dRenderTarget;
#pragma endregion Update
};