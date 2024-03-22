#pragma once
#include "D2DCommonHeader.h"
#include "ManagerDefine.h"

class GameManager
{
	NON_COPYABLE(GameManager);

public:
	void Initialize(HWND hwnd);

private:
	void InitializeD2D(HWND hwnd);
	void InitializeAllManager(HWND hwnd);

#pragma region Update
public:
	bool Update(bool windowActive);

private:
	void UpdateManagerClass(bool windowActive);
	void UpdateObjectFromNetwork();
	bool CalculateCheckTime();
	void CalculateSleepTime(DWORD deltaTime);
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