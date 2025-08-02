#include <windows.h>

#include "Engine/RenderEngine.h"

#include "Windows/GameWindow.h"
#include "GameData/GameData.h"

void RenderEngine::Initialize ( GameWindow & gw )
{
	direct3d.Initialize (gw);
}
void RenderEngine::Close ()
{
	direct3d.Close();
}

void RenderEngine::Render ( GameData & gameData )
{
	direct3d.StartRender();

	direct3d.DrawSprite(graphics, gameData.gameObjData[0].frameIndex, gameData.gameObjData[0].x, gameData.gameObjData[0].y, 0);
	direct3d.DrawSprite(graphics, gameData.gameObjData[1].frameIndex, gameData.gameObjData[1].x, gameData.gameObjData[1].y, 0);
	direct3d.DrawSprite(graphics, gameData.gameObjData[2].frameIndex, gameData.gameObjData[2].x, gameData.gameObjData[2].y, 0);

	direct3d.EndRender();
}
void RenderEngine::LoadGraphics ()
{
	direct3d.LoadSprite(graphics, TEXT("Resources/Graphics.bmp"), 85, 16, 1, 5);
}