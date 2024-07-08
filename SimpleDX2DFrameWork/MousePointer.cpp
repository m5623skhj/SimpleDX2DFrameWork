#include "PreCompile.h"
#include "MousePointer.h"
#include "InputManager.h"
#include "Camera.h"

void MousePointer::Initialize(HWND inHWnd)
{
	hWnd = inHWnd;

	// mouse left button 0, right button 1
	mouseButtonArray.reserve(2);
	mouseButtonArray[0].keyCode = KeyCode::ClickLeft;
	mouseButtonArray[1].keyCode = KeyCode::ClickRight;

	mouseButtonArray[0].SetButtonEvents(
		std::bind(&MousePointer::MouseLeftButtonClick, this),
		std::bind(&MousePointer::MouseLeftButtonPop, this),
		std::bind(&MousePointer::MouseLeftButtonPushing, this));

	mouseButtonArray[1].SetButtonEvents(
		std::bind(&MousePointer::MouseRightButtonClick, this),
		std::bind(&MousePointer::MouseRightButtonPop, this),
		std::bind(&MousePointer::MouseRightButtonPushing, this));
}

Position MousePointer::GetMousePosition()
{
	return mousePosition;
}

Position MousePointer::GetMouseWorldPosition()
{
	return mouseWorldPosition;
}

void MousePointer::SetMouseOnUI(bool isOnMouse)
{
	onMouseUI = isOnMouse;
}

void MousePointer::Update()
{
	POINT mousePoint;

	GetCursorPos(&mousePoint);
	ScreenToClient(hWnd, &mousePoint);
	mousePosition = mousePoint;

	mouseWorldPosition = std::move(mousePosition + Camera::GetInst().GetCameraPosition());
	for (auto& mouseButton : mouseButtonArray)
	{
		mouseButton.Update(InputManager::GetInst().GetKeyState(mouseButton.keyCode));
	}
}

void MousePointer::Render()
{
}

void MousePointer::MouseLeftButtonClick()
{

}

void MousePointer::MouseLeftButtonPop()
{

}

void MousePointer::MouseLeftButtonPushing()
{

}
void MousePointer::MouseRightButtonClick()
{

}

void MousePointer::MouseRightButtonPop()
{

}

void MousePointer::MouseRightButtonPushing()
{

}