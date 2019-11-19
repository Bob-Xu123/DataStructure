#include <stdio.h>
#include <stdlib.h>

struct StackNode
{
	int value;
	struct StackNode* next;
};
typedef struct StackNode* SNode;
typedef SNode Stack;


/*函数：创建链式堆栈，表头带一个空节点*/
Stack CreatStack()
{
	Stack S = (SNode)malloc(sizeof(struct StackNode));
	S->value = -404; //可以不用主动赋值，头结点里的value也用不到
	S->next = NULL;
	return S;
}

bool isEmpty(Stack S) {
	return (S->next == NULL);
}

/*链栈的插入和删除操作都是在第2个节点上进行，第2个节点就是栈顶节点*/
void Push(Stack S, int X)
{
	SNode temp = (SNode)malloc(sizeof(struct StackNode));
	temp->value	= X;
	temp->next = S->next;
	S->next = temp;
}

int Pop(Stack S) {
	if (S->next == NULL) {
		printf("The stack is empty\n");
		return -404;
	}
	else {
		SNode TopNode = S->next;
		int e = TopNode->value;
		S->next = TopNode->next;
		free(TopNode);
		return e;
	}
}


int main() {
	Stack stack1 = CreatStack();
	Push(stack1, 10);
	Pop(stack1);
	int e = Pop(stack1);
	printf("%d\n", e);
}
