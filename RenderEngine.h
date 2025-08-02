#ifndef RENDERENGINE_H
#define RENDERENGINE_H

#include "ObjectData.h"
#include "Direct3D.h"

class GameWindow;

class RenderEngine
{
public:
	void Initialize ( GameWindow & gw );
	void Close ();

	void Render ( ObjectData gameObjectData [] );
	void LoadGraphics ();
private:
	Direct3D	direct3d;
	Sprite		graphics;
};

#endif