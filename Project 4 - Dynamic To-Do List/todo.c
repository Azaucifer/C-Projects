#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
void menuResponse(int menuChoice, Tasks **task, int *taskCounter);
void writeFile(int *taskCounter, Tasks **task);
int loadfile(Tasks **task, int *taskCounter);

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

    /* task is a pointer that stores the address of 
    the first dynamically allocated array of Tasks */
    Tasks *task = NULL;

    int taskCounter = 0;

    taskCounter = loadfile(&task, &taskCounter);

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
        getchar();

        menuResponse(menuChoice, &task, &taskCounter);
    }while(menuChoice != 6);

    
    return 0;
}




/* PROGRAM FUNCTIONS ARE DEFINED HERE */

// 1. function to respond to user's menu choice
void menuResponse(int menuChoice, Tasks **task, int *taskCounter)
{
    switch(menuChoice)
    {
        case 1:
            printf("\nAdd Task selected\n");

            // adding memory to store first task
            if(*taskCounter == 0)
            {
                if((*task) == NULL)
                {
                    (*task) = malloc(sizeof(Tasks));
                    if((*task) == NULL)
                    {
                        printf("Memory cannot be allocated to the first task\n");
                        return;
                    }
                }
            }
            // increasing the memory dynamically by using realloc
            else
            {
                if((*task) != NULL)
                {
                    (*task) = realloc((*task), (*taskCounter + 1) * sizeof(Tasks));
                    if((*task) == NULL)
                    {
                        printf("Memory couldn't be reallocated to the tasks\n");
                        return;
                    }
                }
            }


            // storing a temporary description to get the length to allocate memory accordingly
            char tempDescription[256] = "";
            do
            {
                printf("Enter Description: ");
                fgets(tempDescription, sizeof(tempDescription), stdin);
                tempDescription[strlen(tempDescription) - 1] = '\0';
            }while(strlen(tempDescription) == 0);

            int lenDescription = strlen(tempDescription);
            //printf("Length of description: %d\n", lenDescription);

            // allocating dynamic memory to store the description
            (*task)[*taskCounter].description = malloc((lenDescription + 1) * sizeof(char));
            if((*task)[*taskCounter].description == NULL)
            {
                printf("Memory cannot be allocated\n");
                return;
            }

            // copying and pasting description 
            strcpy((*task)[*taskCounter].description, tempDescription);

            (*task)[*taskCounter].id = (*taskCounter) + 1;
            (*task)[*taskCounter].status = 0;

            printf("ID: %d\nDescription: %s\nStatus: %d\n", 
                (*task)[*taskCounter].id, (*task)[*taskCounter].description, (*task)[*taskCounter].status);

            (*taskCounter)++;
            tempDescription[0] = '\0';

            writeFile(taskCounter, task);
            
            break;
        
        case 2:
            printf("\nView All Tasks selected\n");
            for(int i = 0; i < (*taskCounter); i++)
            {
                printf("ID: %d  Task: %s  Status: %d\n", 
                    (*task)[i].id, (*task)[i].description, (*task)[i].status);
            }
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
            // freeing malloc of descriptions first then the array itself
            for(int i = 0; i < (*taskCounter); i++)
            {
                free((*task)[i].description);
                (*task)[i].description = NULL;
            }
            free(*task);
            (*task) = NULL;
            break;

        default:
            printf("\nPlease enter 1 to 6 only\n");
            break;
    }
}


// 2. function to write to a file
void writeFile(int *taskCounter, Tasks **task)
{
    FILE *file = fopen("todo.txt", "w");
    if(file == NULL)
    {
        perror("File cannot be created\n");
        return;
    }
    for(int i = 0; i < (*taskCounter); i++)
    {
        fprintf(file, "%d ~ %s ~ %d\n", 
            (*task)[i].id, (*task)[i].description, (*task)[i].status);
    }
    fclose(file);
}


// 3. function to load file to read data
int loadfile(Tasks **task, int *taskCounter)
{
    FILE *file = fopen("todo.txt", "r");

    if(file == NULL)
    {
        printf("No existing todo file found. Starting fresh.\n");
        return 0;
    }

    char buffer[1024];

    while(fgets(buffer, sizeof(buffer), file) != NULL)
    {
        int id;
        int status;
        char tempDescription[256];

        // extract data from file
        if(sscanf(buffer, "%d ~ %255[^~] ~ %d", 
                  &id, tempDescription, &status) == 3)
        {

            // remove possible space before/after description
            if(tempDescription[0] == ' ')
            {
                memmove(tempDescription, tempDescription + 1, strlen(tempDescription));
            }


            // first task
            if(*taskCounter == 0)
            {
                *task = malloc(sizeof(Tasks));

                if(*task == NULL)
                {
                    printf("Memory allocation failed\n");
                    fclose(file);
                    return 0;
                }
            }

            // more tasks
            else
            {
                Tasks *temp = realloc(*task, (*taskCounter + 1) * sizeof(Tasks));

                if(temp == NULL)
                {
                    printf("Memory reallocation failed\n");
                    fclose(file);
                    return *taskCounter;
                }

                *task = temp;
            }


            // allocate memory for description
            (*task)[*taskCounter].description = malloc(strlen(tempDescription) + 1);

            if((*task)[*taskCounter].description == NULL)
            {
                printf("Description memory allocation failed\n");
                fclose(file);
                return *taskCounter;
            }


            // copy description
            strcpy((*task)[*taskCounter].description, tempDescription);


            // store remaining values
            (*task)[*taskCounter].id = id;
            (*task)[*taskCounter].status = status;


            // increase task count
            (*taskCounter)++;
        }
    }

    fclose(file);

    return (*taskCounter);
}