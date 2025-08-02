#include <windows.h>

#include "RenderEngine.h"

#include "GameWindow.h"


void RenderEngine::Initialize ( GameWindow & gw )
{
	direct3d.Initialize (gw);
}
void RenderEngine::Close ()
{
	direct3d.Close();
}

void RenderEngine::Render ( ObjectData gameObjectData [] )
{
	direct3d.StartRender();

	direct3d.DrawSprite(graphics, gameObjectData[0].type, gameObjectData[0].x, gameObjectData[0].y, 0);
	direct3d.DrawSprite(graphics, gameObjectData[1].type, gameObjectData[1].x, gameObjectData[1].y, 0);
	direct3d.DrawSprite(graphics, gameObjectData[2].type, gameObjectData[2].x, gameObjectData[2].y, 0);

	direct3d.EndRender();
}
void RenderEngine::LoadGraphics ()
{
	direct3d.LoadSprite(graphics, TEXT("Graphics.bmp"), 85, 16, 1, 5);
}