#include <stdio.h>
#include <string.h>
#include "functions.h"

struct Task tasks[MAX_TASKS];
int taskCount = 0;

void printTask(int index)
{
    printf("%-5d ", index + 1);

    if (tasks[index].done)
        printf("[✓] Done      ");
    else
        printf("[ ] Pending   ");

    printf("%s\n", tasks[index].task);
}

void saveTasks()
{
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

void printHeader(const char *title)
{
    printf("=========================================================\n");
    printf("%30s\n", title);
    printf("=========================================================\n");

    printf("\nNo.   Status      Task\n");
    printf("---------------------------------------------------------\n");
}

int getInt(const char *prompt)
{
    int value;
    char ch;

    while (1)
    {
        printf("%s", prompt);

        if (scanf("%d", &value) == 1)
        {
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;

            return value;
        }

        printf("Invalid input! Please enter a number.\n");

        while ((ch = getchar()) != '\n' && ch != EOF)
            ;
    }
}

int getIntInRange(const char *prompt, int min, int max)
{
    int value;

    while (1)
    {
        value = getInt(prompt);

        if (value >= min && value <= max)
        {
            return value;
        }

        printf("Please enter a number between %d and %d.\n", min, max);
    }
}

void loadTasks()
{
    FILE *ptr = fopen("tasks.dat", "rb");

    if (ptr == NULL)
    {
        return;
    }

    fread(&taskCount, sizeof(taskCount), 1, ptr);
    fread(tasks, sizeof(struct Task), taskCount, ptr);

    fclose(ptr);
}

void displayTasks()
{
    printf("No.   Status      Task\n");
    printf("---------------------------------------------------------\n");
    for (int i = 0; i < taskCount; i++)
    {
        printTask(i);
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

    task_complete = getIntInRange("\nEnter task number to mark as completed (0 to cancel): ", 0, taskCount);

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

void deleteTask()
{
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

    task_delete = getIntInRange("\nEnter task number to delete (0 to cancel): ", 0, taskCount);

    if (task_delete == 0)
    {
        return;
    }

    if (task_delete < 1 || task_delete > taskCount)
    {
        printf("Invalid task number.\n");
        return;
    }

    for (int i = task_delete - 1; i < taskCount - 1; i++)
    {
        tasks[i] = tasks[i + 1];
    }
    taskCount--;
    printf("Task removed successfully.\n");

    saveTasks();
}

void searchTask()
{
    char keyword[50];
    int found = 0;

    getchar();
    printf("=========================================================\n");
    printf("                    SEARCH TASK\n");
    printf("=========================================================\n");

    printf("\nEnter keyword: ");
    fgets(keyword, 50, stdin);
    keyword[strcspn(keyword, "\n")] = '\0';

    printf("\nNo.   Status      Task\n");
    printf("---------------------------------------------------------\n");

    for (int i = 0; i < taskCount; i++)
    {
        if (strstr(tasks[i].task, keyword) != NULL)
        {
            printTask(i);
            found++;
        }
    }

    if (found == 0)
    {
        printf("No matching tasks found.\n");
    }
    else
    {
        printf("---------------------------------------------------------\n");
        printf("Found %d matching task(s).\n", found);
    }
}

void taskStatistics()
{
    int completed_tasks = 0, pending_tasks = 0;

    if (taskCount == 0)
    {
        printf("=========================================================\n");
        printf("                 TASK STATISTICS\n");
        printf("=========================================================\n");
        printf("\nNo tasks available.\n");

        printf("\nPress Enter to continue...");
        getchar();
        getchar();
        return;
    }

    printf("=========================================================\n");
    printf("                 TASK STATISTICS\n");
    printf("=========================================================\n");

    for (int i = 0; i < taskCount; i++)
    {
        if (tasks[i].done)
        {
            completed_tasks++;
        }
        else
        {
            pending_tasks++;
        }
    }
    float completion_rate = ((float)completed_tasks / taskCount) * 100.00;

    printf("\nTotal Tasks     : %d\n", taskCount);
    printf("Completed Tasks   : %d\n", completed_tasks);
    printf("Pending Tasks     : %d\n", pending_tasks);
    printf("Completion Rate   : %.2f%%\n", completion_rate);
    printf("\n=========================================================\n");
    printf("Press Enter to continue...");
    getchar();
}

void editTask()
{
    int choice;
    if (taskCount == 0)
    {
        printf("No task to edit.\n");
        return;
    }

    printf("=========================================================\n");
    printf("                    EDIT TASK\n");
    printf("=========================================================\n");

    displayTasks();

    choice = getIntInRange("Enter task number (0 to cancel):", 0, taskCount);

    if (choice == 0)
    {
        printf("Cancelling...\n");
        return;
    }

    if (choice < 1 || choice > taskCount)
    {
        printf("Invalid task number.\n");
        return;
    }

    printf("\nCurrent Task:\n%s\n", tasks[choice - 1].task);
    getchar();

    printf("\nEnter new task:\n");
    fgets(tasks[choice - 1].task, 50, stdin);

    tasks[choice - 1].task[strcspn(tasks[choice - 1].task, "\n")] = '\0';

    saveTasks();
    printf("Task updated successfully.\n");
}

void filterTasks()
{
    int choice;

    printf("=========================================================\n");
    printf("                  FILTER TASKS\n");
    printf("=========================================================\n");
    printf("\n1. All Tasks\n");
    printf("2. Pending Tasks\n");
    printf("3. Completed Tasks\n");
    printf("4. Back\n");
    printf("\n---------------------------------------------------------\n");

    choice = getIntInRange("Enter your choice: ", 1, 4);

    switch (choice)
    {
    case 1:

        if (taskCount == 0)
        {
            printf("No tasks available.\n");
            return;
        }

        printHeader("ALL TASKS");

        for (int i = 0; i < taskCount; i++)
        {
            printTask(i);
        }
        printf("---------------------------------------------------------\n");
        break;

    case 2:
    {
        int total_pending = 0;

        if (taskCount == 0)
        {
            printf("No tasks available.\n");
            return;
        }
        
        printHeader("PENDING TASKS");

        for (int i = 0; i < taskCount; i++)
        {
            if (!tasks[i].done)
            {
                printTask(i);
                total_pending++;
            }
        }
        printf("---------------------------------------------------------\n");
        if (!total_pending)
        {
            printf("No task pending.\n");
            break;
        }
        
        printf("Total Pending: %d\n", total_pending);
        break;
    }

    case 3:
    {
        int total_completed = 0;

        if (taskCount == 0)
        {
            printf("No tasks available.\n");
            return;
        }
        
        printHeader("COMPLETED TASKS");

        for (int i = 0; i < taskCount; i++)
        {
            if (tasks[i].done)
            {
                printTask(i);
                total_completed++;
            }
        }
        printf("---------------------------------------------------------\n");
        if (!total_completed)
        {
            printf("No completed task found.\n");
            break;
        }
        
        printf("Total Completed: %d\n", total_completed);
        break;
    }

    case 4:
        return;
    }
}