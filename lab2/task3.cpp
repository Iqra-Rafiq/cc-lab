#include <iostream>
#include <deque>
#include <string>

// Define a Task structure
struct Task {
    std::string description;
    int priority;  // Priority: 0 for regular, 1 for high-priority

    Task(const std::string& desc, int prio) : description(desc), priority(prio) {}
};

// Task Scheduling System using a deque
class TaskScheduler {
private:
    std::deque<Task> taskQueue;

public:
    // Add a high-priority task to the front of the deque
    void addHighPriorityTask(const std::string& taskDesc) {
        Task task(taskDesc, 1);
        taskQueue.push_front(task);
        std::cout << "Added high-priority task: " << task.description << " to the front.\n";
    }

    // Add a regular task to the back of the deque
    void addRegularTask(const std::string& taskDesc) {
        Task task(taskDesc, 0);
        taskQueue.push_back(task);
        std::cout << "Added regular task: " << task.description << " to the back.\n";
    }

    // Remove a task from the front
    void removeTaskFromFront() {
        if (!taskQueue.empty()) {
            std::cout << "Removing task from front: " << taskQueue.front().description << std::endl;
            taskQueue.pop_front();
        } else {
            std::cout << "No tasks to remove from front!\n";
        }
    }

    // Remove a task from the back
    void removeTaskFromBack() {
        if (!taskQueue.empty()) {
            std::cout << "Removing task from back: " << taskQueue.back().description << std::endl;
            taskQueue.pop_back();
        } else {
            std::cout << "No tasks to remove from back!\n";
        }
    }

    // Access the task at the front
    void accessFrontTask() const {
        if (!taskQueue.empty()) {
            std::cout << "Task at the front: " << taskQueue.front().description 
                      << " (Priority: " << (taskQueue.front().priority ? "High" : "Regular") << ")\n";
        } else {
            std::cout << "No tasks at the front!\n";
        }
    }

    // Access the task at the back
    void accessBackTask() const {
        if (!taskQueue.empty()) {
            std::cout << "Task at the back: " << taskQueue.back().description 
                      << " (Priority: " << (taskQueue.back().priority ? "High" : "Regular") << ")\n";
        } else {
            std::cout << "No tasks at the back!\n";
        }
    }

    // Display all tasks
    void displayAllTasks() const {
        if (taskQueue.empty()) {
            std::cout << "No tasks in the queue!\n";
            return;
        }

        std::cout << "All tasks in the queue:\n";
        for (const Task& task : taskQueue) {
            std::cout << "- " << task.description << " (Priority: " 
                      << (task.priority ? "High" : "Regular") << ")\n";
        }
    }
};

int main() {
    TaskScheduler scheduler;

    // Add tasks
    scheduler.addRegularTask("Write report");
    scheduler.addRegularTask("Email client");
    scheduler.addHighPriorityTask("Fix critical bug");
    scheduler.addHighPriorityTask("Prepare presentation");

    // Display all tasks
    scheduler.displayAllTasks();

    // Access front and back tasks
    scheduler.accessFrontTask();
    scheduler.accessBackTask();

    // Remove tasks from front and back
    scheduler.removeTaskFromFront();
    scheduler.removeTaskFromBack();

    // Display tasks after removal
    scheduler.displayAllTasks();

    return 0;
}
