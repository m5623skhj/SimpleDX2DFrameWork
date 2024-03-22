#pragma once
#include <vector>
#include "enum.h"
#include "ManagerDefine.h"

class InputManager
{
	NON_COPYABLE(InputManager);

public:
	void Initialize();

public:
	void InputProcess();

	bool GetKeyPressThisFrame();
	bool IsPressKey(int confirmKey);
	bool IsPressKeyThisFrame(int confirmKey);
	bool IsPopKeyThisFrame(int confirmKey);

private:
	void InitializeKeySetting();

private:
	bool inputStop = false;
	bool keyPressInThisFrame = false;
	std::vector<KeyState> keyArray;
};