#pragma once
#include "Platform.h"

struct tosaveEnemy {
	bool alife, ismove, onground;
	float speed, w, h, dx, dy, x, y;
	int moveTimer;
	float shottimer,deleteshottimer;
	int type;
	float anim;
	IntRect posintexture;
	float px, py;
};
class Enemy
{
public:
	


	Enemy();
	~Enemy();

	Sprite sprite;
	
	tosaveEnemy core;

	Enemy(Texture*maintext, int Type, float X, float Y, int W, int H);
	Enemy(Sprite& sprite, int Type, float X, float Y, int W, int H,float speed,float px,float py);
	const Sprite& show();
	void Enemy::updateBoss(float px, float py, float time,float *stage, vector<Enemy>&shots);
	void CollisionforEnemys(int type,float Dx, float Dy, vector<Platform>&);
	void updateMobs(float px,float py,float time, vector<Platform>&plat, vector<Enemy>&shots);
	void updateShots(float px, float py, float time, vector<Platform>&plat);
};

