#include <stdio.h>

// defining struct for accounts
typedef struct
{
    int acNum;
    char name[50];
    int pin;
    float balance;
} Account;

int main()
{
    // initialising bank menu choice to 0
    int bchoice = 0;

    // initialising user menu choice to 0
    int uchoice = 0;

    // creating an array for bank accounts
    Account account[] = {0};

    // printing dashboard menu atleast once for user input
    do
    {
        // printing dashboard menu
        printf("\n====== BANK ATM SYSTEM ======\n");
        printf("1. Create Account\n"
           "2. Login\n"
           "3. Save & Exit\n"
           "\nEnter your choice: ");
        scanf("%d", &bchoice);
    } while(bchoice != 3);

    return 0;
}