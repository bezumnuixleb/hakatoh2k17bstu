#pragma once
#include "Menu.h"

class GamaState
{
public:
	//player info
	float PlayerX,PlayerY;
	float PlayerAnimpos;
	bool PlayerAlife, PlayerIsmove, PlayerOnground;
	float PlayerSpeed, PlayerDx, PlayerDy;
	int PlayerState;
	IntRect PlayerPosintext;
	//float PlayerRemainTime;
	float BossStage;

	float SavedTime;

	sf::Time musicpos;

	vector<Enemy> SavedMobs;
	vector<Enemy> SavedShots;
	GamaState(Player*,const vector<Enemy>&mobs,const vector<Enemy>&shots,float time,float bosstage,Time musicpos);
	void returnPlayer(Player*,float*,float*, Time*);
	void returnMobs(vector<Enemy>&mobs, vector<Enemy>&shots);
	~GamaState();
};

