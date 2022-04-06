#include <iostream>

typedef struct {
	int ItemKey;
}element;

#define maxStackSize 100
typedef struct {
	element stack[maxStackSize];
	int top;
}stackADT;

bool isEmpty(stackADT s) {
	if (s.top < 0)return true;
	else return false;
}

bool isFull(stackADT s) {
	if (s.top >= maxStackSize - 1)return true;
	else return false;
}

void push(stackADT* s, element e) {
	if (isFull(*s) == true) {
		printf("Stack is Full!");
		exit(1);
	}
	else {
		//s->stack[++(s->top)] = e;
		s->top++;
		s->stack[s->top] = e;
	}
}

element pop(stackADT* s) {

	if (isEmpty(*s) == true) {
		printf("Stack is Empty!");
		exit(1);
	}
	else {
		return s->stack[--s->top];
	}
}

void printStack(stackADT* s) {
	for (int i = s->top; i >= 0; i--) {
		printf("S[%d] |  %d  |\r\n", i, s->stack[i]);
	}
}

int main()
{
	//====================initialize====================//
	stackADT s;
	s.top = -1;

	element item;
	item.ItemKey = 5;
	push(&s, item);

	item.ItemKey = -9;
	push(&s, item);

	item.ItemKey = 3;
	push(&s, item);

	pop(&s);

	item.ItemKey = 66;
	push(&s, item);

	item.ItemKey = 2;
	push(&s, item);

	pop(&s);

	printStack(&s);
}

