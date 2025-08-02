#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#define DEFAULT_SCREEN_WIDTH	1024
#define DEFAULT_SCREEN_HEIGHT	768

class GameWindow
{
public:
	HWND	hWnd;
	int		Width;
	int		Height;
	bool	Windowed;

	// constructor
	GameWindow ()
		: hWnd (0),
		Width (DEFAULT_SCREEN_WIDTH),
		Height (DEFAULT_SCREEN_HEIGHT),
		Windowed (true)
	{}
	// Create the game window
	void Create (HINSTANCE hInstance , int nCmdShow);
};
#endif