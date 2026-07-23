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
void writeFile(Account account[], int *acounter);
void createAccount(int caseNum, Account account[], int *acounter, int *accountnum);
int loadfile(Account account[]);
void checkLogin(int caseNum, int *acounter, Account account[]);
void userMenu(int user, Account account[], int *acounter);

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
               //"4. Test: See all accounts\n"
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
                // creates a new account
                createAccount(1,account, acounter, accountnum);
                break;

            case 2:
                // login menu for user
                printf("\n+++++ LOGIN MENU +++++\n");

                // check account num and pin
                checkLogin(2, acounter, account);
                break;

            case 3:
                // saves and exits
                printf("\nGOODBYE & HAPPY BANKING :)\n");
                break;

            /** this is to view all user details and 
              * is used for temporary testing this program 
                 
            case 4:
                for (int i = 0; i < *acounter; i++)
                {
                    printf("%d, %s, %s, $%.2f\n", 
                        account[i].accountnum, account[i].name, 
                        account[i].pin, account[i].balance);
                }
                break;
                */
                    
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

    // removing any buffer so this runs smoothly
    getchar();

    printf("Enter your name: ");

    // storing the name of the user
    fgets(account[*acounter].name, sizeof(account[*acounter].name), stdin);

    // removing any extra buffer after the name
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

    // initialising balance to 0
    account[*acounter].balance = 0.00;

    // creating a new account number for the user
    account[*acounter].accountnum = *accountnum + *acounter;

    // displaying success message to the user
    printf("\n****************************** Congratulations! *******************************\n");
    printf("Dear %s, your account has been successfully created.\n", account[*acounter].name);
    printf("Ac No: %d    ***    PIN: %s    ***    Balance: $%.2f\n", 
                account[*acounter].accountnum, account[*acounter].pin, account[*acounter].balance);
    printf("*******************************************************************************\n");
    (*acounter)++;
    
    // writing data to the file
    writeFile(account, acounter);

}


// 3. function to write to a file
void writeFile(Account account[], int *acounter)
{
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


// 4. function to load file to read data
int loadfile(Account account[])
{
    FILE *file = fopen("bank.csv", "r");
    if(file == NULL)
    {
        perror("File does not exist");
        return 0;
    }

    // creating a buffer to read a line of data
    char buffer[1024];

    // stores the lines aka user data
    int count = 0;

    // checks if read data in buffer is not empty
    while(fgets(buffer, sizeof(buffer), file) != NULL)
    {
        // reads data in this format
        if(sscanf(buffer, "%d,%49[^,],%4[^,],%f", 
                &account[count].accountnum, &account[count].name, 
                &account[count].pin, &account[count].balance) == 4)
        {   
            // incrementing the lines aka users
            count++;
        }
    }
    fclose(file);
    return count;
}


// 5. function to check account num and pin
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

        // clearing the buffer if user enters more than 4 digits
        while(getchar() != '\n');

        // checks if account number is not in the series of bank account numbers
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

    // this variable will store the value of i from the for loop to compare PIN
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

    // this is for debugging
    // printf("user: %d\n", user);

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
    // TODO : use string compare to verify this!!!
    for(int i = user; i < (*acounter); i++)
    {
        // comparing the strings to see if PINs match
        if(strcmp(log_pin, account[i].pin) == 0)
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

    // logging the user to their account
    userMenu(user, account, acounter);
}


// 6. function to display menu after successful login and perform banking actions
void userMenu(int user, Account account[], int *acounter)
{
    // initialising user menu choice to 0
    int uchoice = 0;

    do
    {
        // display the account menu to user and ask for input to perform certain action
        printf("\n===== ACCOUNT MENU =====\n");
        printf("1. Check Balance\n2. Deposit\n3. Withdraw\n4. Transfer\n5. Logout\nEnter your choice: ");
        scanf("%d", &uchoice);

        // printf("Uchoice = %d\n", uchoice);

        // added switch statements to navigate the action flow
        switch(uchoice)
        {
            case 1:
                // displays the balance in the account
                printf("\n********* ACCOUNT BALANCE *********\n");
                printf("Your current balance is $%.2f", account[user].balance);
                printf("\n***********************************\n");
                break;

            case 2:
                // adds money to the account balance
                printf("\n****************** DEPOSIT WINDOW ******************\n");

                // initialising deposit to 0
                float deposit = 0.00f;
                printf("Enter amount to deposit: $");
                scanf("%f", &deposit);

                // adding the deposit to user's balance
                account[user].balance += deposit;
                printf("$%.2f has been successfully added to your account\n", deposit);
                printf("***************************************************\n");

                // writing data to the file
                writeFile(account, acounter);
                break;

            case 3:
                // withdraws money from the account balance
                printf("\n****************** WITHDRAWAL WINDOW ******************\n");

                // initialising withdraw to 0
                float withdraw = 0.00f;
                printf("Enter amount to withdraw: $");
                scanf("%f", &withdraw);

                // checks balance before deducting
                if(account[user].balance >= withdraw)
                {
                    // deducting money from account balance
                    account[user].balance -= withdraw;
                    printf("$%.2f has been withdrawn from your account\n", withdraw);
                    printf("*******************************************************\n");
                }
                else
                {
                    printf("Insufficient Funds\n");
                    printf("*******************************************************\n");
                }

                // writing data to the file
                writeFile(account, acounter);
                break;

            case 4:
                // transfers money to a different account
                printf("\n****************** TRANSFER WINDOW ******************\n");

                // initialising transfer amount and receiver account number to 0
                float amt_transfer = 0.00f;
                int receiver = 0;

                // prompt user for amount
                printf("Enter Amount to transfer: $");
                scanf("%f", &amt_transfer);

                // flag to check balance
                int bal_flag = 0;

                // check if user has sufficient balance
                if(account[user].balance >= amt_transfer)
                {
                    bal_flag = 1;
                    printf("Transfer of amount $%.2f has been initiated!\n", amt_transfer);
                }
                else
                {
                    printf("Insufficient Funds\n");
                    printf("*****************************************************\n");
                    break;
                }

                if(bal_flag == 1)
                {
                    // flag to check if receiver account exists
                    int rec_flag = 0;

                    // prompt user for account number
                    printf("Enter Receiver Account Number: ");
                    scanf("%d", &receiver);

                    // check if account number exists
                    for(int i = 0; i < (*acounter); i++)
                    {
                        if(receiver == account[i].accountnum)
                        {
                            rec_flag = 1;
                            // add amount to receiver's balance
                            account[i].balance += amt_transfer;
                            
                            // deduct amount from user
                            account[user].balance -= amt_transfer;

                            printf("Successfully transferred $%.2f to %s\n", amt_transfer, account[i].name);
                            printf("*****************************************************\n");
                        }
                    }

                    // display error if account number not found
                    if(rec_flag == 0)
                    {
                        printf("Error: Account Number: %d does not exist\n", receiver);
                        printf("*****************************************************\n");
                    }

                    // write data to the file
                    writeFile(account, acounter);
                }
                break;

            case 5:
                // logs out the user
                printf("\n======LOGGED OUT SUCCESSFULLY ======\n");
                break;

            default:
                printf("Please select 1 - 5 only\n");
                break;
        }
        
    }while(uchoice != 5);
}