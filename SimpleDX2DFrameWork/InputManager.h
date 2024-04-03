#pragma once
#include <vector>
#include "ManagerDefine.h"
#include "Define.h"

class InputManager
{
	NON_COPYABLE(InputManager);

public:
	void Initialize();

public:
	void InputProcess();

	bool GetKeyPressThisFrame();
	bool IsPressKey(KeyCode confirmKey);
	bool IsPressKeyThisFrame(KeyCode confirmKey);
	bool IsPopKeyThisFrame(KeyCode confirmKey);

private:
	void InitializeKeySetting();

private:
	bool inputStop = false;
	bool keyPressInThisFrame = false;
	std::vector<KeyState> keyArray;
};