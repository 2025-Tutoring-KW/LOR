#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int data;   // 저장할 값
    struct Node* next; // 자기참조 구조체를 이용해 자기 다음 노드를 가리키는 노드 주소를 저장.
}Node;

typedef struct {
    Node* head;  // 첫 번째 노드를 가리키는 포인터
    Node* tail;  // 마지막 노드를 가리키는 포인터
    int count;   // 리스트의 노드 수를 저장하는 변수
}List;

void insert(List* list, int data,int index);
void add(List* list, int data);
int delete(List* list, int target);
void print(List* list);
int main() {
    List list;
    list.head = NULL;
    list.tail = NULL;
    list.count = 0;
    while (1) {
        char command[101];
        printf("Enter a command (insert or delete or print or exit or add) : ");
        scanf("%s", command);
        if (strcmp(command, "insert") == 0) {
            int data;
            int index;
            printf("Enter a data , index: ");
            scanf("%d %d", &data,&index);
            insert(&list, data,index);
        }
        else if (strcmp(command, "delete") == 0) {
            int target;
            printf("Enter a target : ");
            scanf("%d", &target);
            delete(&list, target);
        }
        else if (strcmp(command, "print") == 0) {
            print(&list);
        }
        else if (strcmp(command, "add") == 0) {
            int data;
            printf("Enter a data ");
            scanf("%d", &data);

            add(&list, data);
        }
        else if (strcmp(command, "exit") == 0) {
            break;
        }
        else {
            printf("Error : Wrong Command.\n");
        }
    }
    Node* current = list.head;
    list.head = NULL;
    list.tail = NULL;
    list.count = 0;
    while (current != NULL) {
        Node* tmp = current;
        current = current->next;
        free(tmp);
    }
    printf("exit program\n");
    return 0;
}
void insert(List* list, int data,int index) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    if (index == 0) {
        node->next = NULL;
        if (list->head == NULL) {
            list->head = node;
            list->tail = node;
        }
        else {
            Node* tmp = list->head;
            list->head = node;
            list->head->next = tmp;
        }
    }
    else {
        Node* tmp;
        Node* tmpp;
        tmp = list->head;
        tmpp = list->head;
        for (int i = 0; i < index; i++) {
           tmp= tmp->next;
        }
        node->next = tmp;

        while (tmpp->next != tmp) {
            tmpp = tmpp->next;
        }
        tmpp->next = node;
        if (index == list->count) {
            list->tail = node;
            node->next = NULL;
        }
    }
    list->count++;
}
int delete(List* list, int target) {
    Node* current = list->head;
    if (current->data == target) {
        if (list->head == list->tail) {
            list->head = NULL;
            list->tail = NULL;
        }
        else {
            list->head = list->head->next;
        }
        free(current);
        list->count--;
        return 0;
    }
    else {
        while (current != NULL) {
            if (current->data == target) {
                Node* tmp = list->head;
                while (tmp->next->data != target) {
                    tmp = tmp->next;
                }
                tmp->next = current->next;
                if (current == list->tail) {
                    list->tail = tmp;
                }
                free(current);
                list->count--;
                return 0;
            }
            current = current->next;
        }
        printf("no exist target.\n");
    }
}
void print(List* list) {
    if (list->count != 0) {
        printf("{ ");
        Node* current = list->head;
        while (current != NULL) {
            printf("%d", current->data);
            if (current->next != NULL) {
                printf(", ");
            }
            current = current->next;
        }
        printf("}, head : %d, tail : %d\n", list->head->data, list->tail->data);
    }
    else {
        printf("No exit list\n");
    }
}
void add(List* list, int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
    }
    else {
        list->tail->next = node;
    }
    list->tail = node;
    list->count++;
}