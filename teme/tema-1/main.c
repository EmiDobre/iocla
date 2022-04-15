#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include <inttypes.h>
char** AlocaMatrice(int m, int n);

int insert(void **arr, int *len, element *data)
{
	return 0;
}

int insert_at(void **arr, int *len, element *data, int index)
{
	return 0;
}

void find(void *data_block, int len, int index) 
{
	return ;
}

int delete_at(void **arr, int *len, int index)
{
	return 0;
}

/* print
*/

void imparteCuv(char* sir, char* el, char c, int* poz ) {
	int i = 0;
	while ( *(sir+i+*poz) != c ) i++;
	memcpy(el, sir+*poz, i);
	*poz = *poz+i+1;
	
}


void prelucrareT1(char* rand) {
	tip1* el = (tip1*)calloc(1, sizeof(tip1));
	el->manelist = (char*)calloc(1000, sizeof(char));
	el->pers = (char*)calloc(1000, sizeof(char));

	int poz = 0;
	imparteCuv(rand, el->manelist, ' ', &poz);
	printf("!%s!\n", el->manelist);
	
	char* nr1 = (char*)calloc(1000, sizeof(char));
	imparteCuv(rand, nr1, ' ', &poz);
	el->ban1 = atoi(nr1);
	printf("!%d!\n", el->ban1);
	
	char* nr2 = (char*)calloc(1000, sizeof(char));
	imparteCuv(rand, nr2, ' ', &poz);
	el->ban2 = atoi(nr2);
	printf("!%d!\n", el->ban2);
	

	imparteCuv(rand, el->pers, '\n', &poz);
	printf("!%s!\n", el->pers);
	
	//creez elementul cu head si lenul coresp


}

void prelucrareT2(char* rand) {
	tip2* el = (tip2*)calloc(1, sizeof(tip2));
	el->manelist = (char*)calloc(1000, sizeof(char));
	el->pers = (char*)calloc(1000, sizeof(char));

	int poz = 0;
	imparteCuv(rand, el->manelist, ' ', &poz);
	printf("!%s!\n", el->manelist);
	
	char* nr1 = (char*)calloc(1000, sizeof(char));
	imparteCuv(rand, nr1, ' ', &poz);
	el->ban1 = atoi(nr1);
	printf("!%d!\n", el->ban1);
	
	char* nr2 = (char*)calloc(1000, sizeof(char));
	imparteCuv(rand, nr2, ' ', &poz);
	el->ban2 = atoi(nr2);
	printf("!%d!\n", el->ban2);
	

	imparteCuv(rand, el->pers, '\n', &poz);
	printf("!%s!\n", el->pers);

}

void prelucrareT3(char* rand){
	tip3* el = (tip3*)calloc(1, sizeof(tip3));
	el->manelist = (char*)calloc(1000, sizeof(char));
	el->pers = (char*)calloc(1000, sizeof(char));

	int poz = 0;
	imparteCuv(rand, el->manelist, ' ', &poz);
	printf("!%s!\n", el->manelist);
	
	char* nr1 = (char*)calloc(1000, sizeof(char));
	imparteCuv(rand, nr1, ' ', &poz);
	el->ban1 = atoi(nr1);
	printf("!%d!\n", el->ban1);
	
	char* nr2 = (char*)calloc(1000, sizeof(char));
	imparteCuv(rand, nr2, ' ', &poz);
	el->ban2 = atoi(nr2);
	printf("!%d!\n", el->ban2);
	

	imparteCuv(rand, el->pers, '\n', &poz);
	printf("!%s!\n", el->pers);
}


int main() {
	//void *arr = NULL;
	//int len = 0;
	char** rand = AlocaMatrice(200, 2000);
	int i = 0;
	int tip = 0;
	
	while (   !feof (stdin) && fgets (rand[i], 1000, stdin)) {
		if ( rand[i][0] == 'i') {
			if ( rand[i][6] == ' ') {
				tip = atoi(&rand[i][7]);
				
				if ( tip == 1 ) 
					prelucrareT1(rand[i]+9);
				if ( tip == 2 ) 
					prelucrareT2(rand[i]+9);
				if ( tip == 3 ) 
					prelucrareT3(rand[i]+9);
					

			} else {
				tip = atoi(&rand[i][7]);
				//printf("comanda insert simpla tip %d\n", tip);

			}
		}

		if ( rand[i][0] == 'd' ) {
			//printf("comanda %d este DELETE\n", i);
		}

		if ( rand[i][0] == 'f' ) {
			//printf("comanda %d este find\n", i);
		}

		if ( rand[i][0] == 'p' ) {
			//printf("comanda %d este print\n", i);
		}
		//printf("Randul %d: %s \n", i, rand[i]);
		i++;
	}

	return 0;
}

char** AlocaMatrice(int m, int n){
	char** matrix = (char**)calloc(m, sizeof(char*));
	if ( matrix == NULL) return NULL;
	int i = 0, j = 0;
	for ( i = 0; i < m; i++ ) {
		for ( j = 0; j < n; j++ ) {
			matrix[i] = (char*)calloc(n, sizeof(char));
			if ( matrix[i] == NULL ) {
				free(matrix[i]);
				return NULL;
			}
		}
	}
	return matrix;
}

//dezaloc matricea la final