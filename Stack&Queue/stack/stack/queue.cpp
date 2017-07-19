#include <iostream>
using namespace std;

// Ž�� �˰��� ���� �켱 Ž��( BFS ) �˰��򿡼� �ٰ����� ���̴� �˰���. 
// �ü������ �켱���� ť ���� ���

class LinkedList_queue {
	class Node {
	public:
		int num;
		Node* next;
	};
public:
	LinkedList_queue();
	Node* head = new Node;
	Node* tail = new Node;

	void showQueue();
	void queue_pop();
	void queue_push(int data);
};

LinkedList_queue::LinkedList_queue() {
	Node* next = new Node;
	head->next = NULL;
	tail = NULL;
}

void LinkedList_queue::showQueue() {
	for (Node* pNode = head->next; pNode != NULL; pNode = pNode->next) {
		cout << pNode->num << "  ";
	}
}

void LinkedList_queue::queue_pop() {
	if (head->next != NULL) {
		if (head->next->next != NULL) {
			Node* temp = new Node;
			temp = head->next;
			head->next = head->next->next;
			delete temp;
		}
		else {
			head->next = NULL;
		}
	}
}

void LinkedList_queue::queue_push(int data) {
	Node* newNode = new Node;
	newNode->next = NULL;
	newNode->num = data;

	if (head->next == NULL) {
		head->next = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		tail = newNode;
	}
}

void main() {
	LinkedList_queue linked_queue;

	linked_queue.queue_push(1);
	linked_queue.queue_push(3);
	linked_queue.queue_push(7);
	linked_queue.queue_push(5);

	linked_queue.queue_pop();

	linked_queue.showQueue();
}