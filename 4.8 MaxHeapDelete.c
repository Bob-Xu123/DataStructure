#include <stdio.h>
#include <stdlib.h>

#define MAXDATA 1000
#define ERROR -1

struct HeapStr
{
	int* Data;
	int CurrentSize;
	int Capacity;
};
typedef struct HeapStr* Heap;
typedef Heap MaxHeap;

//函数：创建一个空的最大堆
MaxHeap CreateHeap(int MaxSize)
{
	MaxHeap H = (MaxHeap)malloc(sizeof(struct HeapStr));
	//int A[MaxSize+1] = {MAXDATA};
	//H->Data = A;
	H->Data = (int*)malloc((MaxSize+1)*sizeof(int));  //这两个语句比上面两语句更好一点
	H->Data[0] = MAXDATA; // 数组的0号元素里面放着一个哨兵，大于最大堆中的所有元素。还有一点，用一维数组存放一个堆，起始点最好从下标为1的元素开始。
	H->CurrentSize = 0;
	H->Capacity = MaxSize;

	return H;
}

//函数：最大堆的删除
bool isFull(MaxHeap H) {
	return (H->CurrentSize == H->Capacity);
}

bool isEmpty(MaxHeap H) {
	return (H->CurrentSize == 0);
}

int Delete(MaxHeap H)
{
	if ( !isEmpty(H) ) {
		int TopItem = H->Data[1];
		int BottomItem = H->Data[H->CurrentSize];
		H->Data[H->CurrentSize--]=0; // 堆中第一个元素被弹出后，最后一个元素要挪位子，堆的长度减1, 下面就是给它找位子。

		int Me = 1; //从根结点开始找起，假设将BottomItem放在堆顶，去依次过滤下层的结点
		int BigChild;
		while ( Me*2 <= H->Capacity ) {
			BigChild = Me*2;
			if ( Me*2+1 < H->Capacity && H->Data[Me*2+1] > H->Data[Me*2] )
				BigChild = Me*2+1;
			if (BottomItem < H->Data[BigChild]) {
				H->Data[Me] = H->Data[BigChild];
				Me = BigChild;
			}
			else
				break;
		}
		H->Data[Me] = BottomItem;
		return TopItem;
	}
	return ERROR;
}


// 主函数*********************************************************
int main() {
	MaxHeap H = CreateHeap(6);
	int A[] = {MAXDATA,58,25,44,18,10,31};
	H->Data = A;
	H->CurrentSize = 6;

	int i;
	for (i=0; i<= H->CurrentSize; i++)
		printf("%d ", H->Data[i]);
	printf("\n");

	while (!isEmpty(H)) {
		Delete(H);
		for (i=0; i<= H->CurrentSize; i++)
			printf("%d ", H->Data[i]);
		printf("\n");
	} 
	return 0;
}