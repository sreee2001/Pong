#ifndef GAMEDATA_H
#define GAMEDATA_H

class GameWindow;	// forward declarations

#define NUM_OBJECTS 3

enum ObjectType
{
	Ball = 0,
	Player = 1,
	Computer = 2
};

class ObjectData
{
public:
	float x,y;
	float w,h;
	float xmomentum, ymomentum;
	int frameIndex;

	ObjectData () : x(0.0f) ,y(0.0f) ,w(0.0f) ,h(0.0f) ,xmomentum(0.0f) ,ymomentum(0.0f) , frameIndex (0) {}
};

class GameData
{
public:
	ObjectData gameObjData [NUM_OBJECTS];

	void InitData (GameWindow & gw);
};

#endif