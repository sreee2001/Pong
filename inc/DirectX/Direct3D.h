#ifndef DIRECT3D_H
#define DIRECT3D_H

#include <d3d9.h>
#include <d3dx9.h>

#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")

class GameWindow;
class Sprite;

class Direct3D
{
public:
	void Initialize (GameWindow & gw);
	void Close();
	void StartRender();
	void EndRender();
	void LoadSprite(Sprite & sprite, LPCTSTR File, int width, int height, int cols, int rows);
	void DrawSprite(Sprite & sprite, int Frame, float x, float y, float z);
private:
	LPDIRECT3D9				d3d;
	LPDIRECT3DDEVICE9		d3ddev;
	D3DPRESENT_PARAMETERS	d3dpp;
	LPD3DXSPRITE			d3dspt;
};

#endif