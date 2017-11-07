#pragma once
#include "Defalt.h"
class Tile :
	public Defalt
{

public:
	int type;
	Tile(int t, string s, float x, float y, float w, float h) : Defalt(s, x, y, w, h) {
		
	}
	Tile(int t,int lvln,Texture *block,float x,float y,float w,float h) {
		
		data.posinworld.left = x;
		data.posinworld.top = y;
		data.posinworld.width = w;
		data.posinworld.height= h;
		data.posintexture.height = 80;
		data.posintexture.width = 80;
		data.posintexture.top = lvln*80;
		data.posintexture.left = 0;
		data.sprite.setTexture(*block);
		data.sprite.setPosition(data.posinworld.left, data.posinworld.top);
		data.sprite.setTextureRect(data.posintexture);
		type = t;
		switch (t)
		{
		case 2: {//air
			data.posintexture.left = 80;
			data.sprite.setTextureRect(data.posintexture);
		}break;
		case 1: {//grass
			data.posintexture.left = 0;
			data.sprite.setTextureRect(data.posintexture);
		}break;
		case 4: {//ground
			data.posintexture.left = 240;
			data.sprite.setTextureRect(data.posintexture);
		}break;
		case 5: {//lava
			data.posintexture.left = 320;
			data.sprite.setTextureRect(data.posintexture);
		}break;
		case 6: {//shipi sverhy
			data.posintexture.left = 400;
			data.sprite.setTextureRect(data.posintexture);
		}break;
		case 3: {//shipi snizy
			data.posintexture.left = 160;
			data.sprite.setTextureRect(data.posintexture);
		}break;
		default: {
			data.posintexture.left = 80;
			data.sprite.setTextureRect(data.posintexture);
		}break;
		}
	}
	~Tile();
};

