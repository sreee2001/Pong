#include "DirectX/DirectInput.h"

DirectInput::DirectInput ()	: din (0), dinkeyboard (0), dinmouse (0) {}

// Create DirectInput and the Keyboard and Mouse Devices
void DirectInput::Init(HINSTANCE hInstance,	HWND hWnd)
{
    DirectInput8Create(hInstance,
                      DIRECTINPUT_VERSION,
                      IID_IDirectInput8,
                      (void**)&din,
                      NULL);

    din->CreateDevice(GUID_SysKeyboard, &dinkeyboard, NULL);
    din->CreateDevice(GUID_SysMouse, &dinmouse, NULL);

    dinkeyboard->SetDataFormat(&c_dfDIKeyboard);
    dinmouse->SetDataFormat(&c_dfDIMouse);

    dinkeyboard->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);
    dinmouse->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);

    dinmouse->Acquire();
}

// Get the Current Keyboard Status
void DirectInput::GetKeys(BYTE* KeyState)
{
    dinkeyboard->Acquire();

    dinkeyboard->GetDeviceState(256, (LPVOID)KeyState);

    for(int Index = 0; Index < 256; Index++)
        *(KeyState + Index) &= 0x80;
}

// Get the Latest Mouse Movements and Mouse Buttons
void DirectInput::GetMouse(DIMOUSESTATE* MouseState)
{
    dinmouse->Acquire();

    dinmouse->GetDeviceState(sizeof(DIMOUSESTATE), (LPVOID)MouseState);

    MouseState->rgbButtons[0] &= 0x80;
    MouseState->rgbButtons[1] &= 0x80;
    MouseState->rgbButtons[2] &= 0x80;
    MouseState->rgbButtons[3] &= 0x80;
}

// Close the Devices and DirectInput
void DirectInput::Close(void)
{
    dinkeyboard->Unacquire();
    dinmouse->Unacquire();
    din->Release(); 
}