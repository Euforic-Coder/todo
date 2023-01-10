#include <iostream>
#include <fstream>
#include "uforia/uforia.h"

using namespace std;

struct Task{
	int id = 0, priority = 0;
	string description;
	void get_id();
};

vector<Task> tasks;

// Give a task an id
void Task::get_id(){
	for(int i = 0; i < tasks.size(); ++i){
		if(tasks[i].id >= id){
			id = tasks[i].id + 1;
		}
	}
}

// Read file
void read(){
	ifstream read(".todo");
	if(read.good() && read.peek() != EOF){
		vector<string> buffer = from(".todo", true);
		for(int i = 0; i < buffer.size(); ++i){
			string line = buffer[i];
			vector<string> temp = from(line, ';');
			Task task;
			task.id = atoi(temp[0]);
			task.priority = atoi(temp[1]);
			task.description = temp[2];
			tasks.push_back(task);
		}
	}
}

// Write file
void write(){
	ofstream write(".todo");
	for(int i = 0; i < tasks.size(); ++i){
		Task task = tasks[i];
		write << task.id << ";" << task.priority << ";" << task.description << endl;
	}
}

// Add a task
void add(string description, int priority){
	Task task;
	task.description = description;
	task.priority = priority;
	task.get_id();
	tasks.push_back(task);
}

// Remove a task
void remove(int id){
	bool b;
	for(int i = 0; i < tasks.size(); ++i){
		if(tasks[i].id == id){
			tasks.erase(tasks.begin() + i);
			b = true;
		}
	}
	if(!b){
		error("Task not found", true);
	}
}

// Clear all tasks
void clear(){
	tasks.clear();
}

// Print all tasks
void print(){
	if(!tasks.empty()){
		for(int i = 0; i < tasks.size(); ++i){
			Task task = tasks[i];
			cout << task.id << "\t" << task.priority << "\t" << task.description << endl;
		}
	}else{
		error("No tasks to display", true);
	}
}

int main(int argc, char* argv[]){
	add("Walk to dog", 8);
	add("Do my homework", 7);
	add("Empty the trash", 5);
	write();
	read();
	print();
	return 0;
}