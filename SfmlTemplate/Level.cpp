#include "Level.h"


bool Level::LoadFromFile(vector<Enemy>&mobs, 
	string filename, 
	Texture* textura,
	int lvln, 
	Player*hedg,
	vector<Tile>& blocks, 
	vector<Tile> &blocksnocollis, 
	vector<Platform>& plat, 
	vector<Platform>& dmg)
{

	TiXmlDocument levelFile(filename.c_str());
	if (!levelFile.LoadFile())
	{
		std::cout << "Loading level \"" << filename << "\" failed." << std::endl;
		return false;
	}
	
	TiXmlElement *map;

	map = levelFile.FirstChildElement("map");

	width = atoi(map->Attribute("width"));
	height = atoi(map->Attribute("height"));
	tileWidth = atoi(map->Attribute("tilewidth"));
	tileHeight = atoi(map->Attribute("tileheight"));


	TiXmlElement *layerElement;
	layerElement = map->FirstChildElement("layer");
	while (layerElement)
	{
		TiXmlElement *layerDataElement;
		layerDataElement = layerElement->FirstChildElement("data");

		if (layerDataElement == NULL)
		{
			std::cout << "Bad map. No layer information found." << std::endl;
		}

		TiXmlElement *tileElement;
		tileElement = layerDataElement->FirstChildElement("tile");

		if (tileElement == NULL)
		{
			std::cout << "Bad map. No tile information found." << std::endl;
			return false;
		}

		int x = 0;
		int y = 0;

		while (tileElement)
		{
			int type = atoi(tileElement->Attribute("gid"));

			Tile block(type,lvln, textura, x*tileWidth, y*tileHeight, tileWidth, tileHeight);
			if (type == 8) {
				blocksnocollis.push_back(block);
			}
			else
			{
				blocks.push_back(block);
			}
			tileElement = tileElement->NextSiblingElement("tile");
			x++;
			if (x >= width)
			{
				x = 0;
				y++;
				if (y >= height)
					y = 0;
			}
		}
		layerElement = layerElement->NextSiblingElement("layer");

	}
	TiXmlElement *objectGroupElement;
	if (map->FirstChildElement("objectgroup") != NULL)
	{
		objectGroupElement = map->FirstChildElement("objectgroup");
		while (objectGroupElement)
		{

			TiXmlElement *objectElement;
			objectElement = objectGroupElement->FirstChildElement("object");
			while (objectElement)
			{

				string objectType;
				if (objectElement->Attribute("type") != NULL)
				{
					objectType = objectElement->Attribute("type");
				}

				int x = atoi(objectElement->Attribute("x"));
				int y = atoi(objectElement->Attribute("y"));
				int width = atoi(objectElement->Attribute("width"));
				int height = atoi(objectElement->Attribute("height"));

				if (objectType == "Player") {
					hedg->set(textura,x, y);
				}
				if (objectType == "Mob1") {
					Enemy tmpmob(textura,0,x,y,width,height);
					mobs.push_back(tmpmob);
				}
				if (objectType == "Mob2") {
					Enemy tmpmob(textura, 1, x, y, width, height);
					mobs.push_back(tmpmob);
				}
				if (objectType == "Mob3") {
					Enemy tmpmob(textura, 2, x, y, width, height);
					mobs.push_back(tmpmob);
				}
				if (objectType == "Mob4") {
					Enemy tmpmob(textura, 3, x, y, width, height);
					mobs.push_back(tmpmob);
				}
				if (objectType == "BossWall") {
					Enemy tmpmob(textura,4, x, y, width, height);
					mobs.push_back(tmpmob);
				}

				//reserved for boss :(
				//
				//
				if (objectType == "Boss") {
					Enemy tmpmob(textura,10, x, y, width, height);
					mobs.push_back(tmpmob);
				}

				if (objectType == "Platform") {
					Platform tmpplat(x, y, width, height, 0);
					plat.push_back(tmpplat);
				}
				if (objectType == "Damage") {
				
					Platform tmpplat(x, y, width, height, 1);
					dmg.push_back(tmpplat);
				}
				objectElement = objectElement->NextSiblingElement("object");
			}
			objectGroupElement = objectGroupElement->NextSiblingElement("objectgroup");
		}

	}
	return true;
}

Level::~Level()
{
}
