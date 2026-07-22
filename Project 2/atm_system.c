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
    char pin[5];
    float balance;
} Account;

// function prototypes
void bankMenu(Account account[], int bchoice, int *acounter, int *accountnum);
void createAccount(int caseNum, Account account[], int *acounter, int *accountnum);

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
        printf("\n==== BANK ATM MENU ====\n"
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
                createAccount(1,account, acounter, accountnum);
                break;

            case 2:
                printf("\n+++++ LOGIN MENU +++++\n");

                // initialising login & pin to verify with data
                int ac_num = 0;
                char log_pin[5] = "";

                // asking user inputs
                printf("Enter Account Number: ");
                
                // accepting only 4 digits
                scanf("%4d", &ac_num);

                // clearing the buffer if user enters more than 4 digits
                while(getchar() != '\n');
                
                printf("Enter PIN: ");
                scanf("%4s", &log_pin);
                while(getchar() != '\n');
                printf("%d %s", ac_num, log_pin);
                
                // clearing the buffer if user enters more than 4 digits
                while(getchar() != '\n');
                break;

            case 3:
                printf("Saved & Exited\n");
                break;

            default:
                printf("Please enter correct choice(1/2/3)\n");
                break;
        }
}

// 2. function to create a new account
void createAccount(int caseNum, Account account[], int *acounter, int *accountnum)
{
    // asks user input to create a new account
    printf("\n==== CREATE ACCOUNT ====\n");
    getchar();
    printf("Enter your name: ");
    fgets(account[*acounter].name, sizeof(account[*acounter].name), stdin);
    account[*acounter].name[strlen(account[*acounter].name) - 1] = '\0';

    // setting a flag to validate pin
    int valid = 0;
    while(!valid)
    {
        printf("Enter a 4-digit PIN(0000 - 9999): ");

        // accepts only 4 numerical digits 
        scanf("%4s", &account[*acounter].pin);

        // clears any extra buffer characters
        while(getchar() != '\n'); 
        
        // checks the length of pin
        if(strlen(account[*acounter].pin) != 4)
        {
            printf("Just enter a 4-digit PIN(for example: 0000 - 9999): ");
            continue;
        }

        valid = 1;

        // checking if the 4 digits are numerical
        for(int i = 0; i < 4; i++)
        {
            if(account[*acounter].pin[i] < '0' || account[*acounter].pin[i] > '9')
            {
                valid = 0;
                break;
            }
            
        }

        // printing and error message to inform the user
        if(!valid)
        {
            printf("\nInvalid Input! Only numbers from 0000 to 9999 are allowed!\n");
        }
        
    }
    account[*acounter].balance = 0.00;
    account[*acounter].accountnum = *accountnum + *acounter;
    printf("\n****************************** Congratulations! *******************************\n");
    printf("Dear %s, your account has been successfully created.\n", account[*acounter].name);
    printf("Ac No: %d    ***    PIN: %s    ***    Balance: $%.2f\n", 
                account[*acounter].accountnum, account[*acounter].pin, account[*acounter].balance);
    printf("*******************************************************************************\n");
    (*acounter)++;

    // opening a file to store data
    FILE *file = fopen("bank.csv", "w");
    if(file == NULL)
    {
        perror("File cannot be created");
        return;
    }
    for(int i = 0; i < (*acounter); i++)
    {
        fprintf(file, "%d,%s,%s,%.2f\n", 
                    account[i].accountnum, account[i].name,
                    account[i].pin, account[i].balance);
    }
    fclose(file);
}