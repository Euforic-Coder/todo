#include <iostream>
#include <fstream>
#include <getopt.h>
#include <algorithm>
#include "uforia/uforia.h"

using namespace std;
using namespace uforia;

string path;

struct Task{
    int id = 0, priority = 0;
    string description;
    void get_id();
};

vector<Task> tasks;

// Give a task an id
void Task::get_id(){
    // sort tasks by ID
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b){
        return a.id < b.id;
    });

    for(int i = 0; i < tasks.size(); ++i){
        if(tasks[i].id >= id){
            id = tasks[i].id + 1;
        }
    }
}

// Read file
void read(){
    ifstream read(path);
    if(read.good() && read.peek() != EOF){
        vector<string> buffer = from(path, true);
        for(int i = 0; i < buffer.size(); ++i){
            string line = buffer[i];
            vector<string> temp = from(line, ';');
            Task task;
            int id, priority;
            string description;
            id = stoi(temp[0]);
            priority = stoi(temp[1]);
            task.id = id;
            task.priority = priority;
            description = temp[2];
            task.description = description;
            tasks.push_back(task);
        }
    }
}

// Write file
void write(){
    ofstream write(path);
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
    bool b = false;
    for(int i = 0; i < tasks.size(); ++i){
        if(tasks[i].id == id){
            tasks.erase(tasks.begin() + i);
            b = true;
            write();
        }
    }
    if(!b){
        error("Task not found", true);
    }
}

// Clear all tasks
void clear(){
    string buffer;
    cout << "Are you sure you want to clear all tasks? [y/n] : ";
    getline(cin, buffer);
    if(lowercase(buffer) == "y"){
        tasks.clear();
        write();
    }
}

// Print all tasks
void print(){
    if(!tasks.empty()){
        // Sort tasks by priority
        sort(tasks.begin(), tasks.end(), [](Task a, Task b){
            return a.priority > b.priority;
        });

        // Print header
        cout << "ID\tPriority\tDescription" << endl;
        cout << "----------------------------------------------" << endl;

        for(int i = 0; i < tasks.size(); ++i){
            Task task = tasks[i];
            cout << task.id << "\t" << task.priority << "\t\t" << task.description << endl;
        }
    }else{
        error("No tasks to display", true);
    }
}

// Help menu
void help(){
    HelpMenu help("todo");
    help.add_option("-a", "Add a task", true);
    help.add_option("-r", "Remove a task by ID", true);
    help.add_option("-l", "List all tasks", true);
    help.add_option("-c", "Clear all tasks", false);
    help.add_option("-h", "Print help menu", false);
    help.print();
}

int main(int argc, char* argv[]){

    // Get path of .todo
    path = getenv("HOME");
    path = path + "/.todo";

    read();

    // Getopt
    int c;

    while ((c = getopt (argc, argv, "ar:lch")) != -1){
        switch (c){
        case 'a':{
            string buffer, description;
            cout << "Enter the description: ";
            getline(cin, buffer);
            description = buffer;

            // Checks if the given string doesn't have a ';' in it
            if(has(';', buffer)){
                error("Description can not have a ';' in it", true);
            }

            cout << "Enter the priority: ";
            cin >> buffer;

            // Checks if the given priority is numeric
            if(is_numeric(buffer)) {
                int priority = stoi(buffer);
                add(description, priority);
                write();
            }else{
                error("The given priority must be numeric", true);
            }
            break;
        }
        case 'r':{
            int id;
            if(is_numeric(optarg)) {
                id = stoi(optarg);
                remove(id);
            }else{
                error("The given ID must be numeric", true);
            }
            break;
        }
        case 'l':
            print();
            break;
        case 'c':
            clear();
            break;
        case 'h':
            help();
            break;
        }
    }
    return 0;
}
