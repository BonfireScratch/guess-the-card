# include <stdio.h>

void create_board(int pin[][4]) {
	int i;
	int j;
	int randnum;
	int auxpin[8]={0,0,0,0,0,0,0,0};	

	for (i=0; i<4; i++){
		printf("\n");
		for (j=0; j<4; j++) {
			randnum = (rand()%8+1);
			while (auxpin[randnum-1] >= 2) {
				randnum = (rand()%8+1);
			}
			auxpin[randnum-1]++;
			printf("%d", randnum);
			pin[i][j] = randnum;
		}
	}	
}

void show_board(int pin[][4]) {
	int i=0;
	int j=0;
	for (i=0; i<4; i++) {
		printf("\n");
		for (j=0; j<4; j++) {
			printf("%d", pin[i][j]);
		}
	}	
}
 
int main()
{
	int x=4;
	int y=4;
	int table[x][y];
	create_board(table);
	printf("\n");
	show_board(table);
	return 0;
}
