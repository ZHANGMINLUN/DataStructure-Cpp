// #include <stdio.h>
using namespace std;
#include <iostream>

template <class T>
void printArray(T* input, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("[%d]element: %d \r\n", i, input[i]);     // element of Array
		printf("[%d]pointerDec: %d \r\n", i, &input[i]); // pointer(Dec) of Array
		printf("[%d]pointerHex: %X \r\n", i, &input[i]); // pointer(Hex) of Array
	}
}

int main()
{
	int len;

	cout << "=======================pointer of number=========================" << endl;
	int number = 5;
	int* numberPointer = &number;
	printf("number: %d \r\n", number);
	printf("pointer of array: %p \r\n", &numberPointer);


	cout << "=======================pointer of Array=========================" << endl;
	int array[] = { 2, 5 };
	len = sizeof(array) / sizeof(int);
	printf("Overall: %p \r\n", &array);// overall Array
	printArray<int>(array, len);// elements in Array
	printf("Exceed: %p \r\n", &array[len]);// exceed length


	cout << "=======================pointer in Function=========================" << endl;
	short arrayFunc[4] = { 13, 0, 7, -10 };
	len = sizeof(arrayFunc) / sizeof(arrayFunc[0]);
	printArray<short>(arrayFunc, len);


	cout << "=======================malloc() with Pointer=========================" << endl;
	int* student;
	int maxN = 5;
	student = (int*)malloc(sizeof(int) * maxN); // dynamic 
	student[3] = 333;
	student[1] = 10;
	printArray<int>(student, maxN);

	cout << "=======================after free=========================" << endl;
	free(student);
	printArray<int>(student, maxN);

	return 0;
}
