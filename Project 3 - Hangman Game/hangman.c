#include <stdio.h>

void displayHangman(int wrong);

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
