#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Declarations
#define MAX_TASKS 100

struct Task
{
    char task[50];
    int done;
    int priority; // 1 = High, 2 = Medium, 3 = Low
};

extern int taskCount;
extern struct Task tasks[MAX_TASKS];

// File load and save
void loadTasks();
void saveTasks();

// Helping Functions
const char* getPriority(int);
void printHeader(const char *title);
int getInt(const char *prompt);
int getIntInRange(const char *prompt, int min, int max);
void printTask(int);
void displayTasks();
void swapTasks(int a, int b);
void sortByPriority();
void sortAlphabetically();
void sortByStatus();

// Main functions
void addTask();
void viewTasks();
void completeTask();
void deleteTask();
void searchTask();
void taskStatistics();
void editTask();
void filterTasks();
void sortTasks();

#endif