#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long int* create_matrix(long int);
void fill_matrix(long int*, long int);
void write_out(long int*, long int);
void sieve(long int*, long int);

int main (void) {
	long int *matrix;
	long int i;
	long int range;
	printf("Poszukiwanie liczb pierwszych w przedziale 0 - ");
	scanf("%d", &range);
	matrix=create_matrix(range); //alokacja pamieci
	if(matrix == NULL) {
		return 0;
	}
	fill_matrix(matrix, range); //wypelnienie tablicy kolejnymi liczbami
	sieve(matrix, range); 
	write_out(matrix, range);
	free(matrix);
	return 0;
}

long int* create_matrix(long int range) {
	long int *matrix = malloc( (range+1) * sizeof(range) );
	if(matrix == NULL) {
		printf("Blad przydzialu pamieci.");
		return NULL;
	}
	return matrix;
}

void fill_matrix(long int* matrix, long int range) {
	long int i;
	for(i=0; i<=range; i++) {
		matrix[i]=i;
	}
}

void write_out(long int* matrix, long int range) {
	long int i;
	printf("\nLiczby pierwsze z tego przedzialu:\n \n");
	for(i=2; i<=range; i++) {
		if(matrix[i] != 0) {
			printf("%d \n", matrix[i]);
		}
	}
}

void sieve(long int* matrix, long int range) {
	long int i,j;
	for(i=2; i<sqrt(range); i++) {
		if(matrix[i] != 0) {
			for(j=2*i; j<=range; j=j+i) {
				matrix[j]=0;
			}
		}
	}
}
