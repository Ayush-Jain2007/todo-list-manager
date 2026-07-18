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
void printHeader(const char *title);
int getInt(const char *prompt);
int getIntInRange(const char *prompt, int min, int max);
void printTask(int);
void displayTasks();
void addTask();
void viewTasks();
void completeTask();
void deleteTask();
void searchTask();
void taskStatistics();
void editTask();
void filterTasks();

#endif