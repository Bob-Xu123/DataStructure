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


int main() {
/*自己简单粗暴地建立一个二叉搜索树的样例。
  30
 /  \
15   41
    /  \
   33  50
*/
	int D[] = {30,15,41,33,50};
	TNode A[5];
	int i;
	for (i=0; i<5; i++) {
		A[i] = (TNode)malloc(sizeof(struct TNodeStr));
		A[i]->Data = D[i];
		A[i]->Left = A[i]->Right = NULL;
	}
	A[0]->Left =A[1]; A[0]->Right =A[2]; A[2]->Left =A[3]; A[2]->Right =A[4];

	//BinTree T = Find(A[0], 33);
	//BinTree T = FindMin(A[0]);
	BinTree T = FindMax(A[0]);
	if (T)
		printf("%d\n", T->Data);
	return 0;
}
