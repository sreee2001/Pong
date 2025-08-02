#ifndef LOGICENGINE_H
#define LOGICENGINE_H

#include "ObjectData.h"
#include "InputData.h"
#include "gameWindow.h"

class LogicEngine
{
public:
	bool Update (ObjectData GameObjectData [] , InputData * inputData, GameWindow & gw);
};

#endif