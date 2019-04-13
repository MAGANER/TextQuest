/*
 this class is a basical conception of game.

*/

#pragma once
#include<string>
#include<fstream>
#include<vector>
#include<iostream>
#include<Windows.h>
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

	vector<Action> actions;
	void draw_actions();
public:
	vector<Action>& get_actions();
	string get_task();
	string get_type();
	int get_id();

	void load(string path);
	void draw();
	Scene();
	~Scene();
};

