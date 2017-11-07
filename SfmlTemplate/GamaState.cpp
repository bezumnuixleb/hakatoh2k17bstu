#include "GamaState.h"






GamaState::GamaState(Player *pl, const vector<Enemy>& mobs, const vector<Enemy>& shots, float time,float bossstage,Time newmusicpos)
{
	/*
	float PlayerX,PlayerY;
	float PlayerAnimpos;
	bool PlayerAlife, PlayerIsmove, PlayerOnground;
	float PlayerSpeed, PlayerDx, PlayerDy;
	stateObject PlayerState;
	*/
	PlayerX = pl->x;PlayerY = pl->y;
	PlayerAnimpos = pl->animpos;
	PlayerAlife = pl->alife; PlayerIsmove = pl->ismove; PlayerOnground = pl->onground;
	PlayerSpeed = pl->speed; PlayerDx = pl->dx; PlayerDy = pl->dy;
	PlayerState = pl->getStat();
	PlayerPosintext = pl->data.posintexture;
	//PlayerRemainTime = pl->remainTime;
	SavedTime = time;
	BossStage = bossstage;

	SavedMobs.clear();
	SavedShots.clear();
	SavedMobs = mobs;
	SavedShots = shots;
	sf::Time musicpos = newmusicpos;
}

void GamaState::returnPlayer(Player *pl,float*time, float *bossstage,Time* timepos)
{
	 pl->x= PlayerX;pl->y= PlayerY;
	 pl->animpos = PlayerAnimpos;
	 pl->alife = PlayerAlife; pl->ismove = PlayerIsmove; pl->onground = PlayerOnground;
	 pl->speed = PlayerSpeed; pl->dx = PlayerDx; pl->dy = PlayerDy;
	 pl->setStat(PlayerState);
	 pl->data.posintexture = PlayerPosintext;
		*time = SavedTime;
		*bossstage = BossStage;
	//	pl->remainTime=PlayerRemainTime;
		*timepos = musicpos;
}

void GamaState::returnMobs(vector<Enemy>&mobs, vector<Enemy>&shots) {

	 mobs= SavedMobs;
	shots= SavedShots;
}

GamaState::~GamaState()
{

}
