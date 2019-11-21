#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Merge(int A[], int TempA[], int L, int R, int REnd)
{
	int LEnd = R-1; //因为R会变动，所以后面不能用R-1作为扫描终止条件，需要用一个临时变量提前记录R-1，在R发生变化前就把它记下来
	int Num = REnd-L+1;
	int i=L; //注意这里易错点，想当然地让i=0开始！！！
	while (L<=LEnd && R<=REnd) {
		if (A[L] <= A[R])
			TempA[i++] = A[L++];
		if (A[L] > A[R])
			TempA[i++] = A[R++];
	}
	for( ; L<=LEnd; L++)
		TempA[i++] = A[L];
	while( R<=REnd ) //对比观察两种风格
		TempA[i++] = A[R++];
	//将有序的TempA[]复制回A[]
	for(i=0; i<Num; i++, REnd--)
		A[REnd] = TempA[REnd];
}

void Msort(int A[], int TempA[], int L, int REnd)
{
	if (L != REnd) {
		Msort(A, TempA, L, (L+REnd)/2);
		Msort(A, TempA, (L+REnd)/2+1, REnd);
	}
	Merge(A, TempA, L, (L+REnd)/2+1, REnd); //这句话可以放到if里面，其实更好，不用对单个元素进行一次Merge操作
}

void MergeSort(int A[], int N) {
	int* TempA = (int*)malloc(N*sizeof(int)); //这里不能用malloc(sizeof(A))，和函数中无法求数组长度一个道理
	Msort(A, TempA, 0, N-1);
}

int main(){
	int A[3];
	int len = sizeof(A)/sizeof(A[0]);
	srand(time(NULL)); // 使用当前时间作为随机种子，srand()播种子
	int i;
	for (i=0; i<len; i++) {
		A[i] = rand()%101;
		printf("%d ", A[i]);
	}
	printf("\n");
	MergeSort(A, len);
	for (i=0; i<len; i++)
		printf("%d ", A[i]);
	return 0;
}
