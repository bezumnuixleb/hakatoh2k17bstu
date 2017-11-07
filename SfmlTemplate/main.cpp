#include "GamaState.h"
#include <sstream>

using namespace sf;
int main()
{
	bool MusicFlag = true;
	///////////////

	SoundBuffer Jump;
	Jump.loadFromFile("zbuk/jump.ogg");
	Sound JumpPlayer(Jump);

	Music ReversPlayer;
	ReversPlayer.openFromFile("zbuk/revers.ogg");
	bool FlagRevers = false;

	Music MusicOnly4LVL;
	MusicOnly4LVL.openFromFile("zbuk/musik.ogg");
	MusicOnly4LVL.setVolume(10);

	Music MusicBossFight;
	MusicBossFight.openFromFile("zbuk/bossfight.ogg");
	MusicBossFight.setVolume(10);

	Music MusicBossWin;
	MusicBossWin.openFromFile("zbuk/tokyohule.ogg");
	MusicBossWin.setVolume(20);

	SoundBuffer Death;
	Death.loadFromFile("zbuk/vilgelm.ogg");
	Sound DeathPlayer(Death);
	//DeathPlayer.setVolume(50);
	bool FlagDeath = false;

	Music MusicWin;
	MusicWin.openFromFile("zbuk/saxguy.ogg");
	MusicWin.setVolume(20);
	//////////

	Font font;//шрифт 
	font.loadFromFile("CyrilicOld.ttf");//передаем нашему шрифту файл шрифта
	Text text("", font, 32);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
	Text textremain("", font, 72);					//	text.setColor(Color::Red);//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
	text.setStyle(Text::Bold);//жирный текст.
	float TIME = 5;
	float remainTIME;
	bool iswin = false;
	RenderWindow window(sf::VideoMode(1280, 720), "HEDGEHOG");
	
	//window.setFramerateLimit (60);
	vector<Tile> tiles, tilesnocollis;
	vector<Platform> Plat , Dmg;
	View view;
	view.reset(sf::FloatRect(0, 0, 1280, 720));
	deque<GamaState> TimeLine;
	vector<Enemy> mobs,shots;
	Level level;
	Texture maintext;
	Texture clocke;//,interface1,interface2;
	clocke.loadFromFile("images/clock.png");
	//interface1.loadFromFile("images/interface1.png");
	//interface2.loadFromFile("images/interface2.png");
	//Sprite face1(interface1), face2(interface2),
	Sprite clck(clocke);
	sf::Time musicpos = sf::seconds(0);
	maintext.loadFromFile("textures/world/maintext.png");
	Clock clock;	
	Player hedgehog;
	int lvlnum =1;
	bool levelisrun = false;
	bool isRevers = false;
	bool nextlevel = false;
	float BossStage = 0;
	while (window.isOpen())
	{
		if (levelisrun == false) {
			///////////////////
			FlagRevers = false;
			FlagDeath = false;
			ReversPlayer.stop();
			MusicOnly4LVL.stop();
			MusicBossFight.stop();
			MusicBossWin.stop();
			MusicWin.stop();
			///////////////////

			view.reset(sf::FloatRect(0, 0, 1280, 720)); view.setCenter(640, 360);
			window.setView(view);
			if(nextlevel==false)lvlnum=menu(window, MusicFlag,JumpPlayer,ReversPlayer,MusicOnly4LVL,MusicBossFight,MusicBossWin,DeathPlayer);
			nextlevel = false;
			clock.restart();
			switch (lvlnum)
			{
			case 1: {
				level.LoadFromFile(mobs,
					"maps/level1.tmx",
					&maintext, 0,
					&hedgehog,
					tiles, tilesnocollis, Plat, Dmg); }
				break;
			case 2: {
				level.LoadFromFile(mobs,
					"maps/level2.tmx",
					&maintext,1,
					&hedgehog,
					tiles, tilesnocollis, Plat, Dmg);
			}break;
			case 3: {
				level.LoadFromFile(mobs,
					"maps/level3.tmx",
					&maintext, 2,
					&hedgehog,
					tiles, tilesnocollis, Plat, Dmg);
			}break;
			case 4: {
				level.LoadFromFile(mobs,
					"maps/level4.tmx",
					&maintext, 3,
					&hedgehog,
					tiles, tilesnocollis, Plat, Dmg);
			}break;
			case 5: {
				level.LoadFromFile(mobs,
					"maps/levelboss.tmx",
					&maintext, 4,
					&hedgehog,
					tiles, tilesnocollis, Plat, Dmg);
				BossStage = 0;
				//2000(95x95)
			}break;
			default: {
				level.LoadFromFile(mobs,
					"maps/level1.tmx",
					&maintext, 0,
					&hedgehog,
					tiles, tilesnocollis, Plat, Dmg);
			}
				break;
			}

			musicpos = sf::seconds(0);
			//level.LoadFromFile("maps/test.tmx",&maintext, tiles, tilesnocollis,&hedgehog,mobs);
			levelisrun = true;
			iswin = false;
			remainTIME = 10000;
			text.setFillColor(Color::White);
			//}break;
		}
		else
		{//igrovoi process
			float time = clock.getElapsedTime().asMicroseconds();
			clock.restart();
			time = time / 800;
			
			
			/////////////////////
			if (lvlnum == 5)
			{
				if (MusicBossFight.getStatus() != sf::SoundSource::Status::Playing
					&& (FlagRevers == false || remainTIME == 0))
				{
				
					MusicBossFight.play();
				}
				if (FlagRevers == true || hedgehog.alife == false)
				{
					
					MusicBossFight.pause();
				}
			}
			if (MusicOnly4LVL.getStatus() != sf::SoundSource::Status::Playing && FlagRevers == false && lvlnum != 5 && hedgehog.alife == true)
			{
				MusicOnly4LVL.play();
			}
			if (FlagRevers == true || hedgehog.alife == false)
			{
				MusicOnly4LVL.pause();
			}
			if (hedgehog.alife == true)
			{
				FlagDeath = false;
			}
			///////////////////////

			if (hedgehog.x > level.width * 80 - 60) {
				iswin = true;
			}



			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				if (Keyboard::isKeyPressed(Keyboard::Escape))
				{
					Vector2f tmp = view.getCenter();
					if(pause(window,tmp.x,tmp.y, &view)==0)
					{
						
						levelisrun = false;
						tiles.clear(); tilesnocollis.clear();
						Plat.clear(); Dmg.clear();
						TimeLine.clear();
						mobs.clear(); shots.clear();
						isRevers = false;
						clock.restart();
						continue;
					}
					
					clock.restart();
				}
				//////////////////////////////////
				if (event.key.code == Keyboard::Up) {
					if (hedgehog.onground == true)
					{
						JumpPlayer.play();
					}
				}
				//////////////////////////////////
				if (event.type == sf::Event::KeyReleased)
				{
					if (event.key.code == Keyboard::Right) {
						hedgehog.stop();
						hedgehog.speed = 0;
						hedgehog.ismove = false;
					}

					if (event.key.code == Keyboard::Left) {
						hedgehog.stop();
						hedgehog.speed = 0;
						hedgehog.ismove = false;
					}
					if (event.key.code == Keyboard::Space) {
						
					}
				}
			}
			/////////////////////////////
			if (!Keyboard::isKeyPressed(Keyboard::Space) || remainTIME <= 0|| TimeLine.size() < 1)
			{
				FlagRevers = false;
				ReversPlayer.stop();
				
				//MusicBossFight.play();
			}
			/////////////////////////////
			



			if (Keyboard::isKeyPressed(Keyboard::Space)&&remainTIME>0) {
				///////////////////////
				clck.setPosition(view.getCenter().x -640, 50);
				window.draw(clck);
				if (FlagRevers == false)
				{
					FlagRevers = true;
					ReversPlayer.play();
				}
				////////////////////////
				if (TimeLine.size() > 0) {
					TimeLine.front().returnPlayer(&hedgehog,&TIME,&BossStage,&musicpos);
 					TimeLine.front().returnMobs(mobs, shots);
					TimeLine.pop_front();
					remainTIME -= time;
					if (remainTIME < 0)remainTIME = 0;
				}

			}
			else
			{
			
				GamaState tmp(&hedgehog, mobs, shots, TIME,BossStage,musicpos);
				TimeLine.push_front(tmp);
				if (TimeLine.size() > 3000) {
					TimeLine.pop_back();

				}

			}
			hedgehog.update(time, Plat, Dmg, mobs, shots);
			
			
			for (int i = 0; i < mobs.size(); i++)
			{if(mobs[i].core.type==10)mobs[i].updateBoss(hedgehog.x, hedgehog.y, time, &BossStage,shots);
			else mobs[i].updateMobs(hedgehog.x,hedgehog.y,time, Plat,shots);
			}
			for (int i = 0; i < shots.size(); i++)
			{
				shots[i].updateShots(hedgehog.x, hedgehog.y, time, Plat);
			}
			if (hedgehog.x + 100 < 640) {
				view.setCenter(640, 360);
			}
			else
			{
				if (hedgehog.x + 100 > level.width * 80 - 640) {
					view.setCenter(level.width*80-640, 360);
				}
				else
				{
					view.setCenter(hedgehog.x + 100, 360);
				}
			}
			window.setView(view);
			
			window.clear();
			for (int i = 0; i < tilesnocollis.size(); i++)
			{
				window.draw(tilesnocollis[i].show());
			}
			for (int i = 0; i < tiles.size(); i++)
			{
				window.draw(tiles[i].show());
			}
			for (int i = 0; i < mobs.size(); i++)
			{
				window.draw(mobs[i].show()); 
			}
			for (int i = 0; i < shots.size(); i++)
			{
				if (shots[i].core.alife == true) {
					window.draw(shots[i].show());
				}
				
			}

			window.draw(hedgehog.show());
			
			std::ostringstream remainStringsec;
			std::ostringstream remainStringms;
			remainStringsec <<(int)remainTIME/1000;
			remainStringms<<((int)remainTIME % 1000)/10;
			if ((int)remainTIME % 1000 > 100) {
				text.setString(remainStringsec.str() + ":" + remainStringms.str());
			}
			else {
				text.setString(remainStringsec.str() + ":" +"0" + remainStringms.str());
			}
			text.setPosition(view.getCenter().x, view.getCenter().y - 360);
			//face1.setPosition(view.getCenter().x-300, -8);
			//window.draw(face1);
			window.draw(text);
			if (Keyboard::isKeyPressed(Keyboard::Space) && remainTIME > 0) {
				///////////////////////
				clck.setPosition(view.getCenter().x - 640, 50);
				window.draw(clck);
			}
			if (hedgehog.alife == true) TIME =2;
			if (hedgehog.alife == false)
			{
				////////////////
				if (FlagDeath == false && hedgehog.alife == false)
				{
					FlagDeath = true;
					MusicWin.stop();
					MusicOnly4LVL.pause();
					MusicBossFight.pause();
					MusicBossWin.stop();
					DeathPlayer.play();
				}
				////////////////
				TIME = TIME - clock.getElapsedTime().asSeconds();
				std::ostringstream timetodiesec;
				std::ostringstream timetodiems;
				timetodiesec << (int)TIME;
				timetodiems << (int)(TIME*100)%100 ;
				
				//face2.setPosition(view.getCenter().x-740 , 0);
				text.setString("Времени до смерти: " + timetodiesec.str()+ ":" +timetodiems.str());
				text.setPosition(view.getCenter().x - 640, view.getCenter().y - 360);
				//window.draw(face2);
				window.draw(text);
				if (TIME < 0)
				{
					
					Vector2f tmp = view.getCenter();
					death(window, tmp.x, tmp.y);
					levelisrun = false;
					tiles.clear();tilesnocollis.clear();
					Plat.clear();Dmg.clear();
					TimeLine.clear();
					mobs.clear();shots.clear();
					isRevers = false;
					iswin = false;
				}
			}
			if (iswin == true) {
				///////////////////////////
				FlagDeath = false;
				ReversPlayer.stop();
				MusicOnly4LVL.pause();
				MusicBossFight.pause();

				if (lvlnum == 5)
				{
					MusicBossWin.play();
				}
				if (lvlnum <= 4)
				{
					MusicWin.play();
				}
				//////////////////////////
				view.reset(sf::FloatRect(0, 0, 1280, 720)); view.setCenter(640, 360);
				window.setView(view);
				if (win(window, lvlnum, text) == 1) {
					lvlnum++;
					nextlevel = true;
					if (lvlnum > 5)lvlnum = 0;
					levelisrun = false;
					tiles.clear(); tilesnocollis.clear();
					Plat.clear(); Dmg.clear();
					TimeLine.clear();
					mobs.clear(); shots.clear();
					isRevers = false;
					iswin = false;
				}
				else
				{
					levelisrun = false;
					tiles.clear(); tilesnocollis.clear();
					Plat.clear(); Dmg.clear();
					TimeLine.clear();
					mobs.clear(); shots.clear();
					isRevers = false;
					iswin = false;
				}
			}
		}
		window.display();
	}

	return 0;
}