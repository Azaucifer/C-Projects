#include <ctype.h>
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
int loadfile(Account account[]);
void checkLogin(int caseNum, int *acounter, Account account[]);

/* MAIN PROGRAM */

int main()
{
    // initialising accounts array to 0
    Account account[] = {0};

    // initialising bank menu choice to 0
    int bchoice = 0;

    // initialising account counter to 0
    int acounter = 0;

    acounter = loadfile(account);

    // initialising account number to 1001
    int accountnum = 1001;

    // display menu to user
    do
    {
        printf("\n==== BANK ATM MENU ====\n"
               "1. Create new Account\n"
               "2. Login\n"
               "3. Save & Exit\n"
               "4. Test: See all accounts\n"
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

                // check account num and pin
                checkLogin(2, acounter, account);
                break;

            case 3:
                printf("Saved & Exited\n");
                break;

            case 4:
                for (int i = 0; i < *acounter; i++)
                {
                    printf("%d, %s, %s, $%.2f\n", 
                        account[i].accountnum, account[i].name, 
                        account[i].pin, account[i].balance);
                }
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

// 3. function to load file to read data
int loadfile(Account account[])
{
    FILE *file = fopen("bank.csv", "r");
    if(file == NULL)
    {
        perror("File does not exist");
        return 0;
    }
    char buffer[1024];
    int count = 0;
    while(fgets(buffer, sizeof(buffer), file) != NULL)
    {
        if(sscanf(buffer, "%d,%49[^,],%4[^,],%f", 
                &account[count].accountnum, &account[count].name, 
                &account[count].pin, &account[count].balance) == 4)
        {
            count++;
        }
    }
    fclose(file);
    return count;
}


// 4. function to check account num and pin
void checkLogin(int caseNum, int *acounter, Account account[])
{
    // initialising login & pin to verify with data
    int ac_num = 0;
    char log_pin[5] = "";

    // setting a flag to check account number
    int ac_numCheck = 0;
    while(!ac_numCheck)
    {
        // asking user inputs
        printf("Enter Account Number: ");
                
        // accepting only 4 digits
        scanf("%4d", &ac_num);

        /* TODO: check if acc num exists in database */

        // clearing the buffer if user enters more than 4 digits
        while(getchar() != '\n');

        if(ac_num < 1001)
        {
            printf("Error: Account Number not valid!\n");
        }
        else
        {
            ac_numCheck = 1;
        }
    }
    
    // setting a flag to check if account num exists in data
    int ac_numFlag = 0;

    // this stores the value of i from the for loop to compare PIN
    int user = 0;

    for(int i = 0; i < (*acounter); i++)
    {
        if(ac_num == account[i].accountnum)
        {
            ac_numFlag = 1;
            printf("Welcome %s\n", account[i].name);
            user = i;
        }
    }

    printf("%d", user);
    if(ac_numFlag == 0)
    {
        printf("Account Number does not exist!\n");
        return;
    }

    // checking if the PIN is in correct format
    int pin_check = 0;
    while(!pin_check)
    {
        printf("Enter PIN: ");
        scanf("%4s", &log_pin);

        // clearing the buffer if user enters more than 4 digits
        while(getchar() != '\n');

        // checking if PIN is in numerical format
        for(int i = 0; i < 4; i++)
        {
            if(isdigit(log_pin[i]))
            {
                pin_check = 1;
                continue;
            }
            else
            {
                pin_check = 0;
                printf("Error: Wrong PIN\n");
                break;
            }
        }
    }

    // checking if entered PIN matches the account's PIN
    int log_pinFlag = 0;

    // using user variable to confirm PIN match
    for(int i = user; i <= (*acounter); i++)
    {
        if(log_pin[i] == account[i].pin)
        {
            log_pinFlag = 1;
            printf("Logged in successfully\n");
        }
    }
    if(log_pinFlag == 0)
    {
        printf("Error: Wrong PIN entered\n");
        return;
    }

}