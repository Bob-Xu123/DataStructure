#include <stdio.h>
#include <stdlib.h>

// 建立二叉树涉及队列，首先将队列的相关函数copy过来

struct QNode {
	int value;
	struct QNode* next;
};
typedef struct QNode* PtrToQNode;

struct QueueStr {
	PtrToQNode Front;
	PtrToQNode Rear;
};
typedef struct QueueStr* Queue;

//函数：创建一个队列，和堆栈一样，链式队列可以带一空的头结点，表头结点后面的第一个结点是队列的头
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
void AddQ(Queue Q, int E) {
	PtrToQNode temp = (PtrToQNode)malloc(sizeof(struct QNode));
	temp->value = E;
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
int DeleteQ(Queue Q) {
	if ( isEmpty(Q) ) {
		printf("The Queue is empty so cannot delete\n");
		return -404;
	}
	else {
		PtrToQNode TopCell = Q->Front;
		Q->Front = TopCell->next;
		if (Q->Front == NULL) //如果队列中只有一个结点，被删后Front变为了NULL，Rear也要置为NULL
			Q->Rear = NULL;
		int E = TopCell->value;
		free(TopCell);
		return E;
	}
}

//下面开始根据层序输入序列，构建二叉树
