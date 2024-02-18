#pragma once

class InputManager
{
private:
	InputManager() = default;
	~InputManager() = default;
	InputManager(const InputManager& other) = delete;
	InputManager& operator=(const InputManager& other) = delete;

public:
	static InputManager& GetInst()
	{
		static InputManager instance;
		return instance;
	}

public:
	void InputProcess();

	bool GetKeyPressThisFrame();
	bool IsPressKey(int confirmKey);
	bool IsPressKeyThisFrame(int confirmKey);
	bool IsPopKeyThisFrame(int confirmKey);
};