#pragma once
#include "ManagerDefine.h"
#include "Define.h"
#include <functional>

struct MouseButtonState : public KeyState
{
	void Update(const KeyState& inKeyState)
	{
		pushNow = inKeyState.pushNow;
		popNow = inKeyState.popNow;
		pushing = inKeyState.pushing;

		CallButtonEvent();
	}

	void SetButtonEvents(
		std::function<void()>&& buttonEventClick,
		std::function<void()>&& buttonEventPop,
		std::function<void()>&& buttonEventPushing)
	{
		callbackButtonEventClick = std::move(buttonEventClick);
		callbackButtonEventPop = std::move(buttonEventPop);
		callbackButtonEventPushing = std::move(buttonEventPushing);
	}

private:
	void CallButtonEvent()
	{
		if (pushNow)
		{
			if (callbackButtonEventClick)
			{
				callbackButtonEventClick();
			}
		}
		else if (popNow)
		{
			if (callbackButtonEventPop)
			{
				callbackButtonEventPop();
			}
		}
		else if (pushing)
		{
			if (callbackButtonEventPushing)
			{
				callbackButtonEventPushing();
			}
		}
	}

	std::function<void()> callbackButtonEventClick{};
	std::function<void()> callbackButtonEventPop{};
	std::function<void()> callbackButtonEventPushing{};
};

class MousePointer
{
	NON_COPYABLE(MousePointer);

public:
	void Initialize(HWND inHWnd);

public:
	Position GetMousePosition();
	Position GetMouseWorldPosition();

	void SetMouseOnUI(bool isOnMouse);

public:
	void Update();
	void Render();

private:
	void MouseLeftButtonClick();
	void MouseLeftButtonPop();
	void MouseLeftButtonPushing();
	void MouseRightButtonClick();
	void MouseRightButtonPop();
	void MouseRightButtonPushing();

private:
	HWND hWnd;

	Position mousePosition;
	Position mouseWorldPosition;

	bool onMouseUI = false;

private:
	std::vector<MouseButtonState> mouseButtonArray;
};