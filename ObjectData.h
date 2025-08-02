#ifndef OBJECT_H
#define OBJECT_H

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
	int type;

	ObjectData () : x(0.0f) ,y(0.0f) ,w(0.0f) ,h(0.0f) ,xmomentum(0.0f) ,ymomentum(0.0f) , type (0) {}
};

#endif