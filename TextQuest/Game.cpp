#include "Game.h"

void Game::run()
{
	if (!scenes_are_loaded)
	{
		load_scenes();
	}
	
	switch (current_state)
	{
	case GameState::game:
		run_game();
		break;
	case GameState::main_menu:
		run_start();
		break;
	case GameState::death:
		run_death();
		break;
	}

    _getch();
}
void Game::run_game()
{

}
void Game::run_death()
{

}
void Game::run_start()
{
	system("cls");
	draw_start();
}
   
void Game::draw_start()
{
	cout <<"    " << "######### ######### #         #  ###########" << endl;
	cout << "   " << "    #     #          ##     ##        #     " << endl;
	cout << "   " << "    #     #            #   #          #     " << endl;
	cout << "   " << "    #     #########     # #           #     " << endl;
	cout << "   " << "    #     #              #            #     " << endl;
	cout << "   " << "    #     #           #    #          #     " << endl;
	cout << "   " << "    #     #          #      #         #     " << endl;
	cout << "   " << "    #     ######### #        #        #     " << endl;
	cout << endl;
	cout << "#########  #       #    #########  ###########   ##########" << endl;
	cout << "#       #  #       #    #          #                  #    " << endl;
	cout << "#       #  #       #    #          #                  #    " << endl;
	cout << "#       #  #       #    #########  ###########        #    " << endl;
	cout << "#       #  #       #    #                    #        #    " << endl;
	cout << "#       #  #       #    #                    #        #    " << endl;
	cout << "#########  #########    #########  ###########        #    " << endl;
	cout << "       ####                                                " << endl;
	cout << endl << endl;
	cout << "               type   START to start:                      " << endl;


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
	current_state = GameState::main_menu;
}




Game::~Game()
{
}
