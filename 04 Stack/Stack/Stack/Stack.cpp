#include <iostream>

typedef struct {
	int ItemKey;
}element;

#define maxStackSize 100
typedef struct {
	element stack[maxStackSize];
	int top;
}stackADT;


int main()
{
	//====================initialize====================//
	stackADT s;
	s.top = -1;


}

