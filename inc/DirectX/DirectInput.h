#ifndef DIRECTINPUT_H
#define DIRECTINPUT_H

#include <dinput.h>

#pragma comment (lib, "dinput.lib")
#pragma comment (lib, "dinput8.lib")
#pragma comment (lib, "dxguid.lib")

class DirectInput
{
public:
	// Constructor
	DirectInput ();

	void Init(HINSTANCE hInstance, HWND hWnd);
	void GetKeys(BYTE* KeyState);
	void GetMouse(DIMOUSESTATE* MouseState);
	void Close(void);
private:
	LPDIRECTINPUT8			din;
	LPDIRECTINPUTDEVICE8	dinkeyboard;
	LPDIRECTINPUTDEVICE8	dinmouse;
};

#endif