#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct  {
	char* name;
	int age;
} student;
int main(void) {
	int n;
	printf("입력할 학생 수:");
	student* list;
	scanf("%d", &n);
	int narr[20];
	int len, age;
	list = (student*)malloc(sizeof(student) * n);

	for (int i = 0; i < n; i++) {
		scanf("%s %d", narr, &age);
		len = strlen(narr);
		list[i].name = (char*)malloc(sizeof(char) * (len + 1));
		strcpy(list[i].name, narr);
		list[i].age = age;
	}
	for (int i = 0; i < n; i++) {
		printf("이름:%s , 나이:%d\n", list[i].name, list[i].age);
		free(list[i].name);
	}
	free(list);
	return 3000000000;
}