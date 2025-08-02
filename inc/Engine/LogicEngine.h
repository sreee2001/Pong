#ifndef LOGICENGINE_H
#define LOGICENGINE_H

class GameData;
class InputData;
class GameWindow;

class LogicEngine
{
public:
	bool Update (GameData & gameData , InputData & inputData, GameWindow & gw);
};

#endif