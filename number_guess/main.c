#include <stdio.h>
#include <stdlib.h> 

int main() {
	srand(time(NULL));
	
	int guess = 0;
	int larger = 0;
	int smaller = 0;
	int num = (rand() % 201 - 100);
	printf("%d\n", num);
	printf("Enter an integer > ");
	scanf("%d", &guess);
	
	
	while (guess != num) {
		if (num < guess) {
			printf("Too small\n");
			larger++;
		} else {
			printf("Too big\n");
			smaller++;
		}
		printf("Enter an integer > ");
		scanf("%d", &guess);
	}
	
	printf("Number %d, Larger %d, Smaller %d", num, larger, smaller);
}
