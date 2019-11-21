#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b)
{
	int t=*a; *a=*b; *b=t;
}

void QuickSort(int A[], int left, int right)
{
	int pivot, L=left, R=right;
	pivot = left; //这里是一个错误点：误把pivot=0
	while(1) {
		while (left <= right && A[left] <= A[pivot])
			left++;
		while (left<=right && A[right]>A[pivot])
			right--;
		if (left < right)
			swap(&A[left], &A[right]);
		else
			break;
	}
	swap(&A[pivot], &A[left-1]);
	if (L < right-1)
		QuickSort(A, L, right-1);
	if (left < R)
		QuickSort(A, left, R);
}


int main() {
	int A[10];
	int len = sizeof(A)/sizeof(A[0]);
	srand(time(NULL)); // 使用当前时间作为随机种子，srand()播种子
	int i;
	for (i=0; i<len; i++) {
		A[i] = rand()%101;
		printf("%d ", A[i]);
	}
	printf("\n");
	QuickSort(A, 0, len-1);
	for (i=0; i<len; i++)
		printf("%d ", A[i]);
	printf("\n");
}
