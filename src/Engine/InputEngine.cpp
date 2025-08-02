#include "Engine/InputEngine.h"
#include "GameData/InputData.h"
#include "DirectX/DirectInput.h"

#define MOUSE_SENSITIVITY  0.2

void InputEngine::Initialize(HINSTANCE hInstance, HWND hWnd)
{
	directinput.Init (hInstance , hWnd);
}

void InputEngine::Update (InputData & inputdata)
{
	static BYTE Keys[256];
	static DIMOUSESTATE Mouse;

	directinput.GetKeys(&Keys[0]);
	directinput.GetMouse(&Mouse);

	//ZeroMemory(&inputdata, sizeof(InputData));
	inputdata.Reset();

	if(Keys[DIK_LEFT] || Keys[DIK_A])
		inputdata.AccelerateLeft = true;
	if(Keys[DIK_RIGHT] || Keys[DIK_D])
		inputdata.AccelerateRight = true;

	if (Mouse.lX)
		inputdata.MoveHorizontal = Mouse.lX * MOUSE_SENSITIVITY;
}

void InputEngine::Close ()
{
	directinput.Close ();
}