#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


// function prototypes
void displayHangman(int wrong);
int pickWord(int words);
void guessWord (char *pword, int len_pword);

// main program
int main()
{
    printf("\nWelcome to HANGMAN\n");
    // initialising the wordlist for the game
    char *wordList[] = {"apple", "banana", "cherry", "date", "fig", "grape", "kiwi", "lemon", "mango", 
                        "orange", "papaya", "raspberry", "strawberry", "tangerine", "vanilla"};
    
    // calculate total number of elements in the array
    int words = sizeof(wordList) / sizeof(wordList[0]);
    // printf("%d\n", words);


    // seed the random number generator with current time
    srand(time(NULL));

    // printing a random string from the wordList array
    char *pword = wordList[pickWord(words)];

    int len_pword = strlen(pword); 

    guessWord(pword,len_pword);

    // debugging to display hangman
    //int wrong = 6;
    //displayHangman(wrong);

    return 0;
}




/* FUNCTIONS USED IN THIS PROGRAM ARE DECLARED HERE*/


// 1. function to display the hangman
void displayHangman(int wrong)
{
    if(wrong == 0)
    {
        printf("\nHANGMAN 0/6\n");
        printf("   +---+\n");
        printf("   |   |\n");
        printf("       |\n");
        printf("       |\n");
        printf("       |\n");
        printf("       |\n");
        printf("=========\n");
    }
    else if(wrong == 1)
    {
        printf("\nHANGMAN 1/6\n");
        printf("   +---+\n");
        printf("   |   |\n");
        printf("   O   |\n");
        printf("       |\n");
        printf("       |\n");
        printf("       |\n");
        printf("=========\n");
    }
    else if(wrong == 2)
    {
        printf("\nHANGMAN 2/6\n");
        printf("   +---+\n");
        printf("   |   |\n");
        printf("   O   |\n");
        printf("   |   |\n");
        printf("       |\n");
        printf("       |\n");
        printf("=========\n");
    }
    else if(wrong == 3)
    {
        printf("\nHANGMAN 3/6\n");
        printf("   +---+\n");
        printf("   |   |\n");
        printf("   O   |\n");
        printf("  /|   |\n");
        printf("       |\n");
        printf("       |\n");
        printf("=========\n");
    }
    else if(wrong == 4)
    {
        printf("\nHANGMAN 4/6\n");
        printf("   +---+\n");
        printf("   |   |\n");
        printf("   O   |\n");
        printf("  /|\\  |\n");
        printf("       |\n");
        printf("       |\n");
        printf("=========\n");
    }
    else if(wrong == 5)
    {
        printf("\nHANGMAN 5/6\n");
        printf("   +---+\n");
        printf("   |   |\n");
        printf("   O   |\n");
        printf("  /|\\  |\n");
        printf("  /    |\n");
        printf("       |\n");
        printf("=========\n");
    }
    else if(wrong == 6)
    {
        printf("\nHANGMAN 6/6\n");
        printf("   +---+\n");
        printf("   |   |\n");
        printf("   O   |\n");
        printf("  /|\\  |\n");
        printf("  / \\  |\n");
        printf("       |\n");
        printf("=========\n");
        printf("\nYOU LOST\n");
        return;
    }
}


// 2. function to pick a random word from the wordlist
int pickWord(int words)
{
    // generate random index between 0 to (words - 1)
    int rand_ind = rand() % words;

    // printf("%d\n", rand_ind);
    return rand_ind;
}

// 3. function for guesses
void guessWord (char *pword, int len_pword)
{
    char guess[26] = {0};
    int wrong = 0;
    char display[50];

    int foundChar = 0;

    // initialising display[50] with underscores 
        for(int i = 0; i < (len_pword); i++)
        {
            display[i] = '_';
            //printf(" %c ", display[i]);
        }

    do
    {
        displayHangman(wrong);

        // print _ _ _ s based on the word length
        for(int i = 0; i < (len_pword); i++)
        {
            printf(" %c ", display[i]);
        }

        // initialising the last character as null
        display[len_pword] = '\0';

        // debugging
        printf("\n%s\n", pword);

        printf("Enter your guess: ");
        scanf("%s", &guess);

        // finding the location of guessed character in the string
        int guessFlag = 0;
        int final;
        for(int i = 0; i < len_pword; i++)
        {
            if(pword[i] == guess[0])
            {
                guessFlag = 1;
                //printf("Character found at %d\n", i);
                display[i] = pword[i];
                foundChar++;
            }
        }
        final = len_pword - foundChar;
        //printf("Total characters found: %d\n", foundChar);
        //printf("More %d characters left\n", final);

        if(strcmp(display, pword) == 0)
        {
            printf("\nYOU WIN\n");
            break;
        }

        if(guessFlag == 0)
        {
            printf("Character not found\n");
            wrong++;
        }
    }while(wrong < 6);

    if(wrong == 6)
        displayHangman(6);
}