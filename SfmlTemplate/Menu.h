#pragma once
#include "Level.h"
int menu(RenderWindow & window, bool &Flag, Sound &JumpPlayer, Music &ReversPlayer, Music &MusicOnly4LVL, Music &MusicBossFight, Music &MusicBossWin, Sound &DeathPlayer);
int pause(RenderWindow & window,float,float, View*);
void death(RenderWindow & window, float, float);
int win(RenderWindow&window,int, Text &);
int LevelMenu(RenderWindow & window, int);