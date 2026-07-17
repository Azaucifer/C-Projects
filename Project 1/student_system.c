#include <stdio.h>
#include <string.h>

/* This is a student dashboard system, where user can add a student, 
   view all students, search for a student by ID, delete a student by ID 
   and update student's grade it stores everything in a students.csv file 
   and any user can save to it and view the data */

// defining a struct for students
typedef struct 
{
    int id;
    char name[50];
    float grade;
}Student;

// function prototypes
void menu_choice(int choice, Student student[], int *scounter);
int loadfile(Student student[]);

int main()
{
    // initialising choice to 0
    int choice = 0;

    // creating an array to store student data
    Student student[100] = {0};

    // counter to keep count of students
    int scounter = 0;

    scounter = loadfile(student);

    // display the dashboard at least once and ask for user input
    do
    {
        // printing the dashboard for user reference
        printf("\n======  STUDENT DASHBOARD ======\n"
           "1. Add a New Student\n"
           "2. View All Students\n"
           "3. Search Student by ID\n"
           "4. Delete Student by ID\n"
           "5. Update Grade by ID\n"
           "6. Save & Exit\n"
           "Please Enter your choice: ");
        scanf("%d", &choice);
        
        // calling the menu choice function
        menu_choice(choice, student, &scounter);

    }while(choice != 6);

    return 0;
}






// function for menu choice
void menu_choice(int choice, Student student[], int *scounter)
{
    switch(choice)
    {
        case 1:
            printf("\nAdd new student selected\n");
            printf("Enter ID: ");
            scanf("%d", &student[*scounter].id);
            getchar();
            printf("Enter Name: ");
            fgets(student[*scounter].name, sizeof(student[*scounter].name) , stdin);
            student[*scounter].name[strlen(student[*scounter].name) - 1] = '\0';
            printf("Enter Grade Percent: ");
            scanf("%f", &student[*scounter].grade);
            printf("\n**********************************\n");
            printf("Alert: Student added successfully!\n");
            printf("**********************************\n");
            // increasing the student counter everytime a new student is added
            (*scounter)++;

            // opens a csv to read the data in it
            FILE *ofile = fopen("students.csv", "r");

            // checking if the file pointer is NULL
            if(ofile == NULL)
            {
                perror("Error opening file");
            }

            // checking if file is empty
            fseek(ofile, 0, SEEK_END);
            long fsize = ftell(ofile);

            // if file is empty it writes the data to the file
            if(fsize == 0)
            {
                FILE *ofile = fopen("students.csv", "w");

                // checking if the file pointer is NULL
                if(ofile == NULL)
                {
                    perror("Error opening file");
                }
                // writing the data to the csv
                for(int i = 0; i < (*scounter); i++)
                {
                    // printing the student data to the csv
                    fprintf(ofile, "%d,%s,%.2f\n",
                        student[i].id, student[i].name, student[i].grade);
                }

            }
            else
            {
                // this appends to the file if it has data
                FILE *ofile = fopen("students.csv", "a");

                // checking if the file pointer is NULL
                if(ofile == NULL)
                {
                    perror("Error opening file");
                }
                // appending the data to the csv
                for(int i = 0; i < (*scounter); i++)
                {
                    // printing the student data to the csv
                    fprintf(ofile, "%d,%s,%.2f\n",
                        student[i].id, student[i].name, student[i].grade);
                }
            }

            // closing the file
            fclose(ofile);
            break;
        
        case 2:
            printf("\nView all students selected\n");
            // design plate for student database
            printf(" ID                       Name                           Grade %\n");
            printf("----- ------------------------------------------------- ---------\n");

            // reads the student array and prints the data on the terminal
            for (int i = 0; i < *scounter; i++) 
            {
                printf("-%-5d %-49s %-6.2f\n", student[i].id, student[i].name,  student[i].grade);
            }
            break;
        
        case 3:
            printf("\nSearch student by ID selected\n");

            // initialising student id
            int sid = 0;

            // asking user for ID
            printf("Enter the Student ID: ");
            scanf("%d", &sid);

            // adding a flag to print not found message
            int flag = 0;
            for(int i = 0; i < *scounter; i++)
            {
                if(sid == student[i].id)
                {
                    flag = 1;
                    printf("\n************ STUDENT DETAILS *******************\n");
                    printf("ID: %d\nName: %s\nGrade: %.2f\n", student[i].id, student[i].name, student[i].grade);
                    printf("************************************************\n");
                    break;
                }
            }
            if(flag == 0)
            {
                printf("\n************ STUDENT DETAILS *******************\n");
                printf("Student ID doesn't exist\n");
                printf("************************************************\n");
            }
            break;

        case 4:
            printf("\nDelete student by ID selected\n");
            break;

        case 5: 
            printf("\nUpdate student by ID selected\n");
            break;

        case 6:
            printf("\nSave and exit selected\n");
            printf("Data Saved and User Exited successfully!\n");
            break;

        default:
            printf("\nPlease enter 1 to 6 only\n\n");
            break;
    }
}

// function to load the data to display on the terminal
int loadfile(Student student[])
{
     // opens a csv to read the data in it
            FILE *file = fopen("students.csv", "r");

            // checking if the file pointer is NULL
            if(file == NULL)
            {
                perror("Error opening file");
            }

            // this prints data to the terminal
            char buffer[1024];
            int count = 0;
            while(fgets(buffer, sizeof(buffer), file) != NULL)
            {
                if(sscanf(buffer,"%d,%49[^,],%f", 
                    &student[count].id, &student[count].name, &student[count].grade) == 3)
                {
                    count++;
                }
            }
        
            fclose(file);
            return count;
}