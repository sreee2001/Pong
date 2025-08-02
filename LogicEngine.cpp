#include <windows.h>

#include "LogicEngine.h"

bool LogicEngine::Update (ObjectData go [], InputData * inputData, GameWindow & gw)
{
	static int time, start_time = GetTickCount();
	time = GetTickCount() - start_time;
	start_time = GetTickCount();

	for(int ms = 0; ms < time; ms++)    // once per millisecond...
	{
		// Take the input and calculate Player 1's change in momentum
		if(inputData->AccelerateLeft)
		{
			if(go[1].xmomentum > 0.0f)
				go[1].xmomentum -= 0.002f;
			if(go[1].xmomentum <= 0.0f)
				go[1].xmomentum -= 0.001f;
		}
		if(inputData->AccelerateRight)
		{
			if(go[1].xmomentum < 0.0f)
				go[1].xmomentum += 0.002f;
			if(go[1].xmomentum >= 0.0f)
				go[1].xmomentum += 0.001f;
		}
		if (inputData->MoveHorizontal)
		{
			go[1].x += inputData->MoveHorizontal;

			if (go[1].x < 0)
				go[1].x = 0;
			if (go[1].x > gw.Width - go[1].w)
				go[1].x = gw.Width - go[1].w;
		}

		// Using a simple AI logic, calculate Player 2's change in momentum
		if(go[2].x + (go[2].w / 2) > go[0].x)
		{
			if(go[2].xmomentum > 0.0f)
				go[2].xmomentum -= 0.002f;
			if(go[2].xmomentum <= 0.0f)
				go[2].xmomentum -= 0.001f;
		}
		if(go[2].x + (go[2].w / 2) < go[0].x)
		{
			if(go[2].xmomentum < 0.0f)
				go[2].xmomentum += 0.002f;
			if(go[2].xmomentum >= 0.0f)
				go[2].xmomentum += 0.001f;
		}

		// Move the two players based on their new momentum
		go[1].x += go[1].xmomentum;
		go[2].x += go[2].xmomentum;

		// Detect player collision with the walls, and change the player momentum
		if(go[1].x < 0)
		{
			go[1].x = 0;
			go[1].xmomentum = -go[1].xmomentum / 2;
		}
		if(go[1].x + go[1].w > gw.Width)
		{
			go[1].x = gw.Width - go[1].w;
			go[1].xmomentum = -go[1].xmomentum / 2;
		}
		if(go[2].x < 0)
		{
			go[2].x = 0;
			go[2].xmomentum = -go[2].xmomentum / 2;
		}
		if(go[2].x + go[2].w > gw.Width)
		{
			go[2].x = gw.Width - go[2].w;
			go[2].xmomentum = -go[2].xmomentum / 2;
		}

		// Move the ball based on its current momentum
		go[0].x += go[0].xmomentum;
		go[0].y += go[0].ymomentum;

		// Detect if the ball has collided with Player 1
		if(go[0].y + go[0].h > go[1].y &&
			go[0].x + go[0].w > go[1].x &&
			go[0].x < go[1].x + go[1].w)
		{
			go[0].ymomentum = -go[0].ymomentum;
			go[0].xmomentum += go[1].xmomentum / 2;
		}

		// Detect if the ball has collided with Player 2
		if(go[0].y < go[2].y + go[2].h &&
			go[0].x + go[0].w > go[2].x &&
			go[0].x < go[2].x + go[2].w)
		{
			go[0].ymomentum = -go[0].ymomentum;
			go[0].xmomentum += go[2].xmomentum / 2;
		}

		// Detect if the ball has collided with either wall
		if(go[0].x < 0)
			go[0].xmomentum = -go[0].xmomentum;
		if(go[0].x + go[0].w > gw.Width)
			go[0].xmomentum = -go[0].xmomentum;

		// Detect victory or defeat and process
		if(go[0].y < 0 || go[0].y + go[0].h > 768)
			//InitGame(go); 
			return false;

	}
	return true;
}