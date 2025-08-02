#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "InputData.h"
#include "InputEngine.h";
#include "ObjectData.h"
#include "GameWindow.h"
#include "RenderEngine.h"
#include "LogicEngine.h"

class GameEngine
{
public:
	// constructor
	GameEngine ();

	void Initialize (HINSTANCE hInstance, GameWindow & gw);
	void Run (GameWindow & gw);
	void Close ();
private:
	void InitGameData (ObjectData gameObjectData [], GameWindow & gw);
	bool HandleMessages ();

	//GameData		& gamedata;
	InputEngine		inputEngine;
	RenderEngine	renderEngine;
	//AudioEngine	& audioengine;
	LogicEngine		logicEngine;
	InputData		inputData;
	ObjectData		gameObjectData [10];
};

#endif