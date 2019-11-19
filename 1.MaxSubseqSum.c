#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int MaxSubseqSum1(int List[], int N);
int MaxSubseqSum2(int List[], int N);
int MaxSubseqSum3(int List[], int N);
int MaxSubseqSum4(int List[], int N);


int main(){
	//下面一小段代码是为了产生一个具有一定长度的[-100,100]的随机数组
	int List[10000], N = 10000;
	for (int i=0; i<(int)(sizeof(List)/sizeof(List[0])); i++){
		List[i] = rand()%201-100;
	}

	clock_t start, stop;
	double duration;
	//{ start = clock(); printf("MaxSubseqSum1: %d\t", MaxSubseqSum1(List, N)); stop = clock(); duration = ((double)(stop - start))/CLK_TCK; printf("duration1: %f\n", duration); }
	{ start = clock(); printf("MaxSubseqSum2: %d\t", MaxSubseqSum2(List, N)); stop = clock(); duration = ((double)(stop - start))/CLK_TCK; printf("duration2: %f\n", duration); }
	{ start = clock(); printf("MaxSubseqSum3: %d\t", MaxSubseqSum3(List, N)); stop = clock(); duration = ((double)(stop - start))/CLK_TCK; printf("duration3: %f\n", duration); }
	{ start = clock(); printf("MaxSubseqSum4: %d\t", MaxSubseqSum4(List, N)); stop = clock(); duration = ((double)(stop - start))/CLK_TCK; printf("duration3: %f\n", duration); }

	return 0;
}

/*算法1.1 穷举*/
int MaxSubseqSum1 (int List[], int N) {
	int i, j, k;
	int ThisSum, MaxSum = 0;
	for (i=0; i<N; i++){
		for (j=i; j<N; j++){
			ThisSum = 0;
			for (k=i; k<=j; k++){
				ThisSum += List[k];
			}
			if (ThisSum > MaxSum) MaxSum = ThisSum;
		}
	}
	return MaxSum;
}

/*算法1.2 部分存储中间值的穷举*/
int MaxSubseqSum2 (int List[], int N) {
	int i, j;
	int ThisSum, MaxSum = 0;
	for (i=0; i<N; i++) {
		ThisSum = List[i];
		for (j=i+1; j<N; j++) {
			if (ThisSum > MaxSum) MaxSum = ThisSum;
			ThisSum += List[j];
		}
	}
	return MaxSum;
}

/*算法啊1.3 分而治之*/
int MaxSubseqSum3 (int List[], int N){
	if ( N==1 ) {
		return List[0];
	}
	else{
		int ListLeft[N/2], ListRight[N-N/2];
		for (int i=0; i<N/2; i++)	ListLeft[i] = List[i];
		for (int i=N/2; i<N; i++)	ListRight[i-N/2] = List[i];

		/*下面是找出过中线的具有最大和的子列*/
		int SumMid_L=0, MaxSumMid_L=0, SumMid_R=0, MaxSumMid_R=0;
		for (int i=N/2-1; i>=0; i--) {
			SumMid_L += ListLeft[i];
			MaxSumMid_L = (SumMid_L > MaxSumMid_L)? SumMid_L : MaxSumMid_L;
		}
		for (int i=0; i<N-N/2; i++) {
			SumMid_R += ListRight[i];
			MaxSumMid_R = (SumMid_R > MaxSumMid_R)? SumMid_R : MaxSumMid_R;
		}
		int MaxSumMid, MaxSumLeft, MaxSumRight, MaxSum;
		MaxSumMid = MaxSumMid_L + MaxSumMid_R;


		MaxSumLeft = MaxSubseqSum3(ListLeft, N/2);
		MaxSumRight = MaxSubseqSum3(ListRight, N-N/2);

		MaxSum = (MaxSumLeft > MaxSumRight)? MaxSumLeft : MaxSumRight;
		MaxSum = (MaxSumMid > MaxSum)? MaxSumMid : MaxSum;
		return MaxSum;
	}
}

/*算法1.4 在线处理*/
int MaxSubseqSum4 (int List[], int N){
	int MaxSum = 0, ThisSum = 0;
	for (int i=0; i<N; i++){
		ThisSum += List[i];
		if (ThisSum > MaxSum){
			MaxSum = ThisSum;
		}
		else if (ThisSum < 0){
			ThisSum = 0;
		}
	}
	return MaxSum;
}