#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>

void create_board(int pin[][4]) {
	int i;
	int j;
	int randnum;
	int auxpin[8] = {0,0,0,0,0,0,0,0};	

	for (i=0; i<4; i++){
		for (j=0; j<4; j++) {
			randnum = (rand() % 8 + 1);
			while (auxpin[randnum-1] >= 2) {
				randnum = (rand() %8 + 1);
			}
			auxpin[randnum - 1]++;
			pin[i][j] = randnum;
		}
	}	
}

// Itaterate in the random number table to display the numbers
void show_board(char table[][4]) {
	int x=0;
	int y=0;
	for (x=0; x<4; x++){
		for (y=0; y<4; y++){
			printf("%c", table[x][y]);
		}
		printf("\n");
	}
	printf("\n");
}

void select_pair(int pin[][4], char tablechar[][4], int *correct) {
	int correctcout = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	int x = 0;
	int y = 0;
	bool exitnow = false;
	while (correctcout <= 16 && exitnow == false) {
		printf("Select the first pair (eg: 1 2 or 9 9 to exit): ");
		scanf("%d %d",&i,&j);
		if (i == 9 && j == 9) {
			exitnow = true;
		} else {
			printf("Select the second pair: ");
			scanf("%d%d",&k,&l);
			if (pin[i][j] == pin[k][l]) {
				tablechar[i][j] = pin[i][j] + '0';
				tablechar[k][l] = pin[i][j] + '0';
				system("cls");
				printf("Correct!\n");
				correctcout++;
				show_board(tablechar);
			} else {
				printf("Wrong answer\n");
			}
			*correct = correctcout;
		}
	}
}
 
int main() {
	srand(time(NULL));
	int x = 4;
	int y = 4;
	int k = 4;
	int l = 4;
	int correct = 0;
	int table[x][y];  // Create the table for the random number
	char tablechar[x][y]; // Create a "blank" table to store the correct values
	for (k=0; k<4; k++){
		for (l=0; l<4; l++){
			tablechar[k][l]='_';
			printf("_");
		}
		printf("\n");
	}
	printf("\n");
	create_board(table);
	select_pair(table, tablechar, &correct); 
	if (correct == 16) {
		printf ("You won!");
	} else {
		printf ("You exited the game with %d correct answers", correct);
	}
	return 0;
}
