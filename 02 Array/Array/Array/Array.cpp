// Array.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//
using namespace std;
#include <iostream>

int insertElement(int value, int location, int* array, int len);

int deleteElement(int location, int* array, int len);

template <class T>
void printArray(T* input, int len);

template <class T>
int countLength(T* input);

char* copyArray(char* input);


int main()
{
	cout << "=======================Array Operation=========================" << endl;
	int array[] = { 2, 15, -8, 9, -5,8 };
	int len = sizeof(array) / sizeof(array[0]);
	insertElement(100, 2, array, len);
	deleteElement(len-1, array, len);
	printArray(array, len);

	cout << "=======================String Operation=========================" << endl;
	//char s[] = "Welcome";
	//int len = sizeof(s) / sizeof(s[0]);
	//printArray(s, len);
	//printf("%d", countLength(s));

	char input[] = "fjweo";
	char* output = copyArray(input);
	printArray(output, countLength(input) + 1);
}

int insertElement(int value, int location, int* array, int len) {

	if (len < 0)return-1;
	for (int i = len - 1; i > location; i--) {
		array[i] = array[i - 1];
	}
	array[location] = value;
	return 0;
}

int deleteElement(int location, int* array, int len) {

	if (location >= len)return-1;
	for (int i = location; i < len - 1; i++) {
		array[i] = array[i + 1];
	}
	array[len - 1] = 0;
	return 0;
}

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

template <class T>
int countLength(T* input) {
	int n = 0;
	while (input[n] != '\0') {
		n++;
	}
	return n;
}

char* copyArray(char* input) {

	int len = countLength(input) + 1;
	char* output = (char*)malloc(len);

	int n = 0;
	while (input[n] != '\0') {
		output[n] = input[n];
		n++;
	}
	output[n] = '\0';

	return output;
}

