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
void loadFile(Tasks **task, int *taskCounter);
void freeTasks(Tasks **task, int *taskCounter);
void addTask(Tasks **task, int *taskCounter);
void viewTasks(Tasks **task, int *taskCounter);
void markCompleted(Tasks **task, int *taskCounter);
void markIncomplete(Tasks **task, int *taskCounter);
void deleteTask(Tasks **task, int *taskCounter);

int main()
{
    /*TODO: mark task as complete
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

    loadFile(&task, &taskCounter);

    do
    {
        printf("\n=== TO-DO LIST MENU ===\n");
        printf("1. Add Task\n"
               "2. View All Tasks\n"
               "3. Mark Task as Completed\n"
               "4. Mark Task as Incomplete\n"
               "5. Delete Task\n"
               "6. Delete all Completed Tasks\n"
               "7. Save & Exit\n"
               "Enter your choice (Ex: 1 to 7): ");
        if(scanf("%d",&menuChoice)!=1)
        {
            while(getchar()!='\n');
            continue;
        }
        getchar();

        menuResponse(menuChoice, &task, &taskCounter);
    }while(menuChoice != 7);

    
    return 0;
}




/* PROGRAM FUNCTIONS ARE DEFINED HERE */

// 1. function to respond to user's menu choice
void menuResponse(int menuChoice, Tasks **task, int *taskCounter)
{
    switch(menuChoice)
    {
        case 1:
            printf("\n=== ADD TASK ===\n");

            addTask(task, taskCounter);
            writeFile(taskCounter, task);
            
            break;
        
        case 2:
            printf("\n=== VIEW ALL TASKS ===\n");
            
            viewTasks(task, taskCounter);

            break;

        case 3:
            printf("\n=== MARK TASK AS COMPLETED ===\n");

            markCompleted(task, taskCounter);
            writeFile(taskCounter, task);

            break;

        case 4:
            printf("\n=== MARK TASK AS INCOMPLETE ===\n");

            // if user marks a task as completed by mistake then this feature helps to undo it
            markIncomplete(task, taskCounter);
            writeFile(taskCounter, task);

            break;
        
        case 5:
            printf("\n===DELETE TASK ===\n");

            deleteTask(task,taskCounter);
            
            break;

        case 6:
            printf("\nDelete all Completed Tasks selected\n");
            break;
        
        case 7:
            printf("\nSave & Exit selected\n");
            freeTasks(task, taskCounter);
            break;

        default:
            printf("\nPlease enter 1 to 7 only\n");
            break;
    }
}


// 2. function to free all dynamically allocated memory
void freeTasks(Tasks **task, int *taskCounter)
{
    // free every task description
    for(int i = 0; i < *taskCounter; i++)
    {
        free((*task)[i].description);
        (*task)[i].description = NULL;
    }

    // free the task array
    free(*task);

    // reset pointer and counter
    *task = NULL;
    *taskCounter = 0;
}

// 3. function to write to a file
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
        fprintf(file, "%d~%s~%d\n", 
            (*task)[i].id, (*task)[i].description, (*task)[i].status);
    }
    fclose(file);
}


// 4. function to load tasks from file
void loadFile(Tasks **task, int *taskCounter)
{
    FILE *file = fopen("todo.txt", "r");

    if(file == NULL)
    {
        printf("No existing todo file found. Starting fresh.\n");
        return;
    }

    char buffer[1024];

    while(fgets(buffer, sizeof(buffer), file) != NULL)
    {
        int id;
        int status;
        char tempDescription[256];


        // extract data from file
        if(sscanf(buffer, "%d~%255[^~]~%d",
                  &id,
                  tempDescription,
                  &status) == 3)
        {

            // allocate memory for first task
            if(*taskCounter == 0)
            {
                *task = malloc(sizeof(Tasks));

                if(*task == NULL)
                {
                    printf("Memory allocation failed\n");
                    fclose(file);
                    return;
                }
            }

            // increase array size for next tasks
            else
            {
                Tasks *temp = realloc(
                    *task,
                    (*taskCounter + 1) * sizeof(Tasks)
                );


                if(temp == NULL)
                {
                    printf("Memory reallocation failed\n");

                    fclose(file);
                    return;
                }


                *task = temp;
            }


            // allocate memory for description
            (*task)[*taskCounter].description = malloc(strlen(tempDescription) + 1);


            if((*task)[*taskCounter].description == NULL)
            {
                printf("Description memory allocation failed\n");


                // cleanup previous memory
                for(int i = 0; i < *taskCounter; i++)
                {
                    free((*task)[i].description);
                }


                free(*task);
                *task = NULL;
                *taskCounter = 0;


                fclose(file);
                return;
            }


            // copy description into allocated memory
            strcpy(
                (*task)[*taskCounter].description,
                tempDescription
            );


            // store remaining data
            (*task)[*taskCounter].id = id;

            (*task)[*taskCounter].status = status;


            // increase number of tasks
            (*taskCounter)++;
        }
    }


    fclose(file);
}

void addTask(Tasks **task, int *taskCounter)
{
    // adding memory to store first task
    if(*taskCounter == 0)
    {
        Tasks *temp = malloc(sizeof(Tasks));

        if(temp == NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }

        *task = temp;
    }
    // increasing the memory dynamically by using realloc
    else
    {
        Tasks *temp = realloc((*task), (*taskCounter + 1) * sizeof(Tasks));

        if(temp == NULL)
        {
            printf("Memory couldn't be reallocated to the tasks\n");
            return;
        }

        *task = temp;
    }


    // storing a temporary description to get the length to allocate memory accordingly
    char tempDescription[256] = "";
    do
    {
        printf("Enter Description: ");
        if(fgets(tempDescription, sizeof(tempDescription), stdin))
        {
            tempDescription[strcspn(tempDescription, "\n")] = '\0';
        }
    }while(strlen(tempDescription) == 0);

    int lenDescription = strlen(tempDescription);
    //printf("Length of description: %d\n", lenDescription);

    // allocating dynamic memory to store the description
    (*task)[*taskCounter].description = malloc(lenDescription + 1);
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
}

void viewTasks(Tasks **task, int *taskCounter)
{
    printf("(Note: Status: 0 = Pending & Status: 1 = Completed)\n");

    if(*taskCounter==0)
    {
        printf("No tasks available\n");
        return;
    }

    for(int i = 0; i < (*taskCounter); i++)
    {
        printf("ID: %d\nTask: %s\nStatus: %d\n\n", 
            (*task)[i].id, (*task)[i].description, (*task)[i].status);
    }
}

void markCompleted(Tasks **task, int *taskCounter)
{
    int taskID = 0;
    printf("Enter task ID: ");
    scanf("%d", &taskID);

    int taskFlag = 0;
    for(int i = 0; i < (*taskCounter); i++)
    {
        if(taskID == (*task)[i].id)
        {
            taskFlag = 1;
            printf("Alert: Task %d marked as completed!\n", (*task)[i].id);
            (*task)[i].status = 1;
        }
    }

    if(!taskFlag)
    {
        printf("No Task found\n");
    }
}

void markIncomplete(Tasks **task, int *taskCounter)
{
    int taskID = 0;
    printf("Enter task ID: ");
    scanf("%d", &taskID);

    int taskFlag = 0;
    for(int i = 0; i < (*taskCounter); i++)
    {
        if(taskID == (*task)[i].id)
        {
            taskFlag = 1;
            printf("Alert: Task %d marked as incomplete!\n", (*task)[i].id);
            (*task)[i].status = 0;
        }
    }

    if(!taskFlag)
    {
        printf("No Task found\n");
    }
}

void deleteTask(Tasks **task, int *taskCounter)
{
    int taskID = 0;
    printf("Enter task ID: ");
    scanf("%d", &taskID);
    int taskFlag = 0;

    for(int i = 0; i < (*taskCounter); i++)
    {
        if(taskID == (*task)[i].id)
        {
            taskFlag = 1;
            printf("Deleted Task %d: %s\n", (*task)[i].id, (*task)[i].description);

            for(int j = i; j < (*taskCounter); j++)
            {
                (*task)[j] = (*task)[j + 1];
                (*task)[j].id -= 1;
            }

            (*taskCounter)--;

            writeFile(taskCounter, task);
        }
    }

    if(!taskFlag)
    {
        printf("Task %d does not exist.\n", taskID);
    }
}