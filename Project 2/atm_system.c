#include <stdio.h>
#include <string.h>

/* This program is a bank atm system, User can create an account
   Login with an auto generated ac no & 4 digit pin, Check their balance
   Deposit/Withdraw money, Transfer money to other accounts
   Logout, Save and exit,  The data is saved and loaded from a CSV */

// creating a struct for account details
typedef struct
{
    int accountnum;
    char name[50];
    int pin;
    float balance;
} Account;

// function prototypes
void bankMenu(Account account[], int bchoice, int *acounter, int *accountnum);

/* MAIN PROGRAM */

int main()
{
    // initialising accounts array to 0
    Account account[] = {0};

    // initialising bank menu choice to 0
    int bchoice = 0;

    // initialising account counter to 0
    int acounter = 0;

    // initialising account number to 1001
    int accountnum = 1001;

    // display menu to user
    do
    {
        printf("\n==== Bank Menu ====\n"
               "1. Create new Account\n"
               "2. Login\n"
               "3. Save & Exit\n"
               "Please enter a choice: ");
        scanf("%d", &bchoice);

        bankMenu(account, bchoice, &acounter, &accountnum);
    } while(bchoice != 3);

    return 0;
}




/* PROGRAM FUNCTIONS ARE DEFINED HERE */

// 1. function for menu choice
void bankMenu(Account account[], int bchoice, int *acounter, int *accountnum)
{
    switch(bchoice)
        {
            case 1:
                // asks user input to create a new account
                printf("\n==== Create Account ====\n");
                getchar();
                printf("Enter your name: ");
                fgets(account[*acounter].name, sizeof(account[*acounter].name), stdin);
                account[*acounter].name[strlen(account[*acounter].name) - 1] = '\0';
                printf("Enter PIN: ");
                scanf("%d", &account[*acounter].pin);
                account[*acounter].balance = 0.00;
                account[*acounter].accountnum = *accountnum + *acounter;
                printf("\nCongratulations!\n");
                printf("Dear %s, your account has been successfully created.\n", account[*acounter].name);
                printf("Ac No: %d\nPIN: %d\nBalance: $%d\n", 
                        account[*acounter].accountnum, account[*acounter].pin, account[*acounter].balance);
                (*acounter)++;
                break;

            case 2:
                printf("Login Selected\n");
                break;

            case 3:
                printf("Saved & Exited\n");
                break;

            default:
                printf("Please enter correct choice(1/2/3)\n");
                break;
        }
}