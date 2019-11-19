#include <stdio.h>
#include <stdlib.h>

struct PolyNode {
	int Coef;
	int Expon;
	struct PolyNode* next;
};
typedef struct PolyNode* PtrToPolyNode;
typedef PtrToPolyNode Polynomial;

int Compare(int e1, int e2) {
	if (e1 > e2)
		return 1;
	else if (e1 < e2)
		return -1;
	else
		return 0;
}

void Attach(int coef, int expon, PtrToPolyNode* PtrRear) {
	PtrToPolyNode P = (PtrToPolyNode)malloc(sizeof(struct PolyNode));
	P->Coef = coef;
	P->Expon = expon;
	P->next = NULL;

	(*PtrRear)->next = P;
	*PtrRear = P;
}

Polynomial PolyAdd(Polynomial P1, Polynomial P2) {
	//为方便表头插入，先产生一个临时空结点作为结果多项式的表头
	Polynomial P;
	PtrToPolyNode rear;
	P = (PtrToPolyNode)malloc(sizeof(struct PolyNode));
	P->next = NULL;
	rear = P;
	int sum;
	while( P1 && P2) {
		switch(Compare(P1->Expon, P2->Expon)) {
			case 1:
				Attach(P1->Coef, P1->Expon, &rear);
				P1 = P1->next;
				break;
			case -1:
				Attach(P2->Coef, P2->Expon, &rear);
				P2 = P2->next;
				break;
			case 0:
				//int sum = P1->Coef + P2->Coef; //error: while多次循环会重复定义int sum
				sum = P1->Coef + P2->Coef;
				if (sum)
					Attach(P1->Coef + P2->Coef, P1->Expon, &rear);
				P1 = P1->next;
				P2 = P2->next;
				break;
		}
	}
	//至此，P1和P2至少有一个已经被扫描完了，接下来把剩下的直接接到结果多项式的后面
	
	while (P1) {
		Attach(P1->Coef, P1->Expon, &rear);
		P1 = P1->next;
	}
	while (P2) {
		Attach(P2->Coef, P2->Expon, &rear);
		P2 = P2->next;
	}
	//rear->next = NULL; //这句应该是多余
	//现在要删掉结果多项式P的临时空的头结点
	PtrToPolyNode temp = P;
	P = temp->next;
	free(temp);
	return P;
}

int main() {
	Polynomial P1 = (Polynomial)malloc(sizeof(struct PolyNode)); PtrToPolyNode rear1 = P1, temp;
	Polynomial P2 = (Polynomial)malloc(sizeof(struct PolyNode)), rear2 = P2;
	Attach(9, 12, &rear1), Attach(15, 8, &rear1), Attach(3, 2, &rear1);
	Attach(26, 19, &rear2), Attach(-4, 8, &rear2), Attach(-13, 6, &rear2), Attach(82, 0, &rear2);
	temp = P1; P1 = temp->next; free(temp);
	temp = P2; P2 = temp->next; free(temp);
	Polynomial P = PolyAdd(P1, P2);
	while (P) {
		printf("%dx^%d + ", P->Coef, P->Expon);
		P = P->next;
	}
	printf("0\n");
	return 0;
}
