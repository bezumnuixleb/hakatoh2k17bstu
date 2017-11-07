#include "Enemy.h"



Enemy::Enemy(Texture*maintext, int Type, float X, float Y, int W, int H)
{
	
		core.x = X; core.y = Y; core.w = W; core.h = H; core.type = Type; core.moveTimer = 0;
		core.speed = 0; core.dx = 0; core.dy = 0; core.shottimer = 0;
		core.alife = true; core.onground = false; core.ismove = false;
		sprite.setTexture(*maintext);
		core.anim = 0;
		switch (Type)
		{
		case 0: {//p4ela
			//800(80x80)<---2 kadra
			//880(80x80)--->2 kadra
			core.posintexture = { 0,800,80,80 };
			core.dx = 0.1;

		}break;
		case 1: {//bird 
			//960(27x23) 4 kadra
			core.posintexture = { 0,960,27,23 };
			core.dy = -0.1;
		}break;
		case 2: {//cannon
			//1040(80x80)
			//cannon ball 1120(12x12)
			core.posintexture = { 0,1040,80,80 };

		}break;
		case 3: {//turret
			//1140(80x80)
			//shot 1240(20x20)
			core.posintexture = { 0,1140,80,80 };


		}break;
		//for boss :(
		//
		case 10: {
			//2000(95x95)
			//
			core.posintexture = { 0,2000,95,95 };
			core.dy = 0.4;
			core.dx = 2.0;

		}break;
		default:
			break;
		}
		sprite.setTextureRect(core.posintexture);

}
Enemy::Enemy(Sprite & spritenew, int Type, float X, float Y, int W, int H, float speed, float Px, float Py)
{
	core.deleteshottimer = 10000;
	core.x = X; core.y = Y; core.w = W; core.h = H; core.type = Type; core.moveTimer = 0;
	core.speed = 0; core.dx = 0; core.dy = 0;core.shottimer = 0;
	core.alife = true; core.onground = false; core.ismove = false;
	sprite.setTexture(*spritenew.getTexture());
	core.anim = 0;
	switch (Type)
	{
	case 21: {//jalo
		if (speed > 0) {
			core.posintexture = { 0,1600,20,20 };
		}
		else
		{
			core.posintexture = {20,1600,20,20 };
		}
		core.dx = speed;

	}break;
	case 22: {//cannon ball
		//1120(12x12)1320(26x40)
		core.posintexture = { 90,1320,26,40 };
		core.dy = speed;
	}break;
	case 23: {//laser
		//1240(20x20)
		core.posintexture = { 0,1240,20,20 };
		speed = 0.5;
		core.px = Px;
		core.py = Py;
		float distance = sqrt((core.px - core.x)*(core.px - core.x) + (core.py - core.y)*(core.py - core.y));//считаем дистанцию (длину от точки ј до точки Ѕ). формула длины вектора
		if (distance > 2) {

			core.dx=0.5*(core.px - core.x) / distance;//идем по иксу с помощью вектора нормали
			core.dy = 0.5*(core.py - core.y) / distance;//идем по игреку так же

		}
		else
		{
			core.alife = false;
		}
		


	}break;
	case 24: {//autotarget
		//1400(75x50)
		core.posintexture = { 0,1400,50,75 };
		
		core.px = Px;
		core.py = Py;

		float distance = sqrt((core.px - core.x)*(core.px - core.x) + (core.py - core.y)*(core.py - core.y));//считаем дистанцию (длину от точки ј до точки Ѕ). формула длины вектора
		if (distance > 2) {

			core.dx = 0.5*(core.px - core.x) / distance;//идем по иксу с помощью вектора нормали
			core.dy = 0.5*(core.py - core.y) / distance;//идем по игреку так же

		}
		else
		{
			core.alife = false;
		}
	}break;
	case 25: {//triple shot
		//speed = number
		//1320(26x40)
		if (speed == 1) {
			core.px = Px + 640;
			core.py =0;

			float distance = sqrt((core.px - core.x)*(core.px - core.x) + (core.py - core.y)*(core.py - core.y));//считаем дистанцию (длину от точки ј до точки Ѕ). формула длины вектора
			if (distance > 2) {

				core.dx = 0.5*(core.px - core.x) / distance;//идем по иксу с помощью вектора нормали
				core.dy = 0.5*(core.py - core.y) / distance;//идем по игреку так же

			}
			else
			{
				core.alife = false;
			}
		}if (speed ==2) {
			core.px = Px+640;
			core.py = 360;

			float distance = sqrt((core.px - core.x)*(core.px - core.x) + (core.py - core.y)*(core.py - core.y));//считаем дистанцию (длину от точки ј до точки Ѕ). формула длины вектора
			if (distance > 2) {

				core.dx = 0.5*(core.px - core.x) / distance;//идем по иксу с помощью вектора нормали
				core.dy = 0.5*(core.py - core.y) / distance;//идем по игреку так же

			}
			else
			{
				core.alife = false;
			}
		}
		if (speed == 3) {
			core.px = Px + 640;
			core.py =720;

			float distance = sqrt((core.px - core.x)*(core.px - core.x) + (core.py - core.y)*(core.py - core.y));//считаем дистанцию (длину от точки ј до точки Ѕ). формула длины вектора
			if (distance > 2) {

				core.dx = 0.5*(core.px - core.x) / distance;//идем по иксу с помощью вектора нормали
				core.dy = 0.5*(core.py - core.y) / distance;//идем по игреку так же

			}
			else
			{
				core.alife = false;
			}
		}

	}break;
	default:
		break;
	}
}
Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void  Enemy::CollisionforEnemys(int type,float Dx, float Dy, vector<Platform>&plat) {
	FloatRect temp = { core.x,core.y,core.w,core.w };
	
		for (int i = 0; i < plat.size(); i++)
		{
			if (plat[i].pos.intersects(temp)) {
				if (type == 0) {//p4ela
					
					if (Dx > 0) {
						core.x = plat[i].pos.left - core.w; core.dx *= -1; core.moveTimer = 0;
					}
					if (Dx < 0) {
						core.x = plat[i].pos.left + plat[i].pos.width; core.dx *= -1; core.moveTimer = 0;
					}
				}
				if (type == 1) {//bird
					if (Dy > 0)
					{
						
						//cout << "LEJAT" << endl;
						//core.y-= 10;
					}
					if (Dy < 0) {

						//cout << "SOSAT"<<endl;
						core.y = plat[i].pos.top + plat[i].pos.height + 1;
					}
					core.dy *= -1;
				}
				if (type == 21) {
					if (Dy > 0)
					{
						core.alife = false; core.dx = 0;
					}
					if (Dy < 0) { core.alife = false; core.dx = 0; }
					if (Dx > 0) {
						core.alife = false; core.dx = 0;
					}
					if (Dx < 0) {
						core.alife = false; core.dx = 0;
					}
				}
				if (type == 22) {
					core.alife = false; core.speed = 0;
				}
				if (type == 23) {
					core.alife = false; core.speed = 0;
				}
				if (type == 24) {
					core.alife = false; core.speed = 0;
				}
				if (type == 25) {
					core.alife = false; core.speed = 0;
				}
			}
		}
	

}
void Enemy::updateMobs(float px, float py, float time, vector<Platform>&plat,vector<Enemy>&shots)
{
	if (core.type == 0) {//p4ela
		//core.moveTimer += time; if (core.moveTimer>3000) { core.dx *= -1; core.moveTimer = 0; }
		core.shottimer += time;
		CollisionforEnemys(core.type,core.dx, 0, plat);
		core.x += core.dx*time;
		sprite.setPosition(core.x, core.y); 
		core.anim += time;
		if (core.anim > 200)core.anim = 0;
		if (core.shottimer > 2000) {
			if (core.dx > 0) {
				core.shottimer = 0;
				Enemy tmpmob(sprite, 21, core.x+30, core.y+30, 20, 20, 0.4,px,py);
				if (shots.size() < 100) {
					shots.push_back(tmpmob);
				}
				else
				{
					shots.erase(shots.begin());
					shots.push_back(tmpmob);
				}
			}
			else {
				core.shottimer = 0;
				Enemy tmpmob(sprite, 21, core.x + 40, core.y + 30, 20, 20, -0.4,px,py);
				if (shots.size() < 100) {
					shots.push_back(tmpmob);
				}
				else
				{
					shots.erase(shots.begin());
					shots.push_back(tmpmob);
				}
			}
		}
		if (core.dx > 0) {
			
			core.posintexture = { (int)(core.anim / 100) * 80,880,80,80 };
			sprite.setTextureRect(core.posintexture);
		}
		else
		{
			
			core.posintexture = { (int)(core.anim / 100)*80,800,80,80 };
			sprite.setTextureRect(core.posintexture);
		}

	}
	if (core.type == 1) {//bird
		
		core.anim += time;
		if (core.anim > 300)core.anim = 0;
		core.y += core.dy*time;
		CollisionforEnemys(core.type, 0, core.dy, plat);
		
		core.posintexture = { (int)(core.anim/100)*27,960,27,23 };
		sprite.setPosition(core.x, core.y);
		sprite.setTextureRect(core.posintexture);
		//cout << "bird poss" << core.y << "spped" << core.dy << endl;
	}
	if (core.type == 2) {//cannon
		sprite.setPosition(core.x, core.y);
		core.shottimer += time;
		if (core.shottimer > 2000) {
			core.posintexture = { 0,1040,80,80 };
			sprite.setTextureRect(core.posintexture);
		}
		if (core.shottimer > 3000) {
			
				core.shottimer = 0;

				Enemy tmpmob(sprite, 22, core.x + 30, core.y +10, 25,40, -0.4,px,py);

				if (shots.size() < 100) {
					shots.push_back(tmpmob);
				}
				else
				{
					shots.erase(shots.begin());
					shots.push_back(tmpmob);
				}
				core.posintexture = { 80,1040,80,80 };
				sprite.setTextureRect(core.posintexture);
		}

	}
	if (core.type == 3) {//jopa
		sprite.setPosition(core.x, core.y);
		if(float distance = sqrt((px - core.x)*(px - core.x) + (py - core.y)*(py - core.y))<800)
		core.shottimer += time;
		if (core.shottimer > 2000) {//1140(80x80)
			core.posintexture = { 80,1140,80,80 };
			sprite.setTextureRect(core.posintexture);
		}
		if (core.shottimer > 3000) {

			core.shottimer = 0;

			Enemy tmpmob(sprite, 23, core.x, core.y, 20, 20, 0,px,py);

			if (shots.size() < 100) {
				shots.push_back(tmpmob);
			}
			else
			{
				shots.erase(shots.begin());
				shots.push_back(tmpmob);
			}
			core.posintexture = { 0,1140,80,80 };
			sprite.setTextureRect(core.posintexture);

		}

	}

}
void Enemy::updateBoss(float px, float py, float time, float *stage, vector<Enemy>&shots) {
	if (core.type == 10) {//bosssssssssssssssss
		
		
		*stage += time;
		core.anim += time;
		if (core.anim > 600)
			core.anim = 0;
		core.posintexture = { (int)(core.anim / 200) * 95,2000,95,95 };
		sprite.setTextureRect(core.posintexture);
		if (*stage < 5000) {
			core.shottimer += time;
			
			if (core.shottimer > 750) {
				//
				core.shottimer = 0;
				//autotarget shot
				Enemy tmpmob(sprite, 24, core.x, core.y, 75, 50, 0, px, py);
					if (shots.size() < 100) {
					shots.push_back(tmpmob);
				}
				else
				{
					shots.erase(shots.begin());
					shots.push_back(tmpmob);
				}
			}
			
			if (core.y > 625) { if (core.dy > 0)core.dy *= -1; }
			if (core.y < 0) { if (core.dy < 0)core.dy *= -1; }
			core.y += core.dy* time;
			core.x = px - 500 + core.dx*time;
			sprite.setPosition(core.x, core.y);
			return;
		}
		if (*stage < 10000) {
			core.x = px - 500 + core.dx*time;
			if (core.y > 400) {}
			if (core.y < 400) {
				if (core.dy < 0)core.dy *= -1; core.y += core.dy* time;
			}

			sprite.setPosition(core.x, core.y);

			core.shottimer += time;
			if (core.shottimer > 750) {
			//
			core.shottimer = 0;
			//triple shot
			Enemy tmpmob(sprite, 25, core.x, core.y, 26, 40,1, px, py);
			if (shots.size() < 100) {
			shots.push_back(tmpmob);
			}
			else
			{
			shots.erase(shots.begin());
			shots.push_back(tmpmob);
			}
			Enemy tmpmob1(sprite, 25, core.x, core.y, 26, 40, 2, px, py);
			if (shots.size() < 100) {
				shots.push_back(tmpmob1);
			}
			else
			{
				shots.erase(shots.begin());
				shots.push_back(tmpmob1);
			}
			Enemy tmpmob2(sprite, 25, core.x, core.y,26, 40,3, px, py);
			if (shots.size() < 100) {
				shots.push_back(tmpmob2);
			}
			else
			{
				shots.erase(shots.begin());
				shots.push_back(tmpmob2);
			}
			}
			return;
		}
		if (*stage < 15000) {

			core.shottimer += time;

			if (core.shottimer > 750) {
				//
				core.shottimer = 0;
				//autotarget shot
				Enemy tmpmob(sprite, 24, core.x, core.y, 75, 50, 0, px, py);
				if (shots.size() < 100) {
					shots.push_back(tmpmob);
				}
				else
				{
					shots.erase(shots.begin());
					shots.push_back(tmpmob);
				}
			}
			if (core.y >625) { if (core.dy > 0)core.dy *= -1; }
			if (core.y < 0) { if (core.dy < 0)core.dy *= -1; }
			core.y += core.dy* time;
			core.x = px - 500 + core.dx*time;
			sprite.setPosition(core.x, core.y);
			return;
		}
		if (*stage < 17000) {
			core.x = px - 500 + core.dx*time;
			if (core.y > 500) {}
			if (core.y < 500) {
				if (core.dy < 0)core.dy *= -1; core.y += core.dy* time;
			}

			
			core.x = core.x + core.dx*time;
			sprite.setPosition(core.x, core.y);
			return;
		}
		if (*stage < 20000) {
			
			core.x = core.x + core.dx*time;
			sprite.setPosition(core.x, core.y);
			return;
		}
		if (*stage < 20003) {
			core.x = px + 720;
			return;
		}if (*stage < 22000) {
			core.x = core.x - 2*core.dx*time;
			sprite.setPosition(core.x, core.y);
			return;
		}
		if (*stage < 24000) {
			int tmp = 1;
			if (px - 500 > core.x)tmp = 0;
			core.x = core.x + core.dx*time*tmp;
			sprite.setPosition(core.x, core.y);
			return;
		}
		if (*stage<25000)
		{
			core.shottimer += time;

			if (core.shottimer > 750) {
				//
				core.shottimer = 0;
				//autotarget shot
				Enemy tmpmob(sprite, 24, core.x, core.y, 75, 50, 0, px, py);
				if (shots.size() < 100) {
					shots.push_back(tmpmob);
				}
				else
				{
					shots.erase(shots.begin());
					shots.push_back(tmpmob);
				}
			}

			if (core.y > 625) { if (core.dy > 0)core.dy *= -1; }
			if (core.y < 0) { if (core.dy < 0)core.dy *= -1; }
			core.y += core.dy* time;
			core.x = px - 500 + core.dx*time;
			sprite.setPosition(core.x, core.y);
			return;
		}
		if (*stage >= 25000)*stage = 0;
	}
}

		




void Enemy::updateShots(float px, float py, float time, vector<Platform>&plat)
{
	core.deleteshottimer -= time;
	if (core.type == 21) {//shots
		core.moveTimer += time; if (core.moveTimer>4000){ core.alife = false; core.dx = 0; }
		CollisionforEnemys(core.type, core.dx, 0, plat);
		core.x += core.dx*time; if (core.dx > 0) {
			sprite.setTextureRect(core.posintexture);
		}
		else
		{
			sprite.setTextureRect(core.posintexture);
		}
		sprite.setPosition(core.x, core.y);
		
	}
	if (core.type == 22) {
		core.moveTimer += time; if (core.moveTimer>4000) { core.alife = false; core.dx = 0; }

		CollisionforEnemys(core.type, 0, core.dy, plat);
		core.y += core.dy*time;
		sprite.setPosition(core.x, core.y);
		
		sprite.setTextureRect(core.posintexture);
	}
	if (core.type == 23) {
		//core.px = px; core.py = py;
		core.y += core.dy*time;
		core.x += core.dx*time;
		CollisionforEnemys(core.type, 0, 0, plat);
		sprite.setPosition(core.x, core.y);
		sprite.setTextureRect(core.posintexture);

	}
	if (core.type == 24) {
		core.y += core.dy*time;
		core.x += core.dx*time;
		core.anim += time;
		if (core.anim > 300)core.anim = 0;
		core.posintexture = { (int)(core.anim / 100) * 50,1400,50,75 };
		//CollisionforEnemys(core.type, 0, 0, plat);
		sprite.setPosition(core.x, core.y);
		sprite.setTextureRect(core.posintexture);
	}
	if (core.type == 25) {
		core.y += core.dy*time;
		core.x += core.dx*time;
		//CollisionforEnemys(core.type, 0, 0, plat);
		core.anim += time;
		if (core.anim > 300)core.anim = 0;
		core.posintexture = { (int)(core.anim / 100) * 26,1320,26,40 };
		sprite.setPosition(core.x, core.y);
		sprite.setTextureRect(core.posintexture);
	}
}
const Sprite& Enemy::show() {
	
		return sprite;
	
}