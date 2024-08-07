#include "PreCompile.h"

#include "Define.h"
#include <windowsx.h>
#include "GameManager.h"

#include "JsonUtil.h"
#include "TestData.h"

HINSTANCE g_hInstance;
HWND g_hMainWnd;
bool g_windowActive = true;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void MainLoop(MSG& message);

int APIENTRY WinMain(HINSTANCE hInstansce, HINSTANCE prevInstance, LPSTR cmdParam, int cmdShow)
{
	if (JsonUtil::LoadAllDataScript() == false)
	{
		const std::wstring errorMessage = L"Failed to load data";

		MessageBox(NULL, errorMessage.c_str(), L"Error", MB_ICONERROR | MB_OK);
		return 0;
	}

	MSG message;
	WNDCLASS WndClass;

	g_hInstance = hInstansce;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstansce;
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.lpszClassName = TEXT("");
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	g_hMainWnd = CreateWindow(WndClass.lpszClassName, WndClass.lpszClassName, WS_OVERLAPPED | WS_POPUP,
		CW_USEDEFAULT, CW_USEDEFAULT, windowSizeX, windowSizeY,
		NULL, (HMENU)NULL, hInstansce, NULL);

	ShowWindow(g_hMainWnd, SW_SHOWMAXIMIZED);
	ShowCursor(FALSE);

	GameManager::GetInst().Initialize(g_hMainWnd);

	MainLoop(message);
	return (int)message.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{case WM_ACTIVATEAPP:
		g_windowActive = (bool)wParam;

		return 0;
	default:
		break;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}

void MainLoop(MSG& message)
{
	while (1)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT)
			{
				return;
			}

			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		else
		{
			if (GameManager::GetInst().Update(g_windowActive) == false)
				PostQuitMessage(0);
		}
	}
}