#include <windows.h>

#include "Engine/GameEngine.h"
#include "Engine/InputEngine.h"

GameEngine::GameEngine () 
{
}

void GameEngine::Initialize (HINSTANCE hInstance, GameWindow & gw)
{
	// Initialize data
	gamedata.InitData (gw);
	// register all the sub engines
	inputEngine.Initialize (hInstance, gw.hWnd);
	renderEngine.Initialize (gw);

	renderEngine.LoadGraphics ();
}

void GameEngine::Close ()
{
	// deregister all the sub engines
	inputEngine.Close ();
	renderEngine.Close ();
}

void GameEngine::Run (GameWindow & gw)
{
	while (HandleMessages())
	{
		// Input ();
		inputEngine.Update (inputData);
		// Logic ();
		if (!logicEngine.Update ( gamedata , inputData, gw))
			gamedata.InitData (gw);
		// Render ();
		renderEngine.Render ( gamedata );
	}
}

bool GameEngine::HandleMessages ()
{
	static MSG msg;

	if (PeekMessage ( &msg, 0, 0, 0, PM_REMOVE))
	{
		if (msg.message == WM_QUIT)
			return false;

		TranslateMessage (&msg);
		DispatchMessage (&msg);
	}
	// Default return true
	return true;
}