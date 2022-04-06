#include <iostream>

typedef struct {
	int ItemKey;
}element;

#define maxQueueSize 100
typedef struct {
	element queue[maxQueueSize];
	int front;
	int rear;
}queueADT;

bool isEmpty(queueADT* q) {
	if (q->front >= q->rear)return true;
	else  return false;
}

bool isFull(queueADT* q) {
	if (q->rear >= maxQueueSize)return true;
	else return false;
}

void addQueue(queueADT* q, element e) {
	if (isFull(q)) {
		printf("Queue is Full!");
		exit(1);
	}
	else {
		q->queue[++q->rear] = e;
	}
}

element deleteQueue(queueADT* q) {
	if (isEmpty(q)) {
		printf("Queue is Empty!");
		exit(1);
	}
	else {
		return q->queue[++q->front];
	}
}

void printQueue(queueADT* q) {
	for (int i = q->front; i <= q->rear; i++) {
		printf("| Q[%d]:%d |-- ", i, q->queue[i]);
	}
}

int main()
{
	//initialize
	queueADT q;
	q.front = 0;
	q.rear = -1;
	element e;

	isEmpty(&q);

	printf("\r\nAdd 0~5: ");
	int i = 0;
	for (; i < 6; i++) {
		e.ItemKey = i;
		addQueue(&q, e);
	}
	
	//printQueue
	printQueue(&q);

	//deleteQueue
	deleteQueue(&q);

	//printQueue
	printf("\r\nDelete: ");
	printQueue(&q);

	for (; i < 10; i++) {
		e.ItemKey = i;
		addQueue(&q, e);
	}

	printf("\r\nAdd 6~9: ");
	printQueue(&q);

	deleteQueue(&q);
	printf("\r\nDelete: ");
	printQueue(&q);
}

