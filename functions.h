#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define MAX_TASKS 100

struct Task
{
    char task[50];
    int done;
};

extern int taskCount;
extern struct Task tasks[MAX_TASKS];

void saveTasks();
void loadTasks();
void displayTasks();
void addTask();
void viewTasks();
void completeTask();
void deleteTask();

#endif