#include <windows.h>

#include "GameWindow.h"
#include "GameEngine.h"

int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine , int nCmdShow )
{
	GameWindow gw;

	gw.Create (hInstance , nCmdShow);

	GameEngine gameEngine;

	gameEngine.Initialize(hInstance, gw);

	gameEngine.Run(gw);

	gameEngine.Close ();
}