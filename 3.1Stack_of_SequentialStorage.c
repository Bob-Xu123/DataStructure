#include <stdio.h>
#include <stdlib.h> //要使用malloc()函数必须包含这个头文件

struct StackStr
{
	int* Data;
	int Top;
	int MaxSize;
};
typedef struct StackStr* Stack;


/*函数：创建一个给定容量的空堆栈*/
Stack CreatStack(int MaxSize)
{
	Stack S = (Stack)malloc(sizeof(struct StackStr));
	S->Data = (int*)malloc(MaxSize*sizeof(int));
	S->Top = -1;
	S->MaxSize = MaxSize;
	return S;
}

/*函数：判断堆栈是否为空、已满*/
bool isEmpty(Stack S)
{
	return(S->Top == -1);
}

bool isFull(Stack S)
{
	return (S->Top == S->MaxSize-1);
}

/*函数：入栈操作Push*/
bool Push(Stack S, int X)
{
	if (isFull(S)) {
		printf("The Stack is Full\n");
		return false;
	}
	else {
		S->Data[++S->Top] = X;
		return true;
	}
}

/*函数：出栈操作Pop*/
int Pop(Stack S)
{ 
	if (isEmpty(S)) {
		printf("The stack is empty\n");
		return -404;
	}
	else{
		return (S->Data[S->Top--]);
	}
}

int main() {
	int MaxSize = 10;
	Stack stack1 = CreatStack(MaxSize);
	Push(stack1, 10);
	Pop(stack1);
	int e = Pop(stack1);
	printf("%d\n", e);
}
