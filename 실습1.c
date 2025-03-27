#include <stdio.h>

int main(void) {
	int a = 0, b = 0;
	scanf_s("%d %d", &a, &b);
	printf("\n%d %d", a, b);
	func(&a, &b);
	printf("\n%d %d", a, b);
}
int func(int* p, int* q) {
	int tmp;
	tmp = *p;
	*p = *q;
	*q = tmp;
}