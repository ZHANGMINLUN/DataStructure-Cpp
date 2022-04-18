#include <iostream>

typedef struct {
    int itemKey;
}element;

#define maxCQueueSize 5
typedef struct {
    element cQueue[maxCQueueSize];
    int front;
    int rear;
}circularQueueADT;

bool isFrontEqRear(circularQueueADT* cQ) {
    if (cQ->front == cQ->rear)return true;
    else return false;
}

//bool isFull(circularQueueADT* cQ) {
//    if (cQ->front == cQ->rear)return true;
//    else return false;
//}
//
//bool isEmptyOrFull(circularQueueADT* cQ) {
//    cQ->rear = (cQ->rear + 1) % maxCQueueSize;
//    if (cQ->front == cQ->rear)return true;
//    else return false;
//}


void addCQueue(circularQueueADT* cQ, element e) {
    cQ->rear = (cQ->rear + 1) % maxCQueueSize;
    if (isFrontEqRear(cQ)) {
        printf("Circular Queue is Full!");
        exit(1);
    }
    else
    {
        cQ->cQueue[cQ->rear] = e;
    }
}

element deleteCQueue(circularQueueADT* cQ) {
    if (isFrontEqRear(cQ)) {
        printf("Circular Queue is Empty!");
        exit(1);
    }
    else {
        cQ->front = (cQ->front + 1) % maxCQueueSize;
        return cQ->cQueue[++cQ->front];
    }
}

void printCQueue(circularQueueADT* cQ) {
    for (int i = 0; i < maxCQueueSize; i++) {
        printf("| Q[%d]: %d |—", i, cQ->cQueue[i]);
    }
}

int main()
{
    circularQueueADT cQ;
    cQ.front = 0;
    cQ.rear = 0;
    element e;

    for (int i = 0; i < 20; i++) {
        e.itemKey = i + 1;
        addCQueue(&cQ, e);
        printf("\r\n");
        printCQueue(&cQ);
    }

}


