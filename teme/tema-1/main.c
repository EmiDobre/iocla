#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include <inttypes.h>
char** AlocaMatrice(int m, int n);
int insert(void **arr, int *len, element *data);
int insert_at(void **arr, int *len, element *data, int index);
void find(void *arr, int len, int index);
int delete_at(void **arr, int *len, int index);
void print(void** arr, int len);
void exit_dezaloc( void** arr, int* lung);

void imparteCuv(char* sir, char* el, char c, int* poz ) {
	int i = 0;
	while ( *(sir+i+*poz) != c ) i++;
	memcpy(el, sir+*poz, i);
	*poz = *poz+i+1;	
}

void prelucrareT1(char* rand, int* len, void** arr, int index) {
	tip1* el = (tip1*)calloc(1, sizeof(tip1));
	el->manelist = (char*)calloc(1000, sizeof(char));
	el->pers = (char*)calloc(1000, sizeof(char));

	int poz = 0;
	imparteCuv(rand, el->manelist, ' ', &poz);
	
	char* nr1 = (char*)calloc(1000, sizeof(char));
	imparteCuv(rand, nr1, ' ', &poz);
	el->ban1 = atoi(nr1);
	
	char* nr2 = (char*)calloc(1000, sizeof(char));
	imparteCuv(rand, nr2, ' ', &poz);
	el->ban2 = atoi(nr2);
	
	imparteCuv(rand, el->pers, '\n', &poz);

	//creez elementul cu head si lenul coresp
	element* data = NULL;
	int dim = 2; // 2inturi pe 2 bytes
	dim = dim + strlen(el->manelist) + strlen(el->pers) + 2; //pt null terminator
	// dim= cea ocupata de campul data
	
	data = (element*)calloc(1, dim + 8);
	data->header = (head*)calloc(1, 8);
	data->data = (tip2*)calloc(1, dim);

	((head*)data->header)->type = 1;
	((head*)data->header)->len = dim + 8; //len e cat ocupa tot elementul
	((tip1*)data->data)->ban1 = el->ban1;
	((tip1*)data->data)->ban2 = el->ban2;
	((tip1*)data->data)->manelist = calloc(strlen(el->manelist)+1, sizeof(char));
	((tip1*)data->data)->pers = calloc(strlen(el->pers)+1, sizeof(char));
	memcpy(((tip1*)data->data)->manelist, el->manelist, strlen(el->manelist));
	memcpy(((tip1*)data->data)->pers, el->pers, strlen(el->pers));

	if ( index < 0 || index > *len )
	insert(arr, len, data);
	else 
	insert_at(arr, len, data, index);

	free(el->manelist);
	free(el->pers);
	free(el);
	free(nr1); free(nr2);
}

void prelucrareT2(char* rand, int* len, void** arr, int index ) {
	tip2* el = (tip2*)calloc(1, sizeof(tip2));
	el->manelist = (char*)calloc(1000, sizeof(char));
	el->pers = (char*)calloc(1000, sizeof(char));

	int poz = 0;
	imparteCuv(rand, el->manelist, ' ', &poz);
	
	char* nr1 = (char*)calloc(1000, sizeof(char));
	imparteCuv(rand, nr1, ' ', &poz);
	el->ban1 = atoi(nr1);
	
	char* nr2 = (char*)calloc(1000, sizeof(char));
	imparteCuv(rand, nr2, ' ', &poz);
	el->ban2 = atoi(nr2);
	
	imparteCuv(rand, el->pers, '\n', &poz);

	element* data = NULL;
	int dim = 6; // 2inturi pe 6 bytes
	dim = dim + strlen(el->manelist) + strlen(el->pers) + 2; //pt null terminator
	// dim= cea ocupata de campul data
	
	data = (element*)calloc(1, dim + 8);
	data->header = (head*)calloc(1, 8);
	data->data = (tip2*)calloc(1, dim);

	((head*)data->header)->type = 2;
	((head*)data->header)->len = dim + 8; //len e cat ocupa tot elementul
	((tip2*)data->data)->ban1 = el->ban1;
	((tip2*)data->data)->ban2 = el->ban2;
	((tip2*)data->data)->manelist = calloc(strlen(el->manelist)+1, sizeof(char));
	((tip2*)data->data)->pers = calloc(strlen(el->pers)+1, sizeof(char));
	memcpy(((tip2*)data->data)->manelist, el->manelist, strlen(el->manelist));
	memcpy(((tip2*)data->data)->pers, el->pers, strlen(el->pers));

	if ( index < 0 || index > *len )
	insert(arr, len, data);
	else 
	insert_at(arr, len, data, index);

	free(el->manelist);
	free(el->pers);
	free(el);
	free(nr1); free(nr2);
}

void prelucrareT3(char* rand, int* len, void** arr, int index){
	tip3* el = (tip3*)calloc(1, sizeof(tip3));
	el->manelist = (char*)calloc(1000, sizeof(char));
	el->pers = (char*)calloc(1000, sizeof(char));

	int poz = 0;
	imparteCuv(rand, el->manelist, ' ', &poz);
	
	char* nr1 = (char*)calloc(1000, sizeof(char));
	imparteCuv(rand, nr1, ' ', &poz);
	el->ban1 = atoi(nr1);
	
	char* nr2 = (char*)calloc(1000, sizeof(char));
	imparteCuv(rand, nr2, ' ', &poz);
	el->ban2 = atoi(nr2);
	
	imparteCuv(rand, el->pers, '\n', &poz);

	element* data = NULL;
	int dim = 8; // 2inturi pe 8 bytes
	dim = dim + strlen(el->manelist) + strlen(el->pers) + 2; //pt null terminator
	//de la head care are 8 octeti
	
	data = (element*)calloc(1, dim+8);
	data->header = (head*)calloc(1, 8);
	data->data = (tip3*)calloc(1, dim);

	((head*)data->header)->type = 3;
	((head*)data->header)->len = dim + 8;
	((tip3*)data->data)->ban1 = el->ban1;
	((tip3*)data->data)->ban2 = el->ban2;
	((tip3*)data->data)->manelist = calloc(strlen(el->manelist)+1, sizeof(char));
	((tip3*)data->data)->pers = calloc(strlen(el->pers)+1, sizeof(char));
	memcpy(((tip3*)data->data)->manelist, el->manelist, strlen(el->manelist));
	memcpy(((tip3*)data->data)->pers, el->pers, strlen(el->pers));

	if ( index < 0 || index > *len )
	insert(arr, len, data);
	else 
	insert_at(arr, len, data, index);

	free(el->manelist);
	free(el->pers);
	free(el);
	free(nr1); free(nr2);
}


int main() {
	void *arr = NULL;
	int len = 0;
	char** rand = AlocaMatrice(200, 2000);
	int i = 0;
	int tip = 0;
	int index = -1;
	
	while (   !feof (stdin) && fgets (rand[i], 1000, stdin)) {
		if ( rand[i][0] == 'i') {
			if ( rand[i][6] == ' ') {
				tip = atoi(&rand[i][7]);
				
				if ( tip == 1 ) 
					prelucrareT1(rand[i]+9, &len, &arr, index);
				if ( tip == 2 ) 
					prelucrareT2(rand[i]+9, &len, &arr, index);
				if ( tip == 3 ) 
					prelucrareT3(rand[i]+9, &len, &arr, index);
					

			} else {
				int j = 10, k = 0;
				char* nr = calloc(100, sizeof(char));
				while ( rand[i][j] != ' ') {
					nr[k] = rand[i][j];
					j++;
					k++;
				}
				index = atoi(nr);
				tip = atoi(&rand[i][10+k+1]);
				
				if ( tip == 1 ) 
					prelucrareT1(rand[i]+11+k+2, &len, &arr, index);
				if ( tip == 2 ) 
					prelucrareT2(rand[i]+11+k+2, &len, &arr, index);
				if ( tip == 3 ) 
					prelucrareT3(rand[i]+11+k+2, &len, &arr, index);
			}
		}

		if ( rand[i][0] == 'd' ) {
			index = atoi(&rand[i][10]);
			delete_at(&arr, &len, index);
		}

		if ( rand[i][0] == 'f' ) {
			int index = 0;
			index = atoi(&rand[i][5]);
			find(arr, len, index);
		}

		if ( rand[i][0] == 'p' ) {
			print(&arr, len);
		}

		//if ( rand[i][0] == 'e' ) {
			//exit_dezaloc(&arr, &len);
		//}
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

//functiile efective:
int insert(void **arr, int *len, element *data) {
	
	static int nr_bytes = 0;
	if ( *len == 0 ) {
		*arr = calloc(1,data->header->len);
		if ( *arr == NULL ) return 1;
		memcpy(*arr, data, data->header->len);
		(*len)++;
		nr_bytes = data->header->len;
		return 0;

	} else {
		int dim = nr_bytes;
		*arr = realloc(*arr, nr_bytes+data->header->len);
		memcpy(*arr+dim, data, data->header->len);
		(*len)++;
	}
	nr_bytes = data->header->len + nr_bytes;
	return 1;
}

void print(void** arr, int len) {
	int i = 0;
	int tip = 0;
	int dim = 0;
	
	//de stersss
	if ( arr == NULL ) 
		printf("vector null\n\n");


	for ( ; i < len; i++ ) {
		tip = ((element*)(*arr+dim))->header->type;
		printf("Tipul %d\n", tip);
		printf("dimensiunea %d\n", ((element*)(*arr+dim))->header->len);
		if ( tip == 1 ) {
			tip1* el = (tip1*)((element*)(*arr+dim))->data;
			printf("%s pentru %s\n", el->manelist, el->pers);
			printf("%"PRId8"\n", el->ban1);
			printf("%"PRId8"\n\n", el->ban2);
		}

		if ( tip == 2 ) {
			tip2* el = (tip2*)((element*)(*arr+dim))->data;
			printf("%s pentru %s\n", el->manelist, el->pers);
			printf("%"PRId16"\n", el->ban1);
			printf("%"PRId32"\n\n", el->ban2);
		}

		if ( tip == 3 ) {
			tip3* el = (tip3*)((element*)(*arr+dim))->data;
			printf("%s pentru %s\n", el->manelist, el->pers);
			printf("%"PRId32"\n", el->ban1);
			printf("%"PRId32"\n\n", el->ban2);
		}

		dim = dim + ((element*)(*arr+dim))->header->len;
	}
}


int delete_at(void **arr, int *len, int index) {
	int i = 0, dim = 0;
	int ant_dim = 0;
	for ( ; i < index+1; i++ ) {
		ant_dim = dim;
		dim = dim + ((element*)(*arr+dim))->header->len;
	}
	printf("Sterg elementul %d ce de la byte ul %d la byte ul %d\n", index, ant_dim, dim);
	//mut cei bytes de la ant_dim la dim, dau free la element
	
	//creez un aux in care copiez ce e dupa dim
	//arr ramane cu ce e pana in ant_dim

	int nr_bytes = 0;
	void* aux = NULL;
	for ( i = index+1; i < *len; i++ ) {
		if ( i == index+1 ) {
			aux = calloc(1, ((element*)(*arr+dim))->header->len);
			memcpy(aux, *arr+dim, ((element*)(*arr+dim))->header->len);
			nr_bytes = ((element*)(*arr+dim))->header->len;
		} else {
			aux = realloc(aux, nr_bytes+ ((element*)(*arr+dim+nr_bytes))->header->len);
			memcpy(aux+nr_bytes, *arr+dim+nr_bytes,  ((element*)(*arr+dim+nr_bytes))->header->len);
			nr_bytes = nr_bytes +  ((element*)(*arr+dim+nr_bytes))->header->len;
		}
	}
	printf("-----------------AUX cu %d elemente:\n", *len-index-1);
	print(&aux,  (*len-index-1));


	//dau free a tot ce e dupa *arr+ant_dim
	int elimin = *len - index;
	//exit_dezaloc(*arr+ant_dim, &elimin);

	//memmove((*arr+ant_dim), (*arr+dim), sizeof(void));

	//mut bitii
	if ( (*len-index-1) != 0 ) {
		//dezaloc  tot ce e la *arr+ant_dim
		//adaug apoi din vectorul aux
	}

	(*len) --;
	return 0;
}

void find(void *arr, int len, int index) {
	if ( index >= 0 && index < len && len != 0) {
		int i = 0, dim = 0;
		int ant_dim = 0;
		for ( ; i < index+1; i++ ) {
			ant_dim = dim;
			dim = dim + ((element*)(arr+dim))->header->len;
		}
		len = len-index;
		printf("Afisez dupa %d octeti pana la %d din vector de lungime %d\n", ant_dim, dim, len);

		
		int tip = ((element*)(arr+ant_dim))->header->type;
		printf("Tipul %d\n", tip);
		//printf("dimensiunea %d\n", ((element*)(*arr+dim))->header->len);
		if ( tip == 1 ) {
			tip1* el = (tip1*)((element*)(arr+ant_dim))->data;
			printf("%s pentru %s\n", el->manelist, el->pers);
			printf("%"PRId8"\n", el->ban1);
			printf("%"PRId8"\n\n", el->ban2);
		}

		if ( tip == 2 ) {
			tip2* el = (tip2*)((element*)(arr+ant_dim))->data;
			printf("%s pentru %s\n", el->manelist, el->pers);
			printf("%"PRId16"\n", el->ban1);
			printf("%"PRId32"\n\n", el->ban2);
		}

		if ( tip == 3 ) {
			tip3* el = (tip3*)((element*)(arr+ant_dim))->data;
			printf("%s pentru %s\n", el->manelist, el->pers);
			printf("%"PRId32"\n", el->ban1);
			printf("%"PRId32"\n\n", el->ban2);
		}	
	}
}

int insert_at(void **arr, int *len, element *data, int index) {
	
	//int i = 0;
	if ( index < 0 ) 
	return 1;
	else { 
		printf("Inserez la indexul %d\n", index);
		//daca vectorul e gol=> se face inserarea la sfarsit
		
		int i = 0, end = 0;
		int start = 0;
		for ( ; i < index+1; i++ ) {
			start = end;
			end = end + ((element*)(*arr+end))->header->len;
		}
		printf("Introduc nou element incepand cu byte ul %d pana la %d \n", start, end);
		//int dim = ((element*)*arr)->header->len;
		//copiez partea de pana in start, pan ain index
		void** inainte = NULL;
		int bytes = 0;
		for ( i = 0; i < index; i++ ) {
			if ( i == 0 ) {
				*inainte = calloc(1, ((element*)*arr)->header->len);
				memcpy(*inainte, (element*)*arr, sizeof(element));
				bytes = ((element*)*arr)->header->len;
			} else {
				*inainte = realloc(*inainte, bytes+((element*)*arr)->header->len);
				memcpy(*inainte+bytes, (element*)*arr, sizeof(element));
				bytes = bytes + ((element*)*arr)->header->len;
			}
		}
		printf("-------------Vectorul auxiliar inainte:\n");
		print(inainte, index);
	}

	return 0;
}

void exit_dezaloc( void** arr, int* lung) {
	int nr_bytes = 0;
	int len = 0, tip = 0;
	if ( *arr != NULL ) {
		while ( (*lung) > 0 ) {
			len = ((element*)*arr+nr_bytes)->header->len;
			tip = ((element*)*arr+nr_bytes)->header->type;
	
			if ( tip == 1 ) {
				free( ((tip1*)((element*)(*arr+nr_bytes))->data)->manelist );
				free( ((tip1*)((element*)(*arr+nr_bytes))->data)->pers );
				free( ((tip1*)((element*)(*arr+nr_bytes))->data));
			}
			if ( tip == 2 ) {
				free( ((tip2*)((element*)(*arr+nr_bytes))->data)->manelist );
				free( ((tip2*)((element*)(*arr+nr_bytes))->data)->pers );
				free( ((tip2*)((element*)(*arr+nr_bytes))->data) );
			}
			if ( tip == 3 ) {
				free( ((tip3*)((element*)(*arr+nr_bytes))->data)->manelist );
				free( ((tip3*)((element*)(*arr+nr_bytes))->data)->pers );
				free( ((tip3*)((element*)(*arr+nr_bytes))->data) );
			}
			free(((element*)*arr+nr_bytes)->header);
			nr_bytes = nr_bytes + len;
			(*lung)--;
		}
		//free(*arr);
	}
}