#include <stdio.h>
#include <string.h>
#include "functions.h"

struct Task tasks[MAX_TASKS];
int taskCount = 0;

void saveTasks(){
    FILE *ptr = fopen("tasks.dat", "wb");
    
    if (ptr == NULL)
    {
        printf("Error saving tasks.\n");
        return;
    }

    fwrite(&taskCount, sizeof(taskCount), 1, ptr);
    fwrite(tasks, sizeof(struct Task), taskCount, ptr);

    fclose(ptr);
}


void loadTasks(){
    FILE *ptr = fopen("tasks.dat", "rb");

    if (ptr == NULL)
    {
        return;
    }

    fread(&taskCount, sizeof(taskCount), 1, ptr);
    fread(tasks, sizeof(struct Task), taskCount, ptr);

    fclose(ptr);
}

void displayTasks(){
    printf("No.   Status      Task\n");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < taskCount; i++)
    {
        if (tasks[i].done == 0)
        {
            printf("%-5d [ ] pending   %s\n", i + 1, tasks[i].task);
        }
        else
        {
            printf("%-5d [✓] Done      %s\n", i + 1, tasks[i].task);
        }
    }
    printf("---------------------------------------------------------\n");
}

void addTask()
{
    if (taskCount >= MAX_TASKS)
    {
        printf("Your Task List is full.\n");
        return;
    }

    getchar();

    printf("Enter a Task: ");
    fgets(tasks[taskCount].task, 50, stdin);

    tasks[taskCount].task[strcspn(tasks[taskCount].task, "\n")] = '\0';

    tasks[taskCount].done = 0;

    taskCount++;

    saveTasks();

    printf("Task added successfully!\n");
}


void viewTasks()
{
    if (taskCount == 0)
    {
        printf("No tasks to do.\n");
        return;
    }
    printf("=========================================================\n");
    printf("                    YOUR TASKS\n");
    printf("=========================================================\n\n");
    
    displayTasks();

    printf("Total Tasks: %d\n\n", taskCount);
    printf("Press Enter to continue...");
    getchar();
    getchar();
}


void completeTask()
{
    int task_complete;
    if (taskCount == 0)
    {
        printf("No tasks available.\n");
        return;
    }
    printf("=========================================================\n");
    printf("                 COMPLETE A TASK\n");
    printf("=========================================================\n");
    
    displayTasks();

    printf("\nEnter task number to mark as completed (0 to cancel): ");
    scanf("%d", &task_complete);

    if (task_complete < 1 || task_complete > taskCount)
    {
        printf("Invalid task number.\n");
        return;
    }

    if (task_complete == 0)
    {
        return;
    }
    else
    {
        tasks[task_complete - 1].done = 1;

        saveTasks();

        printf("Task list updated successfully.\n");
        return;
    }
}

void deleteTask(){
    int task_delete;

    if (taskCount == 0)
    {
        printf("No tasks available.\n");
        return;
    }

    printf("=========================================================\n");
    printf("                  DELETE A TASK\n");
    printf("=========================================================\n\n");

    displayTasks();

    printf("\nEnter task number to delete (0 to cancel): ");
    scanf("%d", &task_delete);

    if (task_delete == 0)
    {
        return;
    }

    if (task_delete < 1 || task_delete > taskCount)
    {
        printf("Invalid task number.\n");
        return;
    }

    for (int i = task_delete-1; i < taskCount-1; i++)
    {
        tasks[i] = tasks[i+1];
    }
    taskCount--;
    printf("Task removed successfully.\n");
    
    saveTasks();
}