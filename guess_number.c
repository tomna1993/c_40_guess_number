#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int convert_str_int(string number_string);

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
	printf("Welcome in the guessing game!\n");
	printf("You have 5 tries to guess a number between 0 and %i. Are you ready?\n", max_rand_num_int);

	// Generate a random number 
	srand(time(NULL));
	
	int random_number_int = rand() % (max_rand_num_int + 1);

	// Debug generated random number
	printf("Random number: %i\n", random_number_int);

	// Start the game

	// Print "You win!" or "Game Over!"
}

// Convert string number to integer
int convert_str_int(string number_string)
{
	int number_int = 0;

	int power_of_ten = 1;

	for(int i = strlen(number_string); i > 0;)
	{
		i--; 

		number_int += (number_string[i] - 48) * power_of_ten;
	
		power_of_ten *= 10;
	}

	return number_int;
}