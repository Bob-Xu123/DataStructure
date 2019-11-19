#include <stdio.h>

int FindKthLargest(int List[], int len, int K);
void swap(int* a, int* b);
int FindKthLargest2(int List[], int left, int right, int K);



int main(){
	int List[] = {6, 5, 9, 8, 2, 1, 7, 3, 4};
	int K = 2;
	int len = (int)sizeof(List)/sizeof(List[0]); //需要注意的一点：当把数组传入函数后，不能在函数中通过上一条语句求长度，因为传进去的只是地址。
	int left = 0, right = len-1;
	if (K > len)
		printf("K exceeds the length!\n");
	else{
		int result = FindKthLargest(List, len, K);
		printf("result: %d\n", result);
		int result2 = FindKthLargest2(List, K, left, right);
		printf("result2: %d\n", result2);
	}
	return 0;
}

/*思路：将大问题分解成小问题，小问题的求解采用与大问题相同的思路，采用函数递归的程序设计方法实现。
基本思路：用一个基准数e将集合S分解为不包含e在内的两个小集合S1和S2，其中S1的任何元素均大于e，S2的任何元素均小于e。
		记|S|代表集合S元素的个数，这样，如果|S1|>=K，则说明第K大数在S1中；如果|S1 = K-1|，则说明K=e; 否则第K大
		数在S2中，并且是S2中的第K-|S1|-1大数。然后，可以用类似的思路继续在S1或S2中查找。*/

/*首先面临的问题是如何根据元素e将集合S分解为S1和S2，可以每次选S中的第一个元素作为e，关于分解S，我想到的是用
两个临时数组分别存放S1和S2，而且需要提前确定两者的长度。书本上提供的思路1：应用一个临时数组，对S中的元素进行
遍历，如果当前元素比e大，则放到临时数组的一头，否则放到临时数组的另一头。书本思路2：不需要额外数组空间，先从
数组S的左边扫描，如果发现比e小的元素则暂停；再从数组右边扫描，遇到大于等于e的元素则暂停。此时，左右两个暂停点
的元素是错位的，把他们交换一下。然后从左右暂停点开始重复上述的步骤，直到作用扫描在中间某处相会。此时相会的位置
就是基准e把两个集合分开的位置，把e换到这个位置上，S1中的元素就被放在e的左边，S2中的元素就被放在e的右边。*/

int FindKthLargest(int List[], int len, int K){
	if (len == 1) return List[0];
	else {
		int e = List[0];
		int len1 = 0;
		int i;
		for (i=0; i<len; i++){
		if (List[i] > e) len1++;
		}
		int len2=len-len1-1, List1[len1], List2[len2];
		int j = 0, k = 0;
		for ( i=0; i<len; i++ ){
			if (List[i] > e){List1[j] = List[i]; j++; }
			if (List[i] < e) { List2[k] = List[i]; k++; }
		}

		if (len1 >= K) return FindKthLargest(List1, len1, K);
		else if (len1 == K-1) return e;
		else return FindKthLargest(List2, len2, K-len1-1);
	}
}


void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int FindKthLargest2(int S[], int K, int left, int right){
	int e = S[left];
	int L = left, R = right;

	while(1){
		while (left<=right && S[left]>=e)
			left++;
		while (left<right && S[right]<e)
			right--;
		if (left < right)
			swap(&S[left], &S[right]);
		else
			break;
	}
	
	swap(&S[L], &S[left-1]);
	if (left-L-1 >= K)
		return FindKthLargest2(S, K, L, left-2);
	else if (left-L-1 < K-1)
		return FindKthLargest2(S, K-(left-L-1)-1, left, R);
	else
		return e;
}
