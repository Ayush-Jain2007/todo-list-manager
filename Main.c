#include <stdio.h>
#include "functions.h"

int main()
{
    int choice;
    loadTasks();

    do
    {
        printf("=========================================================\n");
        printf("                 TO-DO LIST MANAGER\n");
        printf("=========================================================\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Complete Task\n");
        printf("4. Delete Task\n");
        printf("5. Search Task\n");
        printf("6. Task Statistics\n");
        printf("7. Exit\n");
        printf("---------------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addTask();
            break;

        case 2:
            viewTasks();
            break;

        case 3:
            completeTask();
            break;

        case 4:
            deleteTask();
            break;

        case 5:
            searchTask();
            break;

        case 6:
            taskStatistics();
            break;

        case 7:
            printf("Exiting...\n");
            break;

        default:
            printf("Please enter between 1 and 7.\n");
            break;
        }

    } while (choice != 7);

    return 0;
}