#include <iostream>
using namespace std;

// ������ ���� �켱 Ž�� ( DFS ) �˰��򿡼� �ٰ����� ���Ǵ� �ڷᱸ��.
// �پ��� �˰��򿡼� ���ǳ� �� ������ �˰� ! ���

class LinkedList_stack {
	class Node {
	public:
		int num;
		Node* next;
	};
public:
	LinkedList_stack();
	Node* head = new Node;
	Node* temp = new Node;

	void showStack();
	void stack_push(int data);
	void stack_pop();
};

LinkedList_stack::LinkedList_stack() {
	Node* next = new Node;
	next = NULL;
	head->next = NULL;
	temp = NULL;
}

void LinkedList_stack::showStack() {
	for (Node* pNode = head->next; pNode != NULL; pNode = pNode->next) {
		cout << pNode->num << "  ";
	}
}

void LinkedList_stack::stack_push(int data) {
	Node* newNode = new Node;
	newNode->num = data;
	newNode->next = NULL;

	if (head == NULL) {
		head->next = newNode;
		temp = newNode;
		newNode->next = NULL;
	}
	else {
		newNode->next = temp;
		head->next = newNode;
		temp = newNode;
	}
}

void LinkedList_stack::stack_pop() {
	Node* temp = new Node;
	temp = head->next;
	head->next = head->next->next;
}

void main() {
	LinkedList_stack stack;

	stack.stack_pop(1);
	stack.stack_pop(3);
	stack.stack_pop(7);
	stack.stack_pop(5);

	stack.stack_push();

	stack.showStack();
}