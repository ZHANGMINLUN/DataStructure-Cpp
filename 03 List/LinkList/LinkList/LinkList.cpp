using namespace std;
#include <iostream>

struct listNodeRef
{
	int data;
	struct listNodeRef* linkRef;
};

struct CircularList {
	int data;
	CircularList* llink;
	CircularList* rlink;
};

listNodeRef* getNode() {

	listNodeRef* node = (listNodeRef*)malloc(sizeof(listNodeRef));

	return node;
}

int main()
{
	cout << "=======================Singly Linked List=========================" << endl;
	listNodeRef* n1, * n2, * n3;
	listNodeRef* nodes[3];
	for (int i = 0; i < sizeof(nodes) / sizeof(nodes[0]); i++) {
		nodes[i] = getNode();
	}

	nodes[0] = getNode();
	nodes[0]->data = 111;
	nodes[0]->linkRef = nodes[1];

	nodes[1] = getNode();
	nodes[1]->data = 222;
	nodes[1]->linkRef = nodes[2];

	nodes[2] = getNode();
	nodes[2]->data = 333;
	nodes[2]->linkRef = NULL;

	printf("node1 data: %d\r\n", nodes[0]->data);
	printf("node1 link: %p\r\n", nodes[0]->linkRef);
	printf("node2 data: %d\r\n", nodes[1]->data);
	printf("node2 link: %p\r\n", nodes[1]->linkRef);
	printf("node3 data: %d\r\n", nodes[2]->data);
	printf("node3 link: %p\r\n", nodes[2]->linkRef);

	cout << "=======================Singly Linked List=========================" << endl;





	return 0;
}

