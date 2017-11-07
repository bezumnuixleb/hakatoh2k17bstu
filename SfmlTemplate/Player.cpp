#include "Player.h"


void Player::keymove(const Event &ev)
{

}

void Player::control()
{
	
	if (Keyboard::isKeyPressed(Keyboard::Space))  return; else	state = stay;
	if (Keyboard::isKeyPressed(Keyboard::Left)) { speed = 0.4;  state = left; ismove = true; }
	if (Keyboard::isKeyPressed(Keyboard::Right)) { speed = 0.4; state = right; ismove = true;}
	if (Keyboard::isKeyPressed(Keyboard::Up) && onground == true)
	{ dy = -0.8; onground = false;  state = jump; }
	if (Keyboard::isKeyPressed(Keyboard::Down)) {
		state = down;
		speed = 0;
	}

}

void Player::update(const float &t,
	vector<Platform>&plat, 
	vector<Platform>&dmg
	,vector<Enemy>&mobs
	,vector<Enemy>&shots
)
{

	bool stoyatx=false;
	control();
	switch (state)
	{
	case right: dx = speed; break;
	case left: dx = -speed; break;
	case up: break;
	case down: break;
	case jump: break;
	case stay: {
		stoyatx = true;
	} break;
	}
	if (alife == false) {
		data.posintexture = { 0,640,80,80 };
		data.sprite.setTextureRect(data.posintexture);
	}
	else {
		animpos += t;
		if (animpos > 200)animpos = 0;
		
		if (dx > 0) {
			data.posintexture = { (int)(animpos/100)*56+540,560,56,80 };
			if (onground == false)data.posintexture.left = 708;
		}
		if (dx < 0) {
			data.posintexture = { (int)(animpos/100)*56 + 540,480,56,80 };
			if (onground==false)data.posintexture.left = 708;
		}
		if (stoyatx == false) {
			x += dx*t;
			checkCollisionWithMap(dx, 0, plat);
		}
		if (state == stay) {
			data.posintexture = { 540,400,80,80 };
		}
		
		y += dy*t;
		checkCollisionWithMap(0, dy, plat);

		checkCollisionWithDeath(dmg);
		checkCollisionWithMobs(mobs);
		checkCollisionWithMobs(shots);
		if (!ismove) speed = 0;
		data.sprite.setPosition(x, y);
		data.sprite.setTextureRect(data.posintexture);
		//
		dy = dy + 0.0015*t;

	}
}

void  Player::checkCollisionWithMobs(vector<Enemy>&dmg) {
	FloatRect temp = { x,y,56,80 };
	FloatRect mobrect;
	for (int i = 0; i < dmg.size(); i++)
	{
		mobrect = { dmg[i].core.x,dmg[i].core.y,dmg[i].core.w,dmg[i].core.h };
		if (mobrect.intersects(temp)) {
			if (dmg[i].core.alife == true) {
			alife = false;
		}
		}
	}
}

void  Player::checkCollisionWithMap(float Dx, float Dy, vector<Platform>&plat) {
	FloatRect temp = { x,y,56,80 };
	for (int i = 0; i < plat.size(); i++)
	{
		if (plat[i].pos.intersects(temp)) {
			if (Dy > 0)
			{
				y = plat[i].pos.top - h;  dy = 0;  onground = true;
			}
			if (Dy < 0) { y = plat[i].pos.top + plat[i].pos.height;   dy = 0; }
			if (Dx > 0) { x = plat[i].pos.left - w; }
			if (Dx < 0) { x = plat[i].pos.left + plat[i].pos.width; }
		}
	}


}


void  Player::checkCollisionWithDeath(vector<Platform>&dmg) {
	FloatRect temp = { x,y,56,80 };

	for (int i = 0; i < dmg.size(); i++)
	{
			if (dmg[i].pos.intersects(temp)) {
				alife = false;
			}
		}
	}


/*
void Player::move( FloatRect col) {
	float horiz=0, vertic=0;
	Vector2f LT = { data.posinworld.left,data.posinworld.top },
		RT{ data.posinworld.left + data.posinworld.width,data.posinworld.top },
		LB{ data.posinworld.left,data.posinworld.top + data.posinworld.height },
		RB{ data.posinworld.left + data.posinworld.width,data.posinworld.top + data.posinworld.height};

	bool ec = true;
	//два нижних угла вошли в блок
	if (ec&&col.contains(LB)&&col.contains(RB)) {
		ec = false;
		vertic = col.top - LB.y;
	}
	//два верхних угла вошли в блок
	if (ec&&col.contains(LT) && col.contains(RT)) {
		ec = false;
		vertic = col.top+col.height - LT.y;

	}
	//два левых угла вошли в блок
	if (ec&&col.contains(LT)&&col.contains(LB)) {
		ec = false;
		horiz = col.left + col.width - LT.x;

	}
	//два правых угла вошли в блок
	if (ec&&col.contains(RT) && col.contains(RB)) {
		ec = false;
		horiz = col.left - RT.x;

	}
	//только левый верхний
	if (ec&&col.contains(LT)) {
		ec = false;
		vertic = col.top + col.height - LT.y;
		horiz = col.left + col.width - LT.x;

	}
	//только правый верхний
	if (ec&&col.contains(LT)) {
		ec = false;
		vertic = col.top + col.height - LT.y;
		horiz = col.left - RT.x;

	}
	//только левый нижний
	if (ec&&col.contains(LT)) {
		ec = false;
		vertic = col.top - LB.y;
		horiz = col.left + col.width - LT.x;

	}
	//только правый нижний
	if (ec&&col.contains(LT)) {
		ec = false;
		vertic = col.top - LB.y;
		horiz = col.left - RT.x;

	}

	data.posinworld.left += horiz;
	data.posinworld.top += vertic;

}
*/

int Player::getStat()
{
	switch (state)
	{
	case right: return 1; break;
	case left:return 0; break;
	case up:return 5; break;
	case down:return 4; break;
	case jump:return 2; break;
	case stay:return 3; break;
	}
}

void Player::setStat(int s)
{
	switch (s)
	{
	case 1: state = right; break;
	case 0:state=left; break;
	case 2:state = jump; break;
	case 3: state = stay; break;
	case 4:state = down; break;
	case 5:state = up; break;
	}
}
void Player::stop()
{
	state = stay;
}

Player::~Player()
{
}
