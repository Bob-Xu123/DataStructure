#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TNodeStr {
	int Data;
	struct TNodeStr* Left;
	struct TNodeStr* Right;
};
typedef struct TNodeStr* PtrToTNode;
typedef PtrToTNode BinTree;

// 建立二叉树涉及队列，首先将队列的相关函数copy过来，这里需要修改队列中的数据类型为指向树节点的指针

struct QNode {
	PtrToTNode T;
	struct QNode* next;
};
typedef struct QNode* PtrToQNode;

struct QueueStr {
	PtrToQNode Front;
	PtrToQNode Rear;
};
typedef struct QueueStr* Queue;

//函数：创建一个队列
Queue CreatQueue() {
	Queue Q = (Queue)malloc(sizeof(struct QueueStr));
	Q->Front = NULL;
	Q->Rear = NULL;
	return Q;
}

//函数：判断一个队列是否为空
bool isEmpty(Queue Q) {
	return (Q->Front == NULL);
}

//函数：往队列中加一个元素
void AddQ(Queue Q, PtrToTNode E) {
	PtrToQNode temp = (PtrToQNode)malloc(sizeof(struct QNode));
	temp->T = E;
	temp->next = NULL;
	if ( isEmpty(Q) ) {
		Q->Front = temp;
		Q->Rear = temp;
	}
	else {
		Q->Rear->next = temp;
		Q->Rear = temp;
	}
}

//函数：从队列中删除一个元素
PtrToTNode DeleteQ(Queue Q) {
	if ( isEmpty(Q) ) {
		printf("The Queue is empty so cannot delete\n");
		return NULL;
	}
	else {
		PtrToQNode TopCell = Q->Front;
		Q->Front = TopCell->next;
		if (Q->Front == NULL) //如果队列中只有一个结点，被删后Front变为了NULL，Rear也要置为NULL
			Q->Rear = NULL;
		PtrToTNode E = TopCell->T;
		free(TopCell);
		return E;
	}
}

//下面开始根据层序输入序列，构建二叉树

BinTree CreatBinTree()
{
	int data;
	BinTree BT, T;
	Queue Q = CreatQueue();

	//建立第一个节点，即根节点
	scanf("%d", &data);
	if (data != 0) {
		BT = (PtrToTNode)malloc(sizeof(BT));
		BT->Data = data;
		BT->Left = BT->Right = NULL;
		AddQ(Q, BT);
	}
	else
		return NULL;

	while( !isEmpty(Q) ) {
		T = DeleteQ(Q);
		scanf("%d", &data);
		if (data){
			T->Left = (PtrToTNode)malloc(sizeof(struct TNodeStr));
			T->Left->Data = data;
			T->Left->Left = T->Left->Right = NULL;
			AddQ(Q, T->Left);
		}
		else
			T->Left = NULL;

		scanf("%d", &data);
		if (data) {
			T->Right = (PtrToTNode)malloc(sizeof(struct TNodeStr));
			T->Right->Data = data;
			T->Right->Left = T->Right->Right = NULL;
			AddQ(Q, T->Right);
		}
		else
			T->Right = NULL;
	}
	return BT;
}

int main() {
	BinTree BT = CreatBinTree();
}
