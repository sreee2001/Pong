#ifndef RENDERENGINE_H
#define RENDERENGINE_H

#include "DirectX/Direct3D.h"
#include "DirectX/Sprite.h"

class GameWindow;
class GameData;

class RenderEngine
{
public:
	void Initialize ( GameWindow & gw );
	void Close ();

	void Render ( GameData & gamedata );
	void LoadGraphics ();
private:
	Direct3D	direct3d;
	Sprite		graphics;
};

#endif