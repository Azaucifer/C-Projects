#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayHangman(int wrong);
int pickWord(int words);

int main()
{
    // initialising the wordlist for the game
    char *wordList[] = {"apple", "banana", "cherry", "date", "fig", "grape", "kiwi", "lemon", "mango", 
                        "orange", "papaya", "raspberry", "strawberry", "tangerine", "vanilla"};
    
    // calculate total number of elements in the array
    int words = sizeof(wordList) / sizeof(wordList[0]);
    printf("%d\n", words);
    
    // debugging to display hangman
    int wrong = 6;
    displayHangman(wrong);

    // printing a random string from the wordList array
    printf("%s\n", wordList[pickWord(words)]);

    return 0;
}




/* FUNCTIONS USED IN THIS PROGRAM ARE DECLARED HERE*/

// 1. function to display the hangman
void displayHangman(int wrong)
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
    }
    else if(wrong == 6)
    {
        printf("   +---+\n");
        printf("   |   |\n");
        printf("   O   |\n");
        printf("  /|\\  |\n");
        printf("  / \\  |\n");
        printf("       |\n");
        printf("=========\n");
    }
}

// 2. function to pick a random word from the wordlist
int pickWord(int words)
{
    // seed the random number generator with current time
    srand(time(NULL));

    // generate random index between 0 to (words - 1)
    int rand_ind = rand() % words;

    // printf("%d\n", rand_ind);
    return rand_ind;
}