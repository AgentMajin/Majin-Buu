#include "Header.h"
#include <iostream>

using namespace std;

//khai bao danh sach lien ket don
struct Node {
	int data;
	Node* next;
};

Node* head = NULL;
Node* tmp;

//khoi tao mot node moi
void createNode(int x) { 
	Node* node = new Node();
	node->data = x;

	if (head == NULL) {
		head = node;
		return;
	}

	node->next = head;
	head = node;
}

//them dau
void addFirst(int x) {
	Node* node = new Node();
	node->data = x;
	node->next = head;
	head = node;
}

//them cuoi
void addLast(int x) {
	Node* node = new Node();
	node->data = x;
	node->next = NULL;

	tmp = head;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = node;
}

//them sau 1 vi tri bat ky
void addPos(int data, int x) {
	Node* node = new Node();
	node->data = data;

	tmp = head;
	for (int i = 0; i < x - 1; i++) {
		tmp = tmp->next;
	}
	node->next = tmp->next;
	tmp->next = node;
}

//duyet danh sach
void printAll() {
	tmp = head;
	while (tmp != NULL)
	{
		cout << tmp->data << endl;
		tmp = tmp->next;
	}
}

//dem so phan tu
int size() {
	int size = 0;
	tmp = head;
	while (tmp != NULL) {
		size += 1;
		tmp = tmp->next;
	}
	return size;
}

//tim kiem
bool search(int x) {
	tmp = head;
	while (tmp != NULL) {
		if (tmp->data == x) {
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

//kiem tra danh sach rong
bool isEmpty() {
	if (head == NULL) {
		return true;
	}
	return false;
}

//xoa dau
void removeFirst() {
	tmp = head;
	head = head->next;
	tmp->next = NULL;
	delete tmp;
}

//xoa cuoi
void removeLast() {
	tmp = head;
	while (tmp->next->next != NULL) {
		tmp = tmp->next;
	}
	delete tmp->next;
	tmp->next = NULL;
}

//xoa sau 1 vi tri bat ky
void removePos(int x) {
	tmp = head;
	Node* ptr;
	for (int i = 0; i < x - 1; i++) {
		tmp = tmp->next;
	}
	ptr = tmp->next;
	tmp->next = ptr->next;
	ptr->next = NULL;
	delete ptr;
}

#ifdef SLL
int main() {
	createNode(3);
	createNode(5);
	createNode(2);
	createNode(1);

	addFirst(9);
	addLast(11);
	addPos(15, 3);

	removeFirst();
	removeLast();
	removePos(2);

	printAll();

	return 0;
}
#endif