#include <stdio.h>

/* This program can add, view, delete, update and search students by ID. 
   Stores them in an array of structs. Save to a .txt file   */

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

    return 0;
}