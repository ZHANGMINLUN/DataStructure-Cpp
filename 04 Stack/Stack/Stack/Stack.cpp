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

//element pop(stackADT* s) {
//	if(isEmpty())
//}

int maintest()
{
	int a = 10;
	int* ptr1 = &a;
	int** ptr2 = &ptr1;

	printf("The address of a is %p\n", &a);
	printf("The address of ptr1 is %p\n", &ptr1);
	printf("The address of ptr2 is %p\n", &ptr2);

	printf("The value of ptr1 is %p\n", ptr1);
	printf("The value of ptr2 is %p\n", ptr2);
	printf("The value of *ptr2 is %p\n", *ptr2);

	printf("value of a: %d\n", a);
	printf("value of *ptr1(point to variable a): %d\n", *ptr1);
	printf("value of **ptr2(point to variable a): %d\n", **ptr2);

	return 0;
}
int main()
{
	//====================initialize====================//
	stackADT s;
	s.top = -1;
	maintest();

}

