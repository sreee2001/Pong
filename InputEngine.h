#ifndef INPUTENGINE_H
#define INPUTENGINE_H

#include "DirectInput.h"

class InputData;

class InputEngine
{
public:
	void Initialize (HINSTANCE hInstance, HWND hWnd);
	void Update (InputData * data);
	void Close ();
private:
	DirectInput directinput;
};

#endif