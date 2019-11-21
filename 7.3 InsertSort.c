#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b)
{
	int t=*a; *a=*b; *b=t;
}

void InsertSort(int A[], int N)
{
	int i, j;
	for (i=0; i<N; i++) {
		for (j=i; j>0; j--) {
			if (A[j] < A[j-1])
				swap(&A[j], &A[j-1]);
		}
	}
}


int main() {
	int A[10], len = sizeof(A)/sizeof(A[0]);
	srand(time(NULL));
	for (int i=0; i<len; i++) {
		A[i] = rand()%101;
		printf("%d ", A[i]);
	}
	printf("\n");

	InsertSort(A, len);
	for (int i=0; i<len; i++)
		printf("%d ", A[i]);
	return 0;
}