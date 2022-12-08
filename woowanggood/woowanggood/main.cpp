#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 10
typedef char element;
typedef struct {
	int top;
	element data[STACK_SIZE][20];
}Stack;
int isFull(Stack* s);
int isEmpty(Stack* s);
void push(Stack* s);
element* pop(Stack* s);
void initStack(Stack* s);

int main() {
	int menu;
	element* data = NULL;
	Stack s;
	initStack(&s);
	do { 
		printf("=========================================================================\n\n\n\n");
		printf("검색 : 1, 검색기록 삭제 : 2, 종료 : 0 || 수행할 작업을 선택하세요 : ");
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			printf("검색어 입력 : ");
			push(&s);
			printf("\n\n\n");
			break;
		case 2:
			data = pop(&s);
				printf("삭제된 검색어 : ");
				for (int i = 0; i < strlen(data); i++) {
					printf("%c", data[i]);
				}
				printf("\n\n\n\n");
			break;
		case 0:
			break;
		default:
			printf("잘못된 입력 입니다. \n");
			break;
		}
	} while (menu);
}

void initStack(Stack* s) {
	s->top = -1;
}
int isFull(Stack* s) {
	return s->top == STACK_SIZE - 1;
}
int isEmpty(Stack* s) {
	return s->top == -1;
}
void push(Stack* s) {
	if (isFull(s)) {
		printf("Stack if Full\n");
		return;
	}
	char data[20];
	s->top++;
	scanf("%s", data);
	for (int i = 0; i < strlen(data); i++) {
		s->data[s->top][i] = data[i];
	}
	s->data[s->top][strlen(data) + 1] = '\0';
}
element* pop(Stack* s) {
	if (isEmpty(s)) {
		printf("Stack is Empty\n");
		return 0;
	}
	return s->data[s->top--];
}