#include "Header.h"
#include <iostream>

using namespace std;

struct CircularLinkedList {
	int data;
	CircularLinkedList* next;
};

typedef struct CircularLinkedList Node;

Node* tail, * tmp; //global variables
Node* head = NULL; //global variables
int length = 0; //count the elements

Node* setNode(int x) {
	Node* node = new Node();
	node->data = x;
	node->next = NULL;
	return node;
}

void addLast(int x) {
	Node* node = setNode(x);

	tail->next = node;
	node->next = head;
	tail = node;
}

void addFirst(int x) {
	Node* node = setNode(x);

	node->next = head;
	tail->next = node;
	head = node;
}

void addPos(int x, int pos) {
	Node* node = setNode(x);

	tmp = head;
	for (int i = 0; i < pos - 1; i++)
		tmp = tmp->next;
	node->next = tmp->next;
	tmp->next = node;
}

void removeFirst() {
	//tmp = head;
	//head = head->next;
	//tail->next = head;
	//tmp->next = NULL;

	tail->next = head->next;
	head = tail->next;
}

void removeLast() {
	tmp = head;
	while (tmp->next != tail)
		tmp = tmp->next;
	tail->next = NULL;
	tmp->next = head;
	tail = tmp;
}

void removePos(int pos) {
	tmp = head;
	for (int i = 0; i < pos - 1; i++)
		tmp = tmp->next;
	tmp->next = tmp->next->next;
}

void createNode(int x) {
	Node* node = setNode(x);

	if (head == NULL) {
		head = node; //set head = node;
		tail = node; //set tail = node;
	}
	else {
		tail->next = node;
		tail = node;
		node->next = head;
	}

	length++;
}

void printAll() {
	tmp = head;
	while (tmp->next != head) {
		cout << tmp->data << endl;
		tmp = tmp->next;
	}
	cout << tmp->data << endl;
}

#ifdef __PRACTICE6__
void main() {
	createNode(2);
	createNode(4);
	createNode(6);

	addFirst(5);
	addLast(3);
	addPos(9, 2);

	removeFirst();
	removeLast();
	removePos(2);

	printAll();

	cout << "Number of the element: " << length;
}
#endif // __PRACTICE6__
