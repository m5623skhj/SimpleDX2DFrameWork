#include "PreCompile.h"
#include "MousePointer.h"
#include "InputManager.h"
#include "Camera.h"

void MousePointer::Initialize(HWND inHWnd)
{
	hWnd = inHWnd;
}

Position MousePointer::GetMousePosition()
{
	return mousePosition;
}

Position MousePointer::GetMouseWorldPosition()
{
	return mouseWorldPosition;
}

void MousePointer::Update()
{
	POINT mousePoint;

	GetCursorPos(&mousePoint);
	ScreenToClient(hWnd, &mousePoint);
	mousePosition = mousePoint;

	mouseWorldPosition = std::move(mousePosition + Camera::GetInst().GetCameraPosition());
}

void MousePointer::Render()
{
}