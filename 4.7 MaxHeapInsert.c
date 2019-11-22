#include <stdio.h>
#include <stdlib.h>

#define MAXDATA 1000

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

//函数：最大堆的插入
bool isFull(MaxHeap H)
{
	return (H->CurrentSize == H->Capacity);
}

bool Insert(MaxHeap H, int E)
{
	if ( isFull(H) )
		return false;
	else {
		int Me = H->CurrentSize + 1;
		int Father = Me/2;
		while(E > H->Data[Father]) {
			H->Data[Me] = H->Data[Father];
			Me = Father;
			Father = Father/2;
		} // 数组的index：Me和Father其实可以用一者就够了，因为它们之间有关系，但是这里我用了两个，理解起来更清晰。
		H->Data[Me] = E;
		H->CurrentSize++;
		return true;
	}
}


// 主函数*********************************************************
int main() {
	MaxHeap H = CreateHeap(7);
	int A[] = {MAXDATA,44,25,31,18,10};
	H->Data = A;
	H->CurrentSize = 5;

	Insert(H, 58);
	for (int i=0; i<= H->CurrentSize; i++)
		printf("%d ", H->Data[i]);
}