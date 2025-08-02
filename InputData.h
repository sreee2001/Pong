#ifndef INPUTDATA_H
#define INPUTDATA_H

class InputData
{
public:
	int MoveHorizontal;
	bool AccelerateLeft;
	bool AccelerateRight;
	
	void Reset ()
	{
		MoveHorizontal= 0;
		AccelerateLeft = false;
		AccelerateRight = false;
	}
};

#endif