#include <iostream>

//====================Circular Linked List====================//
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

CircularLinkedList* setupCircularNode(int n) {
    CircularLinkedList* CList = (CircularLinkedList*)malloc(sizeof(CircularLinkedList)*n);
    for (int i = 0; i < n; i++) {
        CList[i].data = (int)rand();
        if (i != n - 1)CList[i].linkRef = &CList[i + 1];
        else CList[i].linkRef = &CList[0];
    }

    return CList;
}


//====================Doubly Linked List====================//
struct DoublyLinkedList {
    int data;
    DoublyLinkedList* rlinkRef;
    DoublyLinkedList* llinkRef;
};

void printThruNode(DoublyLinkedList* node) {

    DoublyLinkedList* w = node;
    int n = 0;

    while (w != NULL) {
        printf("node%d: %p\r\n", n, w);
        printf("node%d data: %d\r\n", n, w->data);
        printf("node%d rlink: %p\r\n", n, w->rlinkRef);
        printf("node%d llink: %p\r\n", n, w->llinkRef);
        w = w->rlinkRef;
        n++;
    }
}

bool insertDoubly(DoublyLinkedList* list, DoublyLinkedList* node, int data)
{
    // define data in insertNode
    DoublyLinkedList* insertNode = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));

    //check if run out of meomory
    if (insertNode == NULL)return false;
    insertNode->data = data;

    //check if list exist
    if (list == NULL)return false;
    else
    {
        // rlinkRef
        insertNode->rlinkRef = node->rlinkRef;
        node->rlinkRef = insertNode;

        // llinkRef
        insertNode->llinkRef = node;
        insertNode->rlinkRef->llinkRef = insertNode;
        return true;
    }
    
}

DoublyLinkedList* setupDoublyNode(int n) {
    DoublyLinkedList* CList = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList )*n);
    for (int i = 0; i < n; i++) {
        CList[i].data = (int)rand();
        if (i == 0) {
            CList[i].rlinkRef = &CList[i + 1];
            CList[i].llinkRef = NULL;
        }
        else if (i == n - 1) {
            CList[i].rlinkRef = NULL;
            CList[i].llinkRef = &CList[i - 1];
        }
        else {
            CList[i].rlinkRef = &CList[i + 1];
            CList[i].llinkRef = &CList[i - 1];
        }
    }

    return CList;
}

//===========================main===========================//
int main()
{
    CircularLinkedList* cir = setupCircularNode(3);
    printThruNode(cir);

    printf("=================================\r\n");
    DoublyLinkedList* dou = setupDoublyNode(5);
    printThruNode(dou);

    printf("=================================\r\n");
    insertDoubly(dou, &dou[2], 123);
    printThruNode(dou);

    return 0;
}

