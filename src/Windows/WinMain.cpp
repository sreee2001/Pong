#include <windows.h>

#include "Windows/GameWindow.h"
#include "Engine/GameEngine.h"

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine , int nCmdShow )
{
	GameWindow gw;
	gw.Width = 1024;
	gw.Height = 768;
	gw.Windowed = true;

	gw.Create (hInstance , nCmdShow);

	GameEngine gameEngine;

	gameEngine.Initialize(hInstance, gw);

	gameEngine.Run(gw);

	gameEngine.Close ();
}