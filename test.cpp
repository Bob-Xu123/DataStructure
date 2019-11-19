#include <stdio.h>
#include <stdlib.h>

int main() {
	int* p = (int*)malloc(sizeof(int));
	printf("%d\n", *p);
	*p = 5;
	int* q = p;
	free(q);
	printf("%d\n", *p);
}
