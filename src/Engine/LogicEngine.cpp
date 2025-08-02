#include <windows.h>

#include "Engine/LogicEngine.h"

#include "GameData/GameData.h"
#include "GameData/InputData.h"
#include "Windows/gameWindow.h"

#define AI_ACCELERATE_MOMENTUM	0.001f;
#define AI_BRAKE_MOMENTUM		0.002f;

bool LogicEngine::Update (GameData & gameData , InputData & inputData, GameWindow & gw)
{
	static int time, start_time = GetTickCount();

	time = GetTickCount() - start_time;
	start_time = GetTickCount();

	ObjectData & objBall		= gameData.gameObjData[Ball];
	ObjectData & objPlayer		= gameData.gameObjData[Player];
	ObjectData & objComputer	= gameData.gameObjData[Computer];

	for(int ms = 0; ms < time; ms++)    // once per millisecond...
	{
		if (inputData.MoveHorizontal)
		{
			objPlayer.x += inputData.MoveHorizontal;
			objPlayer.xmomentum = 10 * inputData.MoveHorizontal / time;

			if (objPlayer.x < 0)
				objPlayer.x = 0;
			if (objPlayer.x > gw.Width - objPlayer.w)
				objPlayer.x = gw.Width - objPlayer.w;
		}

		// Using a simple AI logic, calculate Player 2's change in momentum
		if(objComputer.x + (objComputer.w / 2) > objBall.x)
		{
			if(objComputer.xmomentum > 0.0f)
				objComputer.xmomentum -= AI_BRAKE_MOMENTUM;
			if(objComputer.xmomentum <= 0.0f)
				objComputer.xmomentum -= AI_ACCELERATE_MOMENTUM;
		}
		if(objComputer.x + (objComputer.w / 2) < objBall.x)
		{
			if(objComputer.xmomentum < 0.0f)
				objComputer.xmomentum += AI_BRAKE_MOMENTUM;
			if(objComputer.xmomentum >= 0.0f)
				objComputer.xmomentum += AI_ACCELERATE_MOMENTUM;
		}

		// Move the two players based on their new momentum
		//objPlayer.x += objPlayer.xmomentum;
		objComputer.x += objComputer.xmomentum;

		// Detect player collision with the walls, and change the player momentum
		if(objPlayer.x < 0)
		{
			objPlayer.x = 0;
			objPlayer.xmomentum = -objPlayer.xmomentum / 2;
		}
		if(objPlayer.x + objPlayer.w > gw.Width)
		{
			objPlayer.x = gw.Width - objPlayer.w;
			objPlayer.xmomentum = -objPlayer.xmomentum / 2;
		}
		if(objComputer.x < 0)
		{
			objComputer.x = 0;
			objComputer.xmomentum = -objComputer.xmomentum / 2;
		}
		if(objComputer.x + objComputer.w > gw.Width)
		{
			objComputer.x = gw.Width - objComputer.w;
			objComputer.xmomentum = -objComputer.xmomentum / 2;
		}

		// Move the ball based on its current momentum
		objBall.x += objBall.xmomentum;
		objBall.y += objBall.ymomentum;

		// Detect if the ball has collided with Player 1
		if(objBall.y + objBall.h > objPlayer.y &&
			objBall.x + objBall.w > objPlayer.x &&
			objBall.x < objPlayer.x + objPlayer.w)
		{
			objBall.ymomentum = -objBall.ymomentum;
			objBall.xmomentum += objPlayer.xmomentum / 2;

			// change the player paddle on each impact
			++objPlayer.frameIndex;
			objPlayer.frameIndex %= 4;
		}

		// Detect if the ball has collided with Player 2
		if(objBall.y < objComputer.y + objComputer.h &&
			objBall.x + objBall.w > objComputer.x &&
			objBall.x < objComputer.x + objComputer.w)
		{
			objBall.ymomentum = -objBall.ymomentum;
			objBall.xmomentum += objComputer.xmomentum / 2;
		}

		// Detect if the ball has collided with either wall
		if(objBall.x < 0)
			objBall.xmomentum = -objBall.xmomentum;
		if(objBall.x + objBall.w > gw.Width)
			objBall.xmomentum = -objBall.xmomentum;

		// cap the xomentum of the ball
		if (objBall.xmomentum < - 0.8f)
			objBall.xmomentum = - 0.8f;
		if (objBall.xmomentum > 0.8f)
			objBall.xmomentum = 0.8f;

		// Detect victory or defeat and process
		if(objBall.y < 0 || objBall.y /*+ objBall.h*/ > gw.Height)
			//InitGame(go); 
			return false;
	}
	return true;
}