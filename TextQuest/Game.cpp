#include "Game.h"

void Game::run()
{
	if (!scenes_are_loaded)
	{
		load_scenes();
	}

	while (running)
	{
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
		case GameState::help:
			run_help();
			break;
	    }

	string user_action = get_user_input();
	do_action(user_action);
	}


    _getch();
}
void Game::run_help()
{

}
void Game::run_game()
{
	scenes[scene_counter]->draw();
}
void Game::run_death()
{

}
void Game::run_start()
{
	system("cls");
	draw_start();
}

void Game::check_game_actions(string user_choice)
{
	Scene* current_scene = scenes[scene_counter];
	vector<Action*> actions = current_scene->get_actions();

	int user_choice_id = atoi(user_choice.c_str());
	for (size_t action_number = 0; action_number < actions.size(); ++action_number)
	{
		int current_action_number = actions[action_number]->number;

		if (current_action_number == user_choice_id)
		{
			scene_counter = actions[action_number]->next_scene_id;
		}

	}

	system("cls");
	
}
void Game::check_main_menu_actions(string user_choice)
{
	if (user_choice == "START")
	{
		system("cls");
		current_state = GameState::game;
	}
	if (user_choice == "help")
	{
		system("cls");
		current_state = GameState::help;
	}
}
void Game::do_action(string user_choice)
{
	switch (current_state)
	{
	case GameState::game:
		check_game_actions(user_choice);
		break;
	case GameState::help:
		break;
	case GameState::main_menu:
		check_main_menu_actions(user_choice);
		break;
	case GameState::death:
		break;
	}
	Beep(444, 70);
}
string Game::get_user_input()
{
	cout << ">>";
	string command;
    cin >> command;

	return command;
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
	running = true;
	scenes_are_loaded = false;
	current_state = GameState::main_menu;
	scene_counter = 0;

}




Game::~Game()
{
}
