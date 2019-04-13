/*
 main class of game app.
 this class runs game, get input
 draw scene.
*/

#pragma once
#include"Scene.h"
#include<conio.h>

enum GameState
{
	game = 1,
	death,
	main_menu,
	help
};

class Game
{
private:
	bool running; // while it's true game is running

	bool scenes_are_loaded;
	int current_state;

	vector<Scene*> scenes;
private:
	void run_game();
	void run_death();
	void run_help();

	void draw_start();
	void run_start();

	void load_scenes();
	int get_max_scene_number();

	string get_user_input();
	void do_action(string user_choice);
public:
	Game();
	~Game();

	void run();
};

