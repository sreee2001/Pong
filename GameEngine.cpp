#include <windows.h>

#include "GameEngine.h"
#include "InputEngine.h"

GameEngine::GameEngine () 
{
}

void GameEngine::Initialize (HINSTANCE hInstance, GameWindow & gw)
{
	InitGameData (gameObjectData, gw);
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
		inputEngine.Update (& inputData);
		// Logic ();
		if (!logicEngine.Update ( gameObjectData , & inputData, gw))
			InitGameData (gameObjectData , gw);
		// Render ();
		renderEngine.Render ( gameObjectData );
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

	return true;
}

void GameEngine::InitGameData (ObjectData GameObjectData [], GameWindow & gw)
{
	// Initialize Ball
	GameObjectData[Ball].type = 4;
	GameObjectData[Ball].w = 16;
	GameObjectData[Ball].h = 16;
	GameObjectData[Ball].x = gw.Width / 2;
	GameObjectData[Ball].y = gw.Height/ 2;
	GameObjectData[Ball].xmomentum = 0.01f;
	GameObjectData[Ball].ymomentum = -0.3f;

	// Initialize Player 1
	GameObjectData[Player].type = 1;
	GameObjectData[Player].w = 85;
	GameObjectData[Player].h = 16;
	GameObjectData[Player].x = (gw.Width - GameObjectData[Player].w) / 2;
	GameObjectData[Player].y = gw.Height - GameObjectData[Player].h;
	GameObjectData[Player].xmomentum = 0.0f;

	// Initialize Player 2
	GameObjectData[Computer].type = 2;
	GameObjectData[Computer].w = 85;
	GameObjectData[Computer].h = 16;
	GameObjectData[Computer].x = (gw.Width - GameObjectData[Computer].w) / 2;
	GameObjectData[Computer].y = 0.0f;
	GameObjectData[Computer].xmomentum = 0.0f;
}