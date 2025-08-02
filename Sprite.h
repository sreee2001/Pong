#ifndef SPRITE_H
#define SPRITE_H

class Sprite
{
public:
	int rows, cols;
	int width, height;
	LPDIRECT3DTEXTURE9 tex;
	Sprite () : rows(0) , cols(0) , width (0) , height (0) , tex (0) {}
};

#endif