#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct TNodeStr
{
	int Data;
	struct TNodeStr* Left;
	struct TNodeStr* Right;
};
typedef struct TNodeStr* TNode;
typedef TNode BinTree;

//首先将之前编写的二叉搜索树的查找函数照搬过来******************************
TNode Find(BinTree BST, int E)
{
	if (BST==NULL)
		return NULL;
	else {
		if (E < BST->Data)
			return Find(BST->Left, E);
		else if (E > BST->Data)
			return Find(BST->Right, E);
		else
			return BST;
	}
}

TNode FindMin(BinTree BST)
{
	if (BST==NULL)
		return NULL;
	else {
		if (BST->Left==NULL)
			return BST;
		else
			return FindMin(BST->Left);
	} //事后发现这个{}是多此一举的，不过这样恰好体现了我的思考过程。
}

TNode FindMax(BinTree BST)
{
	if (BST==NULL)
		return NULL;
	else if (BST->Right==NULL)
		return BST;
	else
		return FindMax(BST->Right);
}

//函数：二叉搜索树的删除**********************************************************
BinTree Delete(BinTree BST, int E)
{	
	TNode TNodeE = Find(BST, E);
	if(TNodeE) {
		if (TNodeE->Left==NULL && TNodeE->Right==NULL) {
			//如果待删节点无孩子
			return NULL;
			free(TNodeE);
		}
		else if (TNodeE->Left && !TNodeE->Right) {
			//如果待删节点只有一个孩子（左孩子）
			TNodeE->Data = TNodeE->Left->Data;
			TNodeE->Left = Delete(TNodeE->Left, TNodeE->Left->Data);
		}
		else if (!TNodeE->Left && TNodeE->Right) {
			//如果待删节点只有一个孩子（右孩子）
			TNodeE->Data = TNodeE->Right->Data;
			TNodeE->Right = Delete(TNodeE->Right, TNodeE->Right->Data);
		}
		else {
			//如果待删节点有左右两个孩子
			TNode Succession = FindMax(TNodeE->Left);
			TNodeE->Data = Succession->Data;
			TNodeE->Left = Delete(TNodeE->Left, Succession->Data);
		}
	}
	return BST;
}


int main() {
/*自己简单粗暴地建立一个二叉搜索树的样例。
  30
 /  \
15   41
    /  \
   33  50
     \
     35
    /
   34

*/
	int D[7] = {30,15,41,33,50,35,34};
	TNode A[5];
	int i;
	for (i=0; i<7; i++) {
		A[i] = (TNode)malloc(sizeof(struct TNodeStr));
		A[i]->Data = D[i];
		A[i]->Left = A[i]->Right = NULL;
	}
	A[0]->Left=A[1]; A[0]->Right=A[2]; A[2]->Left=A[3]; A[2]->Right=A[4]; A[3]->Right=A[5]; A[5]->Left=A[6];

	int E = 41;
	BinTree T = Delete(A[0], E);
	return 0;
}


