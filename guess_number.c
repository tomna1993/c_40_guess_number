#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

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
	int max_rand_num = convert_str_int(argv[1]);

	// Print range to inform the user 

	// Generate a random number 

	// Start the game

	// Print "You win!" or "Game Over!"
}

int convert_str_int(string number_string)
{
	int number_int = 0;

	for(int i = strlen(number_string); i > 0;)
	{
		i--; 

		number_int += number_string[i] - 48;
	}
}