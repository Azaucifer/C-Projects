#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


// function prototypes
int displayHangman(int *game, int wrong, int *score, char *pword);
int pickWord(int words);
void guessWord (char *pword, int len_pword, int *score, int *game);

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

    int score = 0;

    int game = 0;

    do
    {
        // printing a random string from the wordList array
        char *pword = wordList[pickWord(words)];
        int len_pword = strlen(pword);
        guessWord(pword,len_pword, &score, &game);

    }while(game != 1);

    return 0;
}




/* FUNCTIONS USED IN THIS PROGRAM ARE DECLARED HERE*/


// 1. function to display the hangman
int displayHangman(int *game, int wrong, int *score, char *pword)
{
    if(wrong == 0)
    {
        printf("   +---+\n");
        printf("   |   |\n");
        printf("       |\n");
        printf("       |\n");
        printf("       |\n");
        printf("       |\n");
        printf("=========\n");
        printf("Wrong Guesses: 0/6\n");
    }
    else if(wrong == 1)
    {
        printf("   +---+\n");
        printf("   |   |\n");
        printf("   O   |\n");
        printf("       |\n");
        printf("       |\n");
        printf("       |\n");
        printf("=========\n");
        printf("Wrong Guesses: 1/6\n");
    }
    else if(wrong == 2)
    {
        printf("   +---+\n");
        printf("   |   |\n");
        printf("   O   |\n");
        printf("   |   |\n");
        printf("       |\n");
        printf("       |\n");
        printf("=========\n");
        printf("Wrong Guesses: 2/6\n");
    }
    else if(wrong == 3)
    {
        printf("   +---+\n");
        printf("   |   |\n");
        printf("   O   |\n");
        printf("  /|   |\n");
        printf("       |\n");
        printf("       |\n");
        printf("=========\n");
        printf("Wrong Guesses: 3/6\n");
    }
    else if(wrong == 4)
    {
        printf("   +---+\n");
        printf("   |   |\n");
        printf("   O   |\n");
        printf("  /|\\  |\n");
        printf("       |\n");
        printf("       |\n");
        printf("=========\n");
        printf("Wrong Guesses: 4/6\n");
    }
    else if(wrong == 5)
    {
        printf("   +---+\n");
        printf("   |   |\n");
        printf("   O   |\n");
        printf("  /|\\  |\n");
        printf("  /    |\n");
        printf("       |\n");
        printf("=========\n");
        printf("Wrong Guesses: 5/6\n");
        printf("Warning: One more mistake and you lose!!!\n");
    }
    else if(wrong == 6)
    {
        printf("AAAAAGGHHHH!\n");
        printf("   +---+\n");
        printf("   |   |\n");
        printf("   O   |\n");
        printf("  /|\\  |\n");
        printf("  / \\  |\n");
        printf("       |\n");
        printf("=========\n");
        printf("Score: %d\n", *score);
        printf("OH NOO!!! YOU LOST!!!\n");
        printf("The word was %s\n", pword);
        printf("Note: 0 = YES!   1 = NO!\n");
        printf("Do you want to play again?: ");
        scanf("%d", game);
        return *game;
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
void guessWord (char *pword, int len_pword, int *score, int *game)
{
    char guess[26] = {0};
    char guessed[26] = {0};
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
        displayHangman(game, wrong, score, pword);

        // print _ _ _ s based on the word length
        for(int i = 0; i < (len_pword); i++)
        {
            printf("%c ", display[i]);
        }

        // initialising the last character as null
        display[len_pword] = '\0';

        // debugging
        //printf("\n%s\n", pword);

        printf("\nScore: %d\n", *score);

        printf("Guessed Letters: %s\n", guessed);

        printf("Enter your guess: ");
        scanf("%s", &guess);

        // adding current guess to the guessed array
        guessed[strlen(guessed)] = guess[0];

        printf("\n");

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
            printf("You guessed %s correctly!\n", pword);
            printf("YOU WIN\n");
            (*score)++;
            printf("Score: %d\n", *score);
            printf("Note: 0 = YES!   1 = NO!\n");
            printf("Do you want to play again?: ");
            scanf("%d", game);
            break;
        }

        if(guessFlag == 0)
        {
            //printf("Character not found\n");
            wrong++;
        }
    }while(wrong < 6);

    if(wrong == 6)
        displayHangman(game, 6, score, pword);
}