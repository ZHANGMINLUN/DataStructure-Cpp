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
	if (node == NULL)printf("Run out of MEMORY!");
	return node;
}

void printThruNode(listNodeRef* node) {

	//listNodeRef* w = node;

	int n = 0;
	while (node != NULL) {
		//print detail
		printf("node%d: %p\r\n", n, node);
		printf("node%d data: %d\r\n", n, node->data);
		printf("node%d link: %p\r\n", n, node->linkRef);

		//go to next node
		node = node->linkRef;
		n++;
	}
}

bool insertList(listNodeRef* list, listNodeRef* node, int data) {
	//get address & check NULL
	listNodeRef* node_insert = getNode();
	if (node == NULL)return false;

	//set node 
	node_insert->data = data;
	node_insert->linkRef = NULL;

	if (list != NULL) {
		// node's link is the where list's link before
		node_insert->linkRef = node->linkRef;
		node->linkRef = node_insert;
	}
	else {
		list = node_insert;
	}

	return true;
}

void deleteList(listNodeRef* list, listNodeRef* d) {

	while (list != NULL)
	{
		if (list->linkRef == d) {
			list->linkRef = d->linkRef;
			free(d);
		}
		list = list->linkRef;
	}

}

void concatenateList(listNodeRef* list1, listNodeRef* list2) {
	while (list1 != NULL) {
		if (list1->linkRef == NULL) {
			list1->linkRef = list2;
			return;
		}
		list1 = list1->linkRef;
	}
}

int main()
{
	cout << "=======================Singly Linked List=========================" << endl;
	listNodeRef* nodes[3];
	for (int i = 0; i < sizeof(nodes) / sizeof(nodes[0]); i++) {
		nodes[i] = getNode();
	}

	nodes[0]->data = 111;
	nodes[0]->linkRef = nodes[1];

	nodes[1]->data = 222;
	nodes[1]->linkRef = nodes[2];

	nodes[2]->data = 333;
	nodes[2]->linkRef = NULL;

	printThruNode(nodes[0]);

	cout << "=======================Insert List=========================" << endl;
	insertList(nodes[0], nodes[1], 666);
	printThruNode(nodes[0]);

	cout << "=======================Delete List=========================" << endl;
	deleteList(nodes[0], nodes[1]);
	printThruNode(nodes[0]);

	cout << "=======================Concatenate List=========================" << endl;
	listNodeRef* nodes2[2];
	for (int i = 0; i < sizeof(nodes2) / sizeof(nodes2[0]); i++) {
		nodes2[i] = getNode();
	}

	nodes2[0]->data = 777;
	nodes2[0]->linkRef = nodes2[1];

	nodes2[1]->data = 288822;
	nodes2[1]->linkRef = NULL;

	concatenateList(nodes2[0], nodes[0]);
	printThruNode(nodes2[0]);


	return 0;
}

