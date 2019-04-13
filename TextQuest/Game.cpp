#include "Game.h"

void Game::run()
{
	if (!scenes_are_loaded)
	{
		load_scenes();
	}

	auto scene = scenes.begin();
    _getch();
}

void Game::load_scenes()
{
	int max_scene_number = get_max_scene_number();
	for (size_t scene_number = 0; scene_number < max_scene_number; ++scene_number)
	{
		Scene* scene = new Scene();

		string path = "materials/"+to_string(scene_number) + ".json";
		scene->load(path);
		scenes.push_back(scene);
	}
	scenes_are_loaded = true;
}
int Game::get_max_scene_number()
{
	int max_number = 0;
	ifstream max_number_file("materials/max_number.txt");
	if (max_number_file.fail())
	{
		cout << "can not load maximimum number of scenes!" << endl;
	}
	else
	{
		max_number_file >> max_number;
		max_number_file.close();
		return max_number;
	}
}
Game::Game()
{
	scenes_are_loaded = false;
}




Game::~Game()
{
}