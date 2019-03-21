#include <stdio.h>
#include <stdlib.h> // Standard imports

int main() {
	srand(time(NULL)); // Resetting the random number generator
	
	int guess = 0;
	int larger = 0;
	int smaller = 0;
	int num = (rand() % 201 - 100); // Sets integer num to a number between -100 to 100
	printf("Enter an integer > "); // Asks for user input
	scanf("%d", &guess); // Gets user input
	
	while (guess != num) { // Repeats until you guess the right number
		if (num < guess) { // If your number is too small
			printf("Too small\n");
			larger++; // Increments integer number
		} else {
			printf("Too big\n"); // If number is too big
			smaller++; // Increments integer smaller
		}
		printf("Enter an integer > "); // Ask for input again
		scanf("%d", &guess);
	}
	
	printf("Number %d, Larger %d, Smaller %d", num, larger, smaller); // Outputs the number you had to guess and the integers larger and smaller
}
