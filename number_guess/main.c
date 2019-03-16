#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int num;
	int smaller = 0;
	int larger = 0;
	int guess;
	
	srand(time(NULL));
	num = rand() % 201 - 100;
	printf("Enter an integer between -100 to 100");
	scanf("%d", &guess);
	
	while (num != guess) {
		if (num > guess) {
			printf("Enter a larger integer");
			smaller++;
		} else {
			printf("Enter a smaller integer");
			larger++;
		}
		scanf("%d", &guess);
	}
	
	printf("Number was %d, smaller is %d and larger is %d", num, smaller, larger);
	return 0;
}