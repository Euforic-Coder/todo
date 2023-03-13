#include <iostream>
#include <fstream>
#include <getopt.h>
#include <algorithm>
#include "uforia/uforia.h"

#define DEBUG 0
#if DEBUG
#define LOG(x) cout << colored(x, Red, Bold) << endl
#else
#define LOG(x)
#endif

using namespace std;

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
    sort(tasks.begin(), tasks.end(), [](Task a, Task b){
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
    LOG("Tasks read");
}

// Write file
void write(){
    ofstream write(path);
    for(int i = 0; i < tasks.size(); ++i){
        Task task = tasks[i];
        write << task.id << ";" << task.priority << ";" << task.description << endl;
    }
    LOG("Tasks writen");
}

// Add a task
void add(string description, int priority){
    Task task;
    task.description = description;
    task.priority = priority;
    task.get_id();
    tasks.push_back(task);
    LOG("Task added");
}

// Remove a task
void remove(int id){
    bool b = false;
    for(int i = 0; i < tasks.size(); ++i){
        if(tasks[i].id == id){
            tasks.erase(tasks.begin() + i);
            b = true;
            write();
            LOG("Task removed");
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
        LOG("Tasks cleared");
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
    HelpMaker help("todo");
    help.add_argument("-a", "Add a task");
    help.add_argument("-r", "Remove a task by ID");
    help.add_argument("-l", "List all tasks");
    help.add_argument("-c", "Clear all tasks");
    help.add_argument("-h", "Print help menu");
    help.print();
}

int main(int argc, char* argv[]){

    // Get path of .todo
    path = getenv("HOME");
    path = path + "/.todo";
    LOG(path);

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
            cout << "Enter the priority: ";
            cin >> buffer;

            // Check if the entered value is numberic
            if(is_number(buffer)){
                int priority = stoi(buffer);
                add(description, priority);
                write();
            }else{
                error("Priority has to be a numberic value", true);
            }
            break;
        }
        case 'r':{
            int id;

            // Check if the entered value is numberic
            if(is_number(optarg)){
                id = stoi(optarg);
                remove(id);}
            else {
                error("ID has to be a numberic value", true);
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
