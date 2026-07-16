#include <stdio.h>
#include <string.h>

// defining a struct for students
typedef struct 
{
    int id;
    char name[50];
    float grade;
}Student;

// function prototypes
void menu_choice(int choice, Student student[], int scounter);

int main()
{
    // initialising choice to 0
    int choice = 0;

    // creating an array to store student data
    Student student[100] = {0};

    // counter to keep count of students
    int scounter = 0;

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
        menu_choice(choice, student, scounter);

    }while(choice != 6);

    // printing to test if the student data is captured
    printf("ID: %d  Name: %s  Grade: %.2f\n", student[scounter].id, student[scounter].name, student[scounter].grade);

    return 0;
}






// function for menu choice
void menu_choice(int choice, Student student[], int scounter)
{
    switch(choice)
    {
        case 1:
            printf("\nAdd new student selected\n");
            printf("Enter ID: ");
            scanf("%d", &student[scounter].id);
            getchar();
            printf("Enter Name: ");
            fgets(student[scounter].name, sizeof(student[scounter].name) , stdin);
            student[scounter].name[strlen(student[scounter].name) - 1] = '\0';
            printf("Enter Grade: ");
            scanf("%f", &student[scounter].grade);
            printf("\nAlert: Student added successfully!\n");
            break;
        
        case 2:
            printf("\nView all students selected\n");
            break;
        
        case 3:
            printf("\nSearch student by ID selected\n");
            break;

        case 4:
            printf("\nDelete student by ID selected\n");
            break;

        case 5: 
            printf("\nUpdate student by ID selected\n");
            break;

        case 6:
            printf("\nSave and exit selected\n");
            break;

        default:
            printf("\nPlease enter 1 to 6 only\n");
            break;
    }
}