#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void BubbleSort(int A[], int N)
{
	if (N >= 2) {
		int i, t, K=0; //K是用来记录已经排好序的元素个数，用于确定下面扫描数组的终止点
		for (K=0; K<N-1; K++) {
			for (i=1; i<N-K; i++) {
				if (A[i]<A[i-1]) {
					t = A[i-1]; A[i-1]=A[i]; A[i]=t;
				}
			}
		}
	}
}

//为了更方便处理，下面将从数组的尾部开始扫描。另外增加一个flag标记，检查剩余的数列是否有序，有序的话就不必再循环下去冒泡了。
void swap(int *a, int* b)
{
	int t; t=*a; *a=*b; *b=t;
}

void BubbleSort2(int A[], int N)
{
	int P, i;
	bool flag;
	for (P=N-1; P>0; P--) {
		flag = false;
		for (i=0; i<P; i++) {
			if (A[i] > A[i+1]) {
				swap(A+i, A+i+1);
				flag = true; // flag为true表明发生了交换
			}
		}
		if (!flag)
			break;
	}
}


int main() {
	int A[10];
	int len = sizeof(A)/sizeof(A[0]);
	srand(time(NULL)); // 使用当前时间作为随机种子，srand()播种子
	for (int i=0; i<len; i++) {
		A[i] = rand()%101;
		printf("%d ", A[i]);
	}
	printf("\n");
	
	BubbleSort2(A, len);
	for (int i=0; i<len; i++)
		printf("%d ", A[i]);
	printf("\n");
}