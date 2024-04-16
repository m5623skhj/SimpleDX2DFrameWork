#pragma once
#include "D2DCommonHeader.h"
#include "ManagerDefine.h"

class GameManager
{
	NON_COPYABLE(GameManager);

public:
	void Initialize(HWND hwnd);

private:
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
#pragma endregion Update
};