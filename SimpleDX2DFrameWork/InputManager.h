#pragma once
#include <vector>
#include "KeyCode.h"
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
	struct KeyState
	{
		KeyState()
		{
			SetKeyState(false, false, false);
			keyCode = KeyCode::InvalidKeyCode;
		}

		void SetKeyState(bool inPushNow, bool inPushing, bool inPopNow)
		{
			pushNow = inPushNow;
			pushing = inPushing;
			popNow = inPopNow;
		}

		bool pushNow;
		bool pushing;
		bool popNow;

		KeyCode keyCode;
	};

	bool inputStop = false;
	bool keyPressInThisFrame = false;
	std::vector<KeyState> keyArray;

private:
};