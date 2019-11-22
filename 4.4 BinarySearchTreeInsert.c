#include <stdio.h>
#include <stdlib.h>

struct TNodeStr
{
	int Data;
	struct TNodeStr* Left;
	struct TNodeStr* Right;
};
typedef struct TNodeStr* TNode;
typedef TNode BinTree;

//为了方便，新增结点总是作为叶结点插入到一个二叉搜索树中。
BinTree Insert(BinTree BST, int E)
{
	if( BST == NULL ) {
		BST = (BinTree)malloc(sizeof(struct TNodeStr));
		BST->Data = E;
		BST->Left = BST->Right = NULL;
	}
	else {
		if (E < BST->Data)
			BST->Left = Insert(BST->Left, E); //这里左半部分的赋值操作"BST->Left="是为了最后一次递归，将插入的结点接入到原搜索二叉树的底部（某个叶结点），当然在递归触底反弹的过程中，它也会将已有的二叉树的边重复连接一遍，这个也无妨。
		else if (E > BST->Data)
			BST->Right = Insert(BST->Right, E);
	}
	return BST; //在递归函数一步步重复调用时，会产生很多个BST，但是当一步步返回时，中间产生的BST逐渐消失，最终留下的那个BST就是最初传进的那个BST。
}


int main() {
/*自己简单粗暴的建立一个搜索二叉树的样例。
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

	BinTree T =Insert(A[0], 35);
	printf("%d\n", T->Right->Left->Right->Data);
	return 0;
}
