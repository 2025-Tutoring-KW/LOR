#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void) {
	int n;
	int pn[15] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47 };
	int arr[15];
	memset(arr, 0, sizeof(arr));
	scanf("%d", &n);
	printf("%d =", n);
	int k;
	for (int i = 0; i < 15; i++) {//소인수분해 정보 배열에 저장
		if (n % pn[i] == 0) {
			do
			{


				n = n / pn[i];
				arr[i]++;

			} while (n % pn[i] == 0);
			printf("%d^%d", pn[i], arr[i]);
		}
		if (n == 1) {
			k = i;
			break;
		}

		printf("X");
	}


}