# 🎮 Hangman — C

A command-line **Hangman game written in C** where players try to guess a randomly selected word before the hangman is completely drawn.

Players have **6 chances** to make incorrect guesses. Correct guesses reveal the corresponding letters in the word, while incorrect guesses advance the hangman to the next stage.

The game keeps track of the player's **score** and allows them to play multiple rounds. 🏆

---

## ✨ Features

* 🎲 Randomly selects a word from a predefined word list
* 🔤 Players guess the word one letter at a time
* ❤️ Provides **6 chances** for incorrect guesses
* 🪢 Displays the hangman using ASCII art
* 👀 Reveals correctly guessed letters in their positions
* ❌ Tracks incorrect guesses
* ⚠️ Warns the player when only one chance remains
* 🏆 Keeps track of the player's score
* 🔄 Allows the player to play multiple rounds
* 🚪 Allows the player to exit after a round
* 📚 Uses a predefined list of fruit and food-related words

---

## 🕹️ How to Play

When the program starts, a random word is selected from the word list.

For example:

```text
_ _ _ _ _
```

The player enters a letter:

```text
Enter your guess: a
```

If the letter exists in the word, it is revealed:

```text
_ a _ _ _
```

If the letter is incorrect, the hangman progresses:

```text
   +---+
   |   |
   O   |
       |
       |
       |
=========
Wrong Guesses: 1/6
```

The player wins when all letters in the word have been correctly guessed. 🎉

The player loses after **6 incorrect guesses**. 💀

---

## 🪢 Hangman Stages

The game progressively draws the hangman after each incorrect guess:

```text
Stage 0    →  No mistakes
Stage 1    →  Head
Stage 2    →  Body
Stage 3    →  Left arm
Stage 4    →  Right arm
Stage 5    →  Left leg + warning
Stage 6    →  Complete hangman / Game Over
```

At stage 5, the player receives a warning:

```text
Warning: One more mistake and you lose!!!
```

---

## 🎲 Word Selection

The game contains a predefined word list:

```c id="2q7i8m"
char *wordList[] = {
    "apple", "banana", "cherry", "date", "fig",
    "grape", "kiwi", "lemon", "mango", "orange",
    "papaya", "raspberry", "strawberry", "tangerine",
    "vanilla"
};
```

The program calculates the number of available words and uses C's random number generation to select one:

```c id="bd4t7c"
int rand_ind = rand() % words;
```

The random number generator is seeded using the current system time:

```c id="cm0rpd"
srand(time(NULL));
```

This allows a different word to be selected between game runs. 🎲

---

## 🏆 Scoring System

The game maintains a running score.

Every successfully completed word increases the score by **1 point**.

Example:

```text
You guessed mango correctly!
YOU WIN
Score: 3
```

The score continues across multiple rounds during the same program session.

---

## 🔄 Game Flow

```text
        🎮 Start Game
             │
             ▼
       🎲 Pick Random Word
             │
             ▼
       Display Hidden Word
             │
             ▼
       🔤 Enter a Guess
             │
       ┌─────┴─────┐
       ▼           ▼
   ✅ Correct    ❌ Wrong
       │           │
       ▼           ▼
 Reveal Letter   Hangman +1
       │           │
       └─────┬─────┘
             ▼
      Word Completed?
        │         │
       YES        NO
        │         │
        ▼         ▼
   🏆 Win      6 Mistakes?
                  │
             ┌────┴────┐
             ▼         ▼
            YES        NO
             │         │
             ▼         └── 🔤 Guess Again
          💀 Lose
             │
             ▼
       🔄 Play Again?
```

---

## 📁 Project Structure

```text id="n0j9na"
hangman/
│
├── 🎮 hangman.c
└── 📖 README.md
```

The game does not require an external data file because the word list is stored directly in the C program.

---

## 🛠️ Technologies

* 💻 **C**
* 📚 Standard C Library
* 🎲 Random Number Generation
* 🔤 String Handling
* ⌨️ Command-Line Input
* 🪢 ASCII Art

---

## 🧠 Concepts Practiced

This project was built to practice several fundamental C programming concepts:

* 📦 Arrays
* 🔤 Character arrays and strings
* 👉 Pointers
* 🔧 Functions
* 📤 Passing pointers to functions
* 🔀 `do...while` loops
* 🔀 `if` / `else if` statements
* 🔀 `switch` statements
* 🔍 String comparison with `strcmp()`
* 📏 String length with `strlen()`
* 🎲 Random number generation with `rand()`
* ⏱️ Random seeding with `srand()` and `time()`
* 🧠 Managing game state
* 📊 Score tracking
* 🔤 Character searching
* 🪢 ASCII-based graphics

---

## 🚀 Compilation & Running

### 🔨 Compile with GCC

```bash id="lq0ah3"
gcc hangman.c -o hangman
```

### 🪟 Windows

```bash id="yzf6gk"
hangman.exe
```

### 🐧 Linux / 🍎 macOS

```bash id="ecp6y3"
./hangman
```

---

## ⚠️ Current Limitations

This is a command-line learning project and currently has some limitations:

* 🔤 The word list is hard-coded into the program
* 📝 Words are currently limited to lowercase characters
* 🔁 Previously guessed letters are not prevented from being entered again
* ❤️ There are exactly 6 incorrect guesses allowed
* ⌨️ Input validation is basic
* 📚 The game currently uses a relatively small word list
* 💾 High scores are not saved between program runs
* 🌐 There is no multiplayer functionality
* 🎯 The game only considers the first character entered as the player's guess

---

## 🔮 Future Improvements

Possible improvements include:

* 📚 Add a larger word database
* 🎯 Add categories such as Animals, Countries, Technology, and Movies
* 🔀 Randomize words without immediate repetition
* 🚫 Prevent duplicate guesses
* ❤️ Add difficulty levels with different numbers of attempts
* 🏆 Save high scores to a file
* 📊 Add statistics such as wins, losses, and accuracy
* 🎨 Improve the terminal interface
* 🔤 Support uppercase and lowercase input
* ⌨️ Improve input validation
* 🧩 Separate the word list into an external file
* 🧪 Add automated tests
* 👥 Add two-player mode

---

## 🎯 Project Purpose

This project was created as a practical exercise in **C programming, strings, arrays, functions, random number generation, and game logic**.

The goal was to build a complete command-line game rather than only practicing individual programming concepts.

The project combines user input, string manipulation, random word selection, game-state management, ASCII graphics, and scoring into one interactive application.

---

## 📚 What I Learned

Through this project, I practiced:

> 🎲 Generating random values in C
> 🔤 Working with strings and character arrays
> 👉 Passing pointers between functions
> 🔄 Building a game loop
> 🧠 Managing game state
> 🪢 Creating ASCII-based graphics
> 🔎 Searching for characters within strings
> 🏆 Implementing a scoring system
> 🔀 Controlling program flow with loops and conditions
> 🧩 Breaking a larger program into reusable functions

---

## 👨‍💻 Author

**Syed Shams Junaid**

🔗 GitHub: [Azaucifer](https://github.com/Azaucifer)

---

⭐ **If you enjoyed the game, feel free to explore the code and try to beat the high score!**
