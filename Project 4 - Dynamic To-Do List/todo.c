#include <stdio.h>

/*This program is a command line to-do list,
  this doesn't have a fixed size array, users
  can set tasks to pending or completed & 
  delete all the completed tasks */

typedef struct
{
    int id;
    char *description;
    int status;
} Tasks;

int main()
{
    /*TODO: add task
            view all tasks
            mark task as complete
            delete task
            delete all completed tasks
            save to a file
            load from a file */
    
    // add task
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
               "Enter your choice: ");
        scanf("%d", &menuChoice);
    }while(menuChoice != 6);

    
    return 0;
}