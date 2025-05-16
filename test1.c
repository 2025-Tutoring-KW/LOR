#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int initialize(char*** arr);
int sort(char***arr,int num);
int my_strcmp(char* arr1, char* arr2,int num);
int end(char*** arr, int num);
int main(void) {
	char** arr=malloc(sizeof(char*));
	int num = initialize(&arr);
	sort(&arr, num);
	end(&arr, num);

}
int initialize(char*** arr) {
	char tmp[20];
	int num=0;
	while (1) {
		scanf("%s", &tmp);
		if (tmp[0] == '0') {
			return num;
		}
		else {
			
			*arr= (char**)realloc(*arr,sizeof(char*)*(num+1));
			(*arr)[num] = (char*)malloc((strlen(tmp)+1)*sizeof(char));
			strcpy((*arr)[num], &tmp);
			num++;
		}

	}

}

int sort(char*** arr, int num) {
	for (int i = 0; i < num - 1; i++) {
		for (int j = i+1; j < num; j++) {

			if (my_strcmp((*arr)[i],(*arr)[j],num)==1) {
				char* tmp = (*arr)[i];
				(*arr)[i] = (*arr)[j];
				(*arr)[j] = tmp;

			}
			else if (my_strcmp((*arr)[i], (*arr)[j], num) == -1) {
				(*arr)[i][0] = '\0';
			}
		}	
		
	}
}
int my_strcmp(char* arr1, char* arr2, int num) {//같으면 -1 ,크면1이 크면 1,1이 작으면 0
	for (int i = 0; i<strlen(arr1)&&i<strlen(arr2); i++) {
		char a = (*arr1);
		char b = (*arr2);
		if (a >= 'a') {
			a=a - 32;
		}
		if (b >= 'a') {
			b=b - 32;
		}
		if (a == b) {
			if (i == strlen(arr1)-1 || i == strlen(arr2)-1) {
				if (strlen(arr1) == strlen(arr2)) {
					return -1;
				}
				else if (strlen(arr1) >= strlen(arr2)) {
					return 0;
				}
				else if (strlen(arr1) <= strlen(arr2)) {
					return 1;
				}
			}
			else {
				arr1++;
				arr2++;
				continue;
			}
		}
		else if (a < b) {
			return 0;
		}
		else {
			return 1;
		}
	}
}
int end(char*** arr,int num) {
	for (int i = 0; i < num; i++) {
		if ((*arr)[i][0] != '\0') {
			printf("%s\n", (*arr)[i]);
		}
		free((*arr)[i]);
	}
	free(*arr);
}

