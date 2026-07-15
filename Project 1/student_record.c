#include <stdio.h>
#include <string.h>

/* This program can add, view, delete, update and search students by ID. 
   Stores them in an array of structs. Save to a .txt file   */

// creating a Student struct
typedef struct
{
    int id;
    char name[50];
    float grade;
}Student;

int main()
{
    int choice = 0;

    // creating an array for students
    Student students[100] = {0};
    // counter for students
    int student_count = 0;

    // using switch to run the user choice
    do
    {
        // print the display text
        // ask for user input
        printf("---STUDENT RECORD SYSTEM---\n"
        "1. Add Student\n"
        "2. View All Students\n"
        "3. Delete Student\n"
        "4. Update Student\n"
        "5. Search Student\n"
        "6. Save & Exit\n"
        "Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                // asking user for input
                printf("\nPlease Add Student Details\n");
                printf("Student ID: ");
                scanf("%d", &students[student_count].id);
                getchar();

                printf("Enter the name: ");
                fgets(students[student_count].name, sizeof(students[student_count].name), stdin);
                students[student_count].name[strcspn(students[student_count].name, "\n")] = '\0';

                printf("Enter your grade percent: ");
                scanf("%f", &students[student_count].grade);
                student_count++;
                printf("Student added successfully\n");
                break;

            case 2:
                printf("\nYou chose to view all students\n");
                break;
        
            case 3:
                printf("\nYou chose to delete student\n");
                break;

            case 4:
                printf("\nYou chose to update student\n");
                break;

            case 5:
                printf("\nYou chose search student\n");
                break;

            case 6:
                printf("\nYou chose to save and exit\n");
                break;

            default:
                printf("\nPlease type 1 - 6 only\n");
                break;
        }
    }while(choice < 1 || choice > 6);

    printf("%d %s %.2f", students[0].id, students[0].name, students[0].grade);

    return 0;
}