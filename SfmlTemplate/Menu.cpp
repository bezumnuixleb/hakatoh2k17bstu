#include "Menu.h"
#include <sstream>
int LevelMenu(RenderWindow & window, int Lvl)
{
	Texture Button[6];
	Texture ButtonT[6];
	Texture menuBack, BattonMenu, BattonMenuT;
	Button[0].loadFromFile("Buttons/Button1.png");
	Button[1].loadFromFile("Buttons/Button2.png");
	Button[2].loadFromFile("Buttons/Button3.png");
	Button[3].loadFromFile("Buttons/Button4.png");
	Button[4].loadFromFile("Buttons/Button5.png");

	ButtonT[0].loadFromFile("Buttons/Button11.png");
	ButtonT[1].loadFromFile("Buttons/Button22.png");
	ButtonT[2].loadFromFile("Buttons/Button33.png");
	ButtonT[3].loadFromFile("Buttons/Button44.png");
	ButtonT[4].loadFromFile("Buttons/Button55.png");

	BattonMenu.loadFromFile("Buttons/Menu.png");
	

	menuBack.loadFromFile("Buttons/fon.jpg");

	Sprite menu1(Button[0]), menu2(Button[1]), menu3(Button[2]), menu4(Button[3]), menu5(Button[4]),
		menu1T(ButtonT[0]), menu2T(ButtonT[1]), menu3T(ButtonT[2]), menu4T(ButtonT[3]), menu5T(ButtonT[4]),
		Fon(menuBack), Menu(BattonMenu);
	bool isMenu = 1;
	int menuNum = 0;



	menu1.setPosition(100, 130);
	menu2.setPosition(330, 130);
	menu3.setPosition(560, 130);
	menu4.setPosition(790, 130);
	menu5.setPosition(1020, 130);

	menu1T.setPosition(100, 130);
	menu2T.setPosition(330, 130);
	menu3T.setPosition(560, 130);
	menu4T.setPosition(790, 130);
	menu5T.setPosition(1020, 130);

	Fon.setPosition(0, 0);

	Menu.setPosition(0, 570);

	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		window.clear();

		window.draw(Fon);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		window.draw(menu4);
		window.draw(menu5);
		
		if (Lvl == 1) { window.draw(menu1T); }
		if (Lvl == 2) { window.draw(menu2T); }
		if (Lvl == 3) { window.draw(menu3T); }
		if (Lvl == 4) { window.draw(menu4T); }
		if (Lvl == 5) { window.draw(menu5T); }

		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}
		}
		menuNum = 0;

		if (IntRect(0, 570, 500, 150).contains(Mouse::getPosition(window))) { menuNum = 6; Menu.setPosition(-5, 575); window.draw(Menu);}
		else
		{
			Menu.setPosition(0, 570);
			window.draw(Menu);
		}
		if (IntRect(100, 130, 200, 200).contains(Mouse::getPosition(window))) { menuNum = 1; }
		if (IntRect(330, 130, 200, 200).contains(Mouse::getPosition(window))) { menuNum = 2; }
		if (IntRect(560, 130, 200, 200).contains(Mouse::getPosition(window))) { menuNum = 3; }
		if (IntRect(790, 130, 200, 200).contains(Mouse::getPosition(window))) { menuNum = 4; }
		if (IntRect(1020, 130, 200, 200).contains(Mouse::getPosition(window))) { menuNum = 5; }


		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 6) { return Lvl; }
			if (menuNum == 1) { Lvl = 1; }
			if (menuNum == 2) { Lvl = 2; }
			if (menuNum == 3) { Lvl = 3; }
			if (menuNum == 4) { Lvl = 4; }
			if (menuNum == 5) { Lvl = 5; }

		}
		window.display();
	}
	////////////////////////////////////////////////////


}
int menu(RenderWindow & window, bool &Flag, Sound &JumpPlayer, Music &ReversPlayer, Music &MusicOnly4LVL, Music &MusicBossFight, Music &MusicBossWin, Sound &DeathPlayer)
{


	int LVL = 1;
	Texture menuTexture1, menuTexture2, menuTexture3, menuBackground, soundt1, soundt0;
	menuTexture1.loadFromFile("images/11.png");//play
	menuTexture2.loadFromFile("images/22.png");//Выход
	menuTexture3.loadFromFile("images/33.png");//lvl
	soundt1.loadFromFile("Buttons/sound1.png");
	soundt0.loadFromFile("Buttons/sound2.png");
	menuBackground.loadFromFile("images/fon.jpg");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), menuBg(menuBackground), sound1(soundt1), sound0(soundt0);
	bool isMenu = 1;
	int menuNum = 0;
	sound1.setPosition(1080, 0);
	sound0.setPosition(1080, 0);
	menu1.setPosition(380, 30);
	menu2.setPosition(380, 230);
	menu3.setPosition(380, 430);
	menuBg.setPosition(0, 0);

	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		window.clear();

		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);
		if (Flag == true)window.draw(sound0);
		else window.draw(sound1);

		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}

			menuNum = 0;
			if (IntRect(380, 30, 500, 150).contains(Mouse::getPosition(window))) {
				menu1.setPosition(375, 35);
				window.draw(menu1); menuNum = 1;
			}
			else
			{
				menu1.setPosition(380, 30);
				window.draw(menu1);
			}
			if (IntRect(380, 230, 500, 150).contains(Mouse::getPosition(window))) { menu2.setPosition(375, 235); window.draw(menu2); menuNum = 2; }
			else
			{
				menu2.setPosition(380, 230);
				window.draw(menu2);
			}
			if (IntRect(380, 430, 500, 150).contains(Mouse::getPosition(window))) { menu3.setPosition(375, 435); window.draw(menu3); menuNum = 3; }
			else
			{
				menu3.setPosition(380, 430);
				window.draw(menu3);
			}
			if (IntRect(1080, 0,200, 200).contains(Mouse::getPosition(window))) {	 menuNum = 4; }
			else
			{

			}
			
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (menuNum == 1) { isMenu = false; return LVL; }//если нажали первую кнопку, то выходим из меню 
				if (menuNum == 2) { LVL = LevelMenu(window, LVL); }
				if (menuNum == 3) { window.close(); isMenu = false; }
				if (menuNum == 4) {
					if (Flag == true)Flag = false; else Flag = true;
					
				}
				if (Flag == true)
				{

					JumpPlayer.setVolume(100);
					ReversPlayer.setVolume(70);
					MusicOnly4LVL.setVolume(70);
					MusicBossFight.setVolume(70);
					MusicBossWin.setVolume(70);
					DeathPlayer.setVolume(70);
				}
				else
				{
					JumpPlayer.setVolume(0);
					ReversPlayer.setVolume(0);
					MusicOnly4LVL.setVolume(0);
					MusicBossFight.setVolume(0);
					MusicBossWin.setVolume(0);
					DeathPlayer.setVolume(0);
				}
			}
			
		}window.display();
			
		}
		////////////////////////////////////////////////////
}

int pause(RenderWindow & window, float x, float y,View* view)
{
	Texture pauseTexture1, pauseTexture2, pause, pauseFON;

	pauseTexture1.loadFromFile("images/pause11.png");//play
	pauseTexture2.loadFromFile("images/pause22.png");//Выход

	pause.loadFromFile("images/pause.png");
	pauseFON.loadFromFile("images/fon.jpg");//play

	Sprite pause1(pauseTexture1), pause2(pauseTexture2),  PAUSE(pause), pauseFon(pauseFON);
	bool isMenu = 1;
	int menuNum = 0;

	pause1.setPosition(x-640+80, 200);
	pause2.setPosition(x - 640 + 80, 400);


	PAUSE.setPosition(x - 640 + 130, 30);
	pauseFon.setPosition(x - 640, 0);
	pauseFon.setColor(sf::Color(255, 255, 255, 128));
	//////////////////////////////МЕНЮ///////////////////
	

	//window.draw(pauseFon);
	while (isMenu)
	{
		
		window.clear();
		window.draw(PAUSE);
		window.draw(pauseFon);

		
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		menuNum = 0;
		
		if (IntRect(80,200, 500, 150).contains((Mouse::getPosition(window)))) { 
			pause1.setPosition(x - 640 + 75, 205);
			window.draw(pause1); menuNum = 1; }
		else
		{
			pause1.setPosition(x - 640 + 80, 200);
			window.draw(pause1);
		}
		if (IntRect(80, 400, 500, 150).contains(Mouse::getPosition(window))) { pause2.setPosition(x - 640 + 75, 405); window.draw(pause2); menuNum = 2; }
		else
		{
			pause2.setPosition(x - 640 + 80, 400);
			window.draw(pause2);
		}

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) { isMenu = false; return 1; }//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { isMenu = false; return 0; }

		}
		//window.setView(*view);
		window.display();

	}
	////////////////////////////////////////////////////
}
void death(RenderWindow & window, float x, float y)
{
	Texture menuTexture1, menuTexture2, menuBackground, menuTexture1T, menuTexture2T;

	menuTexture1.loadFromFile("images/Menu.png");//Menu
	menuTexture2.loadFromFile("images/Exit1.png");//Выход

	menuBackground.loadFromFile("images/End.jpg");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menuBg(menuBackground);
	bool isMenu = 1;
	int menuNum = 0;


	
	menu1.setPosition(x-260, 30);
	menu2.setPosition(x - 260, 230);


	menuBg.setPosition(x-640, 0);

	//////////////////////////////МЕНЮ///////////////////
	while (isMenu)
	{
		window.clear();

		window.draw(menuBg);
		
		
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}
		}
		menuNum = 0;
		if (IntRect(380, 30, 500, 150).contains(Mouse::getPosition(window))) { 
			menu1.setPosition(x - 255, 35);
			window.draw(menu1); menuNum = 1; }
		else
		{
			window.draw(menu1);
			menu1.setPosition(x - 260, 30);
		


		}
		if (IntRect(380, 230, 500, 150).contains(Mouse::getPosition(window))) {
			menu2.setPosition(x - 255, 235); window.draw(menu2); menuNum = 2; }
		else
		{
			window.draw(menu2);
			menu2.setPosition(x - 260, 230);
		}

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) { isMenu = false; }//если нажали первую кнопку, то выходим из меню 
			if (menuNum == 2) { window.close(); isMenu = false; }

		}
		window.display();
	}
	////////////////////////////////////////////////////
}

int win(RenderWindow & window,int lvln, Text &text)
{
	if (lvln != 5)
	{
		text.setFillColor(Color::Red);
		std::ostringstream Level;
		Level << lvln;
		text.setString("Уровень " + Level.str() + " пройден !");
		text.setPosition(510, 10);
	}
	else
	{
		text.setString("ИГРА ПРОЙДЕНА !");
		text.setPosition(510, 385);
	}
	



	Texture background, but1, but1T, but2T, but2;
	if (lvln == 5)
	{
		background.loadFromFile("images/fonWIN.jpg");
	}
	else
	{
		background.loadFromFile("images/winnerhedge.png");
	}
	but1.loadFromFile("images/winMenu.png");
	but1T.loadFromFile("images/winMenuT.png");
	but2.loadFromFile("images/winNext.png");
	but2T.loadFromFile("images/winNextT.png");

	Sprite back(background),bt1(but1),bt1T(but1),bt2(but2),bt2T(but2);

	back.setPosition(0, 0);
	if (lvln == 5)
	{
		bt1.setPosition(450, 100);
		bt1T.setPosition(445, 110);
	}
	else
	{
		bt1.setPosition(200, 300);
		bt1T.setPosition(195, 310);
	}
	bt2.setPosition(700, 300);
	bt2T.setPosition(690, 310);

	bool isMenu = 1;
	int menuNum = 0;
	while (isMenu)
		{
			window.clear();

			window.draw(back);
			
			

			sf::Event event;

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				
			}
			menuNum = 0;
			if(lvln!=5){
			if (IntRect(200, 300, 400, 150).contains(Mouse::getPosition(window))) { window.draw(bt1T); menuNum = 1; }
			else
			{
				window.draw(bt1);
			}
			if (IntRect(700, 300, 400, 150).contains(Mouse::getPosition(window))&& lvln != 5) { window.draw(bt2T); menuNum = 2; }
			else
			{
				if (lvln != 5) { window.draw(bt2); }
			}
			}
			else
			{
				if (IntRect(450, 100, 400, 150).contains(Mouse::getPosition(window))) { window.draw(bt1T); menuNum = 1; }
				else
				{
					window.draw(bt1);
				}
			}
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (menuNum == 1) { isMenu = false; return 0; }
				if (menuNum == 2 && lvln != 5) { isMenu = false; return 1; }

			}
			window.draw(text);
			window.display();
		}
	return 0;
}
