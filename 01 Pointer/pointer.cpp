// #include <stdio.h>
using namespace std;
#include <iostream>

int main()
{
    cout << "=======================pointer of number=========================" << endl;
    int number = 5;
    int *numberPointer = &number;

    cout << "number: " << number << endl;
    cout << "Pointer of number: " << &numberPointer << endl;

    cout << "=======================pointer of Array=========================" << endl;
    int array[3] = {2, 5, 7};
    printf("pointer of array: %X \r\n", &array); // overall Array
    for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    {
        printf("[%d]element: %d \r\n", i, array[i]);     // element of Array
        printf("[%d]pointerDec: %d \r\n", i, &array[i]); // pointer(Dec) of Array
        printf("[%d]pointerHex: %X \r\n", i, &array[i]); // pointer(Hex) of Array
    }
    printf("pointer of array: %X \r\n", &array[sizeof(array) / sizeof(array[0])]); // pointer which exceed the length of Array

    return 0;
}