# c_40_guess_number

## DESCRIPTION

In this program I implemented a simple guessing game. The user sets a range within he wants to guess the number, then he has 5 guesses to find the number. The program generates a random number between 0 and a number the user set at start.

### SPECIFICATION

- Get a range from the user as a command line argument, the number must be a positive integer number
- If the command line argument is not a number print an error message
- If the player doesn't give a command line argument print an error how to start the program
- Convert the command line argument `string` to `integer` number
- Print out the range within the player can guess
- The player can have five guesses within he must find the number, otherwise he looses
- Help the player if the number he guessed is higher or lower than the generated number
- Check if the player inputs correct type of number, if his input contains other types then a number, ask for a new guess
- When the player wins print "You win!" with green background, if looses print "Game Over!" with red background

### EXAMPLES

```bash
./guess_number 10
Guess a number between 0 and 10. Are you ready?
Your first guess: 5
The number is < then 5
Your second guess: 3
The number is < then 3
Your third guess: 1
The number is > then 1
Your fourth guess: 2
****** You win! ******

./guess_number 100
Guess a number between 0 and 10. Are you ready?
Your first guess: 50
The number is < then 50
Your second guess: 13
The number is > then 13
Your third guess: 38
The number is > then 38
Your fourth guess: 45
The number is < then 45
Your fifth guess: 40
****** Game Over! ******
```

## INSTALL LIBRARIES

The source code uses the cs50 library what you can download [HERE](https://github.com/cs50/libcs50).

To install the cs50 library follow the steps:

1. Open git bash terminal and change the current working directory to `src`:  
   > cd ./libsc50/src

2. Compile the cs50.c source into .o with:
   > gcc -c cs50.c -o cs50.o

3. Make the library archive:  
   > ar rcs libcs50.a cs50.o

4. Copy the `libcs50.a` file into your compiler's `lib` directory

5. Copy the `cs50.h` file into your compiler's `include` directory

## COMPILE AND RUN THE CODE

The code is written in C, the compiler used to generate the exe is: `gcc Rev10, Built by MSYS2 project 12.2.0`

Run the below code in terminal (git bash) to compile the source:

> gcc commandLineArgument.c -lcs50 -o ./build/commandLineArgument

To run the executable run the below code in terminal (git bash):

> ./build/commandLineArgument.exe
