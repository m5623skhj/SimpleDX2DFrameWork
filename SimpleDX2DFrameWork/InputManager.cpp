#include "PreCompile.h"
#include "InputManager.h"

#define SET_KEY_CODE(inKeyCode, inRealKeyCode) keyArray[static_cast<int>(inKeyCode)].keyCode = static_cast<KeyCode>(inRealKeyCode)

void InputManager::Initialize()
{
	InitializeKeySetting();
}

void InputManager::InitializeKeySetting()
{
	keyArray.reserve(static_cast<int>(KeyCode::InvalidKeyCode));

	SET_KEY_CODE(KeyCode::ClickLeft, VK_LBUTTON);
	SET_KEY_CODE(KeyCode::ClickRight, VK_RBUTTON);
	SET_KEY_CODE(KeyCode::Enter, VK_RBUTTON);
	SET_KEY_CODE(KeyCode::Esc, VK_ESCAPE);
	SET_KEY_CODE(KeyCode::LeftShift, VK_LSHIFT);
	SET_KEY_CODE(KeyCode::LeftCtrl, VK_LCONTROL);

	SET_KEY_CODE(KeyCode::Q, 0x51);
	SET_KEY_CODE(KeyCode::W, 0x57);
	SET_KEY_CODE(KeyCode::E, 0x45);
	SET_KEY_CODE(KeyCode::R, 0x52);
	SET_KEY_CODE(KeyCode::A, 0x41);
	SET_KEY_CODE(KeyCode::S, 0x53);
	SET_KEY_CODE(KeyCode::D, 0x44);
	SET_KEY_CODE(KeyCode::F, 0x46);
	SET_KEY_CODE(KeyCode::Z, 0x5A);
	SET_KEY_CODE(KeyCode::X, 0x58);
	SET_KEY_CODE(KeyCode::C, 0x43);
	SET_KEY_CODE(KeyCode::V, 0x56);

	SET_KEY_CODE(KeyCode::LeftArrow, VK_LEFT);
	SET_KEY_CODE(KeyCode::RightArrow, VK_RIGHT);
	SET_KEY_CODE(KeyCode::UpArrow, VK_UP);
	SET_KEY_CODE(KeyCode::DownArrow, VK_DOWN);
}

void InputManager::InputProcess()
{
	keyPressInThisFrame = false;

	for (auto& key : keyArray)
	{
		if (key.keyCode == KeyCode::InvalidKeyCode)
		{
			continue;
		}
		
		if (GetAsyncKeyState(static_cast<int>(key.keyCode)) & 0x8000)
		{
			if (key.pushing == true)
			{
				key.pushNow = false;
			}
			else
			{
				key.pushNow = true;
			}

			keyPressInThisFrame = true;
			key.pushing = true;
		}
		else
		{
			if (key.pushing == true)
			{
				key.SetKeyState(false, true, false);
			}
			else
			{
				key.SetKeyState(false, key.pushing, false);
			}
		}
	}
}

bool InputManager::GetKeyPressThisFrame()
{
	return keyPressInThisFrame;
}

bool InputManager::IsPressKey(KeyCode confirmKey)
{
	return keyArray[static_cast<int>(confirmKey)].pushing;
}

bool InputManager::IsPressKeyThisFrame(KeyCode confirmKey)
{
	return keyArray[static_cast<int>(confirmKey)].pushNow;
}

bool InputManager::IsPopKeyThisFrame(KeyCode confirmKey)
{
	return keyArray[static_cast<int>(confirmKey)].popNow;
}

KeyState InputManager::GetKeyState(KeyCode confirmKey)
{
	return keyArray[static_cast<int>(confirmKey)];
}