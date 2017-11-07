#include <SFML/Graphics.hpp>
#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include "TinyXML/tinyxml.h"
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

struct forrend {
	Texture texture;
	Sprite sprite;
	FloatRect posinworld ; 
	IntRect posintexture;
};
