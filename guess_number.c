#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// define green background with white letters 
#define GREEN "\033[38;2;255;255;255m \033[48;2;19;161;14m" 

// define red background with white letters
#define RED "\033[38;2;255;255;255m \033[48;2;197;15;31m"

// define reset to clear styling and color modes 
#define RESET "\033[0m"

int convert_str_int(string number_string);
long int random_number(long int seed);
bool guess_number_game(int number_to_guess);

int main(int argc, string argv[])
{
	// Read command-line argument; if program run with a
	// single command-line argument, print error and return 1
	if(argc != 2)
	{
		printf("Usage: ./guess_number max_rand_num\n");
		return 1;
	}

	// Save command-line argument in a variable
	string max_rand_num_string = argv[1];

	// Get the command-line argument length
	int max_rand_num_string_length = strlen(max_rand_num_string);

	// Check if command-line argument characters are numbers
	for(int i = max_rand_num_string_length; i > 0;)
	{
		i--;

		if(isalpha(max_rand_num_string[i]))	
		{
			printf("The given max_rand_num is not a number!\n");
			return 1;
		}
	}

	// Convert argument from string to int, 
	// If it is equal to 0, bigger then 30000 or not a number return 1
	const int max_rand_num_int = convert_str_int(max_rand_num_string);

	// Debug convert_str_int function
	// printf("max_rand_num: %i\n", max_rand_num_int);

	// Print range to inform the user 
	printf(GREEN "Welcome in the guessing game!" RESET "\n");
	printf("You have 5 tries to guess a number between 0 and %i. Are you ready?\n", max_rand_num_int);

	// Generate rundom number with standard c library and rand() function
	// srand(time(NULL));
	// const int random_number_int = rand() % (max_rand_num_int + 1);

	// Generate random number with custom random function
	const int random_number_int = random_number(time(NULL)) % (max_rand_num_int + 1);

	// Debug generated random number
	printf("Random number: %i\n", random_number_int);

	// Start the game, guess_number_game returns true if player wins 
	bool game_result = guess_number_game(random_number_int);

	// Print "You win!" or "Game Over!"
	if(game_result)
	{
		printf(GREEN "****** You Win! ******" RESET "\n");
	}
	else
	{
		printf(RED "****** Game Over! ******" RESET "\n");
	}
}

// Convert string number to integer
int convert_str_int(string number_string)
{
	int number_int = 0;

	// To calculate power of 10; in each for cycle multiply it with 10
	int power_of_ten = 1;

	// Iterate through the string starting from the ones digit place
	for(int i = strlen(number_string); i > 0;)
	{
		i--; 

		// If subtract from '1' the 48 dec value it becomes 1
		// Then multiply it with power of ten:
		// ones place = number * 10^0
		// tens place = number * 10^1
		number_int += (number_string[i] - 48) * power_of_ten;
	
		// With each cycle calculate the ten on power of n++
		// 1st cycle = 10
		// 2nd cycle = 100
		// 3rd cycle = 1000
		power_of_ten *= 10;
	}

	return number_int;
}

// Custom random number generator
long int random_number(long int seed)
{
	seed = (seed << 13) ^ seed;
	return ((seed * (seed * seed * 15731 + 789221) + 1376312589) & 0x7fffffff); 
}

// Number guessing game function definition
bool guess_number_game(int number_to_guess)
{
	int player_number;

	for(int guess = 1; guess <= 5; guess++)
	{
		// Get input from player, it can be just an integer number 
		player_number = get_int("Input a number: ");

		if(player_number > number_to_guess)
		{
			printf("Your %i. guess is bigger!\n", guess);
		}
		else if(player_number < number_to_guess)
		{
			printf("Your %i. guess is smaller!\n", guess);
		}
		else if(player_number == number_to_guess)
		{
			return true;	
		}
	}

	return false;
}