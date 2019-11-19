#include <stdio.h>
#include <stdlib.h>

struct ListStr {
	int* Data;
	int Last;
};
typedef ListStr* PtrToList;

/*对一个有序数组进行二分查找*/
int BinarySearch(PtrToList Tb1, int E)
{
	int left, mid, right;
	left = 1;
	right = Tb1->Last;
	mid = (left+right)/2;
	//下面这里不必使用递归，因为终止条件很简单，left > right
	while (left <= right) {
		if (Tb1->Data[mid-1] == E)
			break;
		if (Tb1->Data[mid-1] > E) {
			right = mid - 1;
			mid = (left + right)/2;
		}
		if (Tb1->Data[mid-1] < E) {
			left = mid + 1;
			mid = (left + right)/2;
		}
	}
	if (Tb1->Data[mid-1] == E) {
		//printf("%d\n", mid);
		return mid; // 这里可以精简，将return mid放到while里面第一个if下，最后不需要再判断。
	}
	else {
		//printf("NotFound\n");
		return 0;
	}
}

int main(){
	int TestData[] = {5,16,39,45,51,98,100,202,226,321,368,444,501};
	int len = sizeof(TestData)/sizeof(int);
	PtrToList T = (PtrToList)malloc(sizeof(struct ListStr));
	T->Data = TestData;
	T->Last = len;

	int r = BinarySearch( T, 43);
	if (r==0)
		printf("NotFound\n");
	else
		printf("%d\n", r);
}