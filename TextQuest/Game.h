/*
 main class of game app.
 this class runs game, get input
 draw scene.
*/

#pragma once
#include"Scene.h"
#include<conio.h>
class Game
{
private:
	bool scenes_are_loaded;

	vector<Scene*> scenes;
private:
	void run_game();
	void run_death();
	void run_start();

	void load_scenes();
	int get_max_scene_number();
public:
	Game();
	~Game();

	void run();
};

