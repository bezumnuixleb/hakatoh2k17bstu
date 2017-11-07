#pragma once
#include "Enemy.h"


class Player :
	public Defalt
{
public:
	enum stateObject { left, right, jump, stay, down, up };

	stateObject state;
	bool alife,ismove,onground;
	float speed,w,h,dx,dy,x,y;
	float remainTime;
	float animpos;

	Player() {}
	void keymove(const Event&);
	void control();
	void update(const float &,
		vector<Platform>&,
		vector<Platform>&
		,vector<Enemy>&mobs
		, vector<Enemy>&shots 
	);
	void checkCollisionWithMap(float Dx, float Dy, vector<Platform>&);
	void  checkCollisionWithDeath(vector<Platform>&dmg);
	void  checkCollisionWithMobs(vector<Enemy>&mobs);
	FloatRect getPos() {
		FloatRect tmp;
		tmp = data.posinworld;
		return tmp;
	}
	//void move(FloatRect col);
	void set(Texture *textura,float newx, float newy)
	{
		data.sprite.setTexture(*textura);
		data.posintexture = { 540,400,80,80 };
		data.posinworld = { newx,newy,80,80 };
		data.sprite.setPosition(data.posinworld.left, data.posinworld.top);
		data.sprite.setTextureRect(data.posintexture);
		
		remainTime = 10000;
		speed = 0;  dx = 0; dy = 0;
		alife = true; ismove = false; onground = false;
		w = 56; h = 80;
		data.sprite.setTexture(*textura);

		x = newx; y = newy;
		data.sprite.setTextureRect(data.posintexture);
		onground = false;
		state = jump;
		alife = true;
		animpos = 0;
		ismove = true;
	}
	int getStat();
	void setStat(int);
	void stop();
	~Player();
};


