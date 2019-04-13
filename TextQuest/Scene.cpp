#include "Scene.h"


string Scene::get_type()
{
	return type;
}
vector<Action*> Scene::get_actions()
{
	return actions;
}
string Scene::get_task()
{
	return task;
}
void Scene::load(string path)
{
	ifstream file(path);
	if (file.fail())
	{
		cout << "error:scene can not be loaded!" << endl;
	}
	else
	{
        file >> data;

	    int object_counter = 0;
	    bool loading = true;
	    while (loading)
	    {
		   if (!data["scenes"][to_string(object_counter)].empty())
		   {
			   id = data["scenes"][to_string(0)].at(0);

			   
			   // type = data["scenes"][to_string(0)].at(1) DOES NOT WORK! LOL
			   //correct version
			   string _type = data["scenes"][to_string(0)].at(1);
			   type = _type;

			   //the same problem, the same solution
			   string _task = data["scenes"][to_string(0)].at(2);
			   task = _task;

			   object_counter++;
			   //load all actions to do
			   while (!data["scenes"][to_string(object_counter)].empty())
			   {
				   Action * action = new Action;
				   action->number = data["scenes"][to_string(object_counter)].at(0);

				   string text   = data["scenes"][to_string(object_counter)].at(1);
				   action->text = text;

				   action->next_scene_id = data["scenes"][to_string(object_counter)].at(2);

				   object_counter++;
			   }
		   }
		   else
		   {
			   cout << "level is loaded" << endl;
			   loading = false;
		   }
	    }
	}

	
}


Scene::Scene()
{
}


Scene::~Scene()
{
}
