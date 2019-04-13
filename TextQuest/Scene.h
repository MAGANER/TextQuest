/*
 this class is a basical conception of game.

*/

#pragma once
#include<string>
#include<fstream>
#include<vector>
#include<iostream>
#include"json.hpp"

using nlohmann::json;
using namespace std;

struct Action
{
	int number;
	string text;
	int next_scene_id;
};

class Scene
{
private:
	json data;

	int id;
	string type;
	string task;

	vector<Action*> actions;
public:
	vector<Action*> get_actions();
	string get_task();
	string get_type();

	void load(string path);
	Scene();
	~Scene();
};

