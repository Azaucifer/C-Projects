#include <stdio.h>

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

    // print the display text
    // ask for user input
    int choice = 0;
    printf("---STUDENT RECORD SYSTEM---\n"
        "1. Add Student\n"
        "2. View All Students\n"
        "3. Delete Student\n"
        "4. Update Student\n"
        "5. Search Student\n"
        "6. Save & Exit\n"
        "Enter your choice: ");
    scanf("%d", &choice);

    // creating an array for students
    Student students[100] = {0};
    // counter for students
    int student_count = 0;

    // using switch to run the user choice
    switch(choice)
    {
        case 1:
            printf("You chose add student\n");
            break;

        case 2:
            printf("You chose to view all students\n");
            break;
        
        case 3:
            printf("You chose to delete student\n");
            break;

        case 4:
            printf("You chose to update student\n");
            break;

        case 5:
            printf("You chose search student\n");
            break;

        case 6:
            printf("You chose to save and exit\n");
            break;

        default:
            printf("Please type 1 - 6 only\n");
            break;
    }

    return 0;
}