#pragma once
#include "Player.h"

using namespace sf;
using namespace std;



class Level
{
public:
	bool LoadFromFile (
		vector<Enemy>&mobs,
		string filename,
		Texture*,
		int lvln,
		Player*,
		vector<Tile>& blocks,
		vector<Tile> &blocksnocollis,
		vector<Platform>& plat,
		vector<Platform>& dmg);

	int width, height, tileWidth, tileHeight;
	int firstTileID;

public:
	
	~Level();
};


