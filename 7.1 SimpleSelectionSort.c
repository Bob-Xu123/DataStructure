#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
	int t=*a; *a=*b; *b=t;
}

void SimpleSelectionSort(int A[], int N)
{
	int i, j;
	for (i=0; i<N; i++) {
		int min = i;
		for (j=i+1; j<N; j++)
			if ( A[j] < A[min] ) min = j;
		swap(&A[i], &A[min]);
	}
}


int main(){
	int A[10];
	int len = sizeof(A)/sizeof(A[0]);
	for (int i=0; i<len; i++) {
		A[i] = rand()%101;
	}
	for (int i=0; i<len; i++)
		printf("%d ", A[i]);
	SimpleSelectionSort(A, len);
	printf("\n");
	for (int i=0; i<len; i++)
		printf("%d ", A[i]);
}