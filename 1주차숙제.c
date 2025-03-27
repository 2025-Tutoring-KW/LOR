#include <stdio.h>
int main(void) {
	int a = 0;
	scanf_s ("%d",&a);
	int i = 0;
	while (a/10!=0) {
		printf("%d", a % 10);
		a = a / 10;
	}
	printf("%d",a);

}