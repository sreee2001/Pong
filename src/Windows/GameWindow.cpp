#include <windows.h>

#include "Windows/GameWindow.h"
#include "Windows/WindowProc.h"

void GameWindow::Create ( HINSTANCE hInstance, int nCmdShow )
{
	WNDCLASSEX wc;

	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpfnWndProc = (WNDPROC)WindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.lpszClassName = TEXT("Pong 2D WindowClass");

	RegisterClassEx(&wc);

	hWnd = CreateWindowEx(	NULL,
							wc.lpszClassName,
							TEXT("Pong"),
							Windowed ? WS_OVERLAPPEDWINDOW : WS_EX_TOPMOST|WS_POPUP,
							0,
							0,
							Width,
							Height,
							NULL,
							NULL,
							hInstance,
							NULL);

	ShowWindow(hWnd, nCmdShow);
}