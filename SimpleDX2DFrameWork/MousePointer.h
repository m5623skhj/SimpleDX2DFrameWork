#pragma once
#include "ManagerDefine.h"
#include "Define.h"

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
	HWND hWnd;

	Position mousePosition;
	Position mouseWorldPosition;

	bool onMouseUI = false;
};