#ifndef CL_BASE_H
#define CL_BASE_H

#include <iostream>

#include <string>

#include <vector>

using namespace std;

class cl_base
{
public:
		cl_base(cl_base * p_parent = 0);

	void set_object_name(string s_object_name);
	string get_object_name();
	
	//---------------------------------------------------------------    Иерахия объектов
	void set_parent(cl_base * p_parent);
	void add_child(cl_base * p_child);
	void delete_child(string s_object_name);
	cl_base * take_child(string s_object_name);
	cl_base * get_child(string s_object_name);
	int get_object_level();
	//---------------------------------------------------------------  Состояние объекта
	void set_state(int i_state);
	int get_state();
	
	//---------------------------------------------------------------    Сервис
	void show_object_state();
	void show_object_name();
private:
		vector<cl_base*> children; // ссылки на подчиненных объектов
	vector<cl_base*>::iterator it_child;
	
	string object_name; // наименование объекта
	cl_base * p_parent; // ссылка на головной объект
	int i_state; // состояние объекта
	
	cl_base * get_object_root();
	void show_state_next(cl_base * ob_parent);
	void show_name_next(cl_base * ob_parent);
};

#endif // CL_BASE_H
