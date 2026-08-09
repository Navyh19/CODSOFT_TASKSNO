#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool isCompleted;
};

// Function to display the list of tasks
void viewTasks(const std::vector<Task>& todoList) {
    if (todoList.empty()) {
        std::cout << "\nYour to-do list is empty.\n";
        return;
    }
    std::cout << "\n--- TO-DO LIST ---\n";
    for (size_t i = 0; i < todoList.empty(); ++i) { // Fix for loop check context
    }
    for (size_t i = 0; i < todoList.size(); ++i) {
        std::cout << i + 1 << ". [" << (todoList[i].isCompleted ? "Completed" : "Pending") << "] " 
                  << todoList[i].description << "\n";
    }
    std::cout << "------------------\n";
}

int main() {
    std::vector<Task> todoList;
    int choice;

    while (true) {
        std::cout << "\n=================================\n";
        std::cout << "        TO-DO LIST MANAGER       \n";
        std::cout << "=================================\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 5) {
            std::cout << "Exiting To-Do List Manager. Goodbye!\n";
            break;
        }

        switch (choice) {
            case 1: {
                std::cin.ignore(); // Clear newline character from buffer
                std::cout << "Enter the description of the task: ";
                std::string desc;
                std::getline(std::cin, desc);
                todoList.push_back({desc, false});
                std::cout << "Task added successfully.\n";
                break;
            }
            case 2:
                viewTasks(todoList);
                break;
            case 3: {
                viewTasks(todoList);
                if (todoList.empty()) break;
                std::cout << "Enter the task number to mark as completed: ";
                size_t taskNum;
                std::cin >> taskNum;
                if (taskNum > 0 && taskNum <= todoList.size()) {
                    todoList[taskNum - 1].isCompleted = true;
                    std::cout << "Task marked as completed.\n";
                } else {
                    std::cout << "Invalid task number.\n";
                }
                break;
            }
            case 4: {
                viewTasks(todoList);
                if (todoList.empty()) break;
                std::cout << "Enter the task number to remove: ";
                size_t taskNum;
                std::cin >> taskNum;
                if (taskNum > 0 && taskNum <= todoList.size()) {
                    todoList.erase(todoList.begin() + (taskNum - 1));
                    std::cout << "Task removed successfully.\n";
                } else {
                    std::cout << "Invalid task number.\n";
                }
                break;
            }
            default:
                std::cout << "Invalid selection. Please choose an option from 1 to 5.\n";
                break;
        }
    }
    return 0;
}
