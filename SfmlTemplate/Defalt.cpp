#include "Defalt.h"



Defalt::Defalt()
{

}

Defalt::Defalt(string s,float x,float y,float w,float h)
{
	
	data.texture.loadFromFile(s);
	data.sprite.setTexture(data.texture);
	data.posintexture = { 0,0,80,80 };
	data.posinworld = { x,y,w,h };
	data.sprite.setPosition(data.posinworld.left, data.posinworld.top);
	data.sprite.setTextureRect(data.posintexture);
}

const Sprite& Defalt::show()
{
	return data.sprite;
}


Defalt::~Defalt()
{
	
}
