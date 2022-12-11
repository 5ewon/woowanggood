#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

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
int partition(element list[][20], int left, int right);
void quicksort(element list[][20], int left, int right);

int main() {
	int menu;
	element* data = NULL;
	Stack s;
	initStack(&s);
	printf("┌───────────────┐\n"
		   "│   WOOWANGOOD  │ \n"
		   "└───────────────┘\n");
	do {
		printf("=========================================================================\n");
		printf(" 검색 : 1 \n 검색기록 삭제 : 2 \n 검색기록 조회 : 3 \n 검색기록 정렬 : 4 \n 종료 : 0 \n\n 수행할 작업을 선택하세요 : ");
		scanf("%d", &menu);
		switch (menu) {
		case 1:
			printf(" 검색어 입력 : ");
			push(&s);
			printf("\n\n\n");
			break;
		case 2:
			data = pop(&s);
			printf(" 삭제된 검색어 : ");
			printf("%s", data);
			printf("\n\n\n\n");
			break;
		case 3:
			printf("\n ──── 최근 검색 내역 ──── \n");
			for (int i = 0; i<= s.top; i++) {
				printf("ㄴ %s \n", s.data[i]);
			}
			break;
		case 4:
			printf("\n ──── 최근 검색 기록 정렬 ──── \n");
			quicksort(s.data, 0, s.top);
			for (int i = 0; i <= s.top; i++) {
				printf("ㄴ %s \n", s.data[i]);
			}
			break;
		case 0:
			break;
		default:
			printf(" 잘못된 입력 입니다. \n");
			break;
		}
	} while (menu);
}
	
void initStack(Stack* s) {
	s->top = -1;
	int i = 0;
}
int isFull(Stack* s) {
	return s->top == STACK_SIZE - 1;
}
int isEmpty(Stack* s) {
	return s->top == -1;
}
void push(Stack* s) {
	if (isFull(s)) {
		printf("── FULL ──\n");
		return;
	}
	s->top++;
	scanf("%s", s->data[s->top]);

}
element* pop(Stack* s) {
	if (isEmpty(s)) {
		printf("── EMPTY ──\n");
		return 0;
	}
	s->data[s->top][0] = NULL;
	return s->data[s->top--];
}
void swap(element x[], element y[], element t[]) {
	strcpy(t, x);
	strcpy(x, y);
	strcpy(y, t);
}

int partition(element list[][20], int left, int right)
{
	int low, high;
	element pivot;
	element temp[20];
	low = left;
	high = right + 1;
	pivot = list[left][0];
	do {
		do {
			low++;
		} while (list[low][0] < pivot && low <= right);
		do {
			high--;
		} while (list[high][0] > pivot);

		if (low < high) {
			swap(list[low], list[high], temp);
		}
	} while (low < high);

	swap(list[left], list[high], temp);
	return high;
}

void quicksort(element list[][20], int left, int right)
{
	if (left < right)
	{
		int q = partition(list, left, right);
		quicksort(list, left, q - 1);
		quicksort(list, q + 1, right);
	}
}
