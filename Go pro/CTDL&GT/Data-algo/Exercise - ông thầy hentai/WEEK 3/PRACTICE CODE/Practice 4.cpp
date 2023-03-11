#include "Header.h"
#include <iostream>

using namespace std;

struct DoubleLinkedList {
	int data;
	DoubleLinkedList* next, * prev;
};

typedef struct DoubleLinkedList Node;

Node* head = NULL; //global variable: meaning data = NULL, next = NULL, prev = NULL
Node* tail, * tmp; //global variables

int length = 0; //count the number of elements in list

Node *setNode(int x) {
	Node *node = new Node();
	node->data = x;
	node->prev = NULL;
	node->next = NULL;
	return node;
}

void addFirst(int x) {
	Node* node = setNode(x);

	head->prev = node;
	node->next = head;
	head = node;

	length++;
}

void addLast(int x) {
	Node* node = setNode(x);

	tail->next = node;
	node->prev = tail;
	node->next = NULL;
	tail = node;

	length++;
}

void addPos(int x, int pos) {
	Node* node = setNode(x);

	tmp = head;
	for (int i = 0; i < pos - 1; i++) {
		tmp = tmp->next;
	}
	node->prev = tmp;
	node->next = tmp->next;
	tmp->next = node;
	tmp->next->prev = node;

	length++;
}

void removeFirst() {
	head = head->next;
	head->prev = NULL;

	length--;
}

void removeLast() {
	tail = tail->prev;
	tail->next = NULL;

	length--;
}

void removePos(int pos) {
	tmp = head;
	for (int i = 0; i < pos - 1; i++)
		tmp = tmp->next;
	tmp->next = tmp->next->next;
	tmp->next->prev = tmp;

	length--;
}

void createNode(int x) {
	Node* node = setNode(x);

	if (head == NULL) {
		head = node; //set head = node;
		tail = node; //set tail = node;
	}
	else {
		tail->next = node;
		node->prev = tail;
		tail = node;
	}

	length++;
}

void printAll() {
	tmp = head;
	while (tmp != NULL) {
		cout << tmp->data << endl;
		tmp = tmp->next;
	}
}

#ifdef __PRACTICE4__
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
#endif // __PRACTICE4__

