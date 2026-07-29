#include <stdio.h>

/*This program is a command line to-do list,
  this doesn't have a fixed size array, users
  can set tasks to pending or completed & 
  delete all the completed tasks */

  // defining a struct for tasks
typedef struct
{
    int id;
    char *description;
    int status;
} Tasks;

// function prototypes
void menuResponse(int menuChoice);

int main()
{
    /*TODO: add task
            view all tasks
            mark task as complete
            delete task
            delete all completed tasks
            save to a file
            load from a file */
    
    // main menu
    int menuChoice = 0;

    do
    {
        printf("\n=== TO-DO LIST MENU ===\n");
        printf("1. Add Task\n"
               "2. View All Tasks\n"
               "3. Mark Task as Completed\n"
               "4. Delete Task\n"
               "5. Delete all Completed Tasks\n"
               "6. Save & Exit\n"
               "Enter your choice (Ex: 1 to 6): ");
        scanf("%d", &menuChoice);

        menuResponse(menuChoice);
    }while(menuChoice != 6);

    
    return 0;
}




/* PROGRAM FUNCTIONS ARE DEFINED HERE */

// 1. function to respond to user's menu choice
void menuResponse(int menuChoice)
{
    switch(menuChoice)
    {
        case 1:
            printf("\nAdd Task selected\n");
            break;
        
        case 2:
            printf("\nView All Tasks selected\n");
            break;

        case 3:
            printf("\nMark Task as Completed selected\n");
            break;
        
        case 4:
            printf("\nDelete Task selected\n");
            break;

        case 5:
            printf("\nDelete all Completed Tasks selected\n");
            break;
        
        case 6:
            printf("\nSave & Exit selected\n");
            break;

        default:
            printf("\nPlease enter 1 to 6 only\n");
            break;
    }
}