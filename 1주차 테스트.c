#define _CRT_SECURE_NO_WARINGS
#include <stdio.h>
int main(void) {
	int a = 0;
	while (a <= 9) {
		if (a!=0 && a % 3 == 0) {
			int i = 0;
			printf("CLAP\n");
			while (i <= 8) {
				printf("CLAP\t");
				i = i+1;
			}

			a = a+1;
		}
		else {
			int l = 0;
			printf("%d0\n", a);
			while (l <= 6) {
				printf("%d%d\t%d%d\tCLAP\t", a, l + 1, a, l + 2);
				l = l+3;
			}
			a = a+1;
		}

	}
	printf("100");
	return 0;
		
	
}