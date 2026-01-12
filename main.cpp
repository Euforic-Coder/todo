#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <getopt.h>

using namespace std;


// Debug logging
void log(const string &s) {
    cout << "Debug: " + s << endl;
}

class Task {
public:
    Task();

    int get_id();

    int get_priority();

    void set_id(int i);

    void set_priority(int i);

    void set_description(string s);

    string get_description();

private:
    int id = 0, priority = 0;
    string description;

    void give_id();
};

vector<Task> tasks;

// Task will add a description and set a unique id when constructed
Task::Task() {
    give_id();
}

// Gives the id of the task
int Task::get_id() {
    return id;
}

// Gives the priority of the task
int Task::get_priority() {
    return priority;
}

void Task::set_id(int i) {
    this->id = i;
}

void Task::set_priority(int i) {
    this->priority = i;
}

// Define the description of the task
void Task::set_description(string s) {
    this->description = s;
}

string Task::get_description() {
    return description;
}

// Give a task an id
void Task::give_id() {
    // Sort tasks by id
    sort(tasks.begin(), tasks.end(), [](Task a, Task b) { return a.get_id() < b.get_id(); });

    // Create a new id for the last task
    for (int i = 0; i < tasks.size(); ++i) {
        Task task = tasks[i];
        if (task.id >= id) {
            id = task.id + 1;
        }
    }
}

string file_path = "todo.txt";

// Read tasks from file
void read() {
    log("read file");
    ifstream read_file(file_path);
    if (read_file.good() && read_file.peek() != EOF) {
        // Convert file in lines
        string line;
        while (getline(read_file, line)) {
            log(line);

            // Split lines into datatypes and make a task
            vector<string> buffer;
            int pos = 0, len = 0;
            for (int i = 0; i < line.length(); ++i) {
                char c = line[i];
                if (c == ';') {
                    buffer.push_back(line.substr(pos, len));
                    log(line.substr(pos, len));
                    len = 0;
                    pos = i + 1;
                } else if (i == line.length() - 1) {
                    int end = line.length() - pos;
                    buffer.push_back(line.substr(pos, end));
                    log(line.substr(pos, len));
                } else {
                    len++;
                }
            }
            // Debug
            for (const auto &a: buffer) {
                log(a);
            }

            // Convert data into a task
            Task task;
            int id = stoi(buffer[0]), priority = stoi(buffer[1]);
            string description = buffer[2];
            task.set_id(id);
            task.set_priority(priority);
            task.set_description(description);

            // Add task to tasks
            tasks.push_back(task);
        }
    }
}

// Write tasks to file
void write() {
    ofstream write_file(file_path);
    for (int i = 0; i < tasks.size(); ++i) {
        Task task = tasks[i];
        write_file << task.get_id() << ";" << task.get_priority() << ";" << task.get_description() << endl;
    }
}

int main(int argc, char *argv[]) {
    bool flag_add = false, flag_remove = false, flag_list = false, flag_clear = false, flag_help = false,
            flag_debug = true;

    // Handle getopt
    int opt;
    int option_index;

    static struct option long_options[] = {
        {"add", no_argument, nullptr, 'a'},
        {"remove", required_argument, nullptr, 'r'},
        {"list", no_argument, nullptr, 'l'},
        {"clear", no_argument, nullptr, 'c'},
        {"help", no_argument, nullptr, 'h'},
        {nullptr, 0, nullptr, 0}
    };

    while ((opt = getopt_long(argc, argv, "a:r:l:ch", long_options, &option_index)) != -1) {
        switch (opt) {
            case 'a':
                flag_add = true;
                log("flag_add");
                break;
            case 'r':
                flag_remove = true;
                log("flag_remove");
                break;
            case 'l':
                flag_list = true;
                log("flag_list");
                break;
            case 'c':
                flag_clear = true;
                log("flag_clear");
                break;
            case 'h':
                flag_help = true;
                log("flag_help");
                break;
            default:
                exit(0);
        }
    }

    read();

    // Add a task to the list
    if (flag_add) {
        Task task;
        string s;

        cout << "Set the task description: ";
        getline(cin, s);
        task.set_description(s);

        cout << "Set priority : ";
        getline(cin, s);
        task.set_priority(stoi(s));

        tasks.push_back(task);
        // Debug
        if (flag_debug) {
            log(to_string(task.get_id()) + " - " + to_string(task.get_priority()) + " - " + task.get_description());
        }
    }

    // TODO: Remove a task
    if (flag_remove) {
    }

    // TODO: List all tasks
    if (flag_list) {
        if (!tasks.empty()) {
            // Sort tasks by priority
            sort(tasks.begin(), tasks.end(), [](Task a, Task b) {
                return a.get_priority() > b.get_priority();
            });

            // List header
            cout << "ID\tPriority\tDescription" << endl;
            cout << "----------------------------------------------" << endl;

            for (int i = 0; i < tasks.size(); ++i) {
                Task task = tasks[i];
                cout << task.get_id() << "\t" << task.get_priority() << "\t\t" << task.get_description() << endl;
            }
        }
    }

    // TODO: Clear all tasks
    if (flag_clear) {
    }

    // Handle the helpmenu
    if (flag_help) {
        cout << "Usage: " << endl;
        cout << "todo [OPTIONS]" << endl << endl;
        cout << "OPTIONS:" << endl;
        cout << "-a, --add" << "\t" << "Add task" << endl;
        cout << "-r, --remove" << "\t" << "Remove task" << endl;
        cout << "-l, --list" << "\t" << "List tasks" << endl;
        cout << "-c, --clear" << "\t" << "Clear all tasks" << endl;
        cout << "-h, --help" << "\t" << "Print helpmenu" << endl;
    }

    return 0;
}
