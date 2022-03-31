#include <iostream>


struct CircularLinkedList {
    int data;
    CircularLinkedList* linkRef;
};

void printThruNode(CircularLinkedList* node) {

    CircularLinkedList* w = node;
    int n = 0;
    if (node != NULL) {
        do
        {
            printf("node%d: %p\r\n", n, w);
            printf("node%d data: %d\r\n", n, w->data);
            printf("node%d link: %p\r\n", n, w->linkRef);
            w = w->linkRef;
            n++;
        } while (w != node);
    }
}

//#include <stdlib.h>
CircularLinkedList* setupNode(int n) {
    CircularLinkedList* CList = (CircularLinkedList*)malloc(n);
    for (int i = 0; i < n; i++) {
        CList[i].data = rand();
        if (i != n - 1)CList[i].linkRef = &CList[i + 1];
        else CList[i].linkRef = &CList[0];
    }
    printThruNode(CList);

    return CList;
}

int main()
{
    setupNode(5);
}

