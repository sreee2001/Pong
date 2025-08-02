#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "GameData/InputData.h"
#include "GameData/GameData.h"

#include "Windows/GameWindow.h"

#include "Engine/InputEngine.h";
#include "Engine/RenderEngine.h"
#include "Engine/LogicEngine.h"

class GameEngine
{
public:
	// constructor
	GameEngine ();

	void Initialize (HINSTANCE hInstance, GameWindow & gw);
	void Run (GameWindow & gw);
	void Close ();
private:
	bool HandleMessages ();

	InputEngine		inputEngine;
	RenderEngine	renderEngine;
	LogicEngine		logicEngine;
	//AudioEngine	audioengine;

	InputData		inputData;
	GameData		gamedata;
};

#endif