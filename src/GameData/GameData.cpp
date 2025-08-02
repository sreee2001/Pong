#include <windows.h>
#include "GameData/GameData.h"
#include "Windows/GameWindow.h"

#define BALL_WIDTH		16
#define BALL_HEIGHT		16
#define PADDLE_WIDTH	85
#define PADDLE_HEIGHT	16

void GameData::InitData (GameWindow & gw)
{
	// Initialize Ball
	gameObjData[Ball].frameIndex = 4;
	gameObjData[Ball].w = BALL_WIDTH;
	gameObjData[Ball].h = BALL_HEIGHT;
	gameObjData[Ball].x = gw.Width / 2;
	gameObjData[Ball].y = gw.Height/ 2;
	gameObjData[Ball].xmomentum = 0.01f;
	gameObjData[Ball].ymomentum = -0.3f;

	// Initialize Player 1
	gameObjData[Player].frameIndex = 0;
	gameObjData[Player].w = PADDLE_WIDTH;
	gameObjData[Player].h = PADDLE_HEIGHT;
	gameObjData[Player].x = (gw.Width - gameObjData[Player].w) / 2;
	gameObjData[Player].y = gw.Height - gameObjData[Player].h;
	gameObjData[Player].xmomentum = 0.0f;

	// Initialize Player 2
	gameObjData[Computer].frameIndex = 3;
	gameObjData[Computer].w = PADDLE_WIDTH;
	gameObjData[Computer].h = PADDLE_HEIGHT;
	gameObjData[Computer].x = (gw.Width - gameObjData[Computer].w) / 2;
	gameObjData[Computer].y = 0.0f;
	gameObjData[Computer].xmomentum = 0.0f;
}