#include <iostream>
using namespace std;

//����
// �������� �޸𸮸� ����� �� �ִ�
// �迭�� ������ �ִ� ����( ���԰� ������ �־ )�� �غ� ! , ���� ���� ����
//����
// search �� �־�� ���� x
// �ּҸ� �����ϱ� ������ �߰����� �޸� �䱸

//���� ��ũ�� ����Ʈ
// ���� : �� ��忡�� �ٸ� ������ ���� ����(�ӓ���)
//ȯ�� ��ũ�� ����Ʈ
// ���� : �� ��忡�� �ٸ� ������ ���� ����(�ӓ���)
// ���� : ���ѷ����� ���� ���ɼ��� �ִ�. - �ᱹ �˻��� ���� ��带 �ִ� ���� ����


class LinkedList {
	class Node {
	public:
		int num;
		Node* next;
	};
public:
	Node* head = new Node;
	Node* tail = new Node;
	int size;

	void showList();

	LinkedList();
	void insert_List(int data);
};

LinkedList::LinkedList() {
	head->next = NULL;
	tail->next = NULL;
	head->num = -1;
	tail->num = -1;
}

void LinkedList::showList() {
	for (Node* curNode = head->next; curNode != tail; curNode = curNode->next) {
		cout << curNode->num << "  ";
	}
}

void LinkedList::insert_List(int data){
	Node* newNode = new Node;
	newNode->num = data;
	newNode->next = NULL;
	if (head->next == NULL) {
		newNode->next = tail;
		head->next = newNode;
		newNode->next = tail;
	}
	else {
		for (Node* curNode = head; curNode != tail; curNode = curNode->next) {
			if (curNode->next->num > newNode->num) {
				if (curNode == head) {
					newNode->next = head -> next;
					head->next = newNode;
				}
				else {
					newNode->next = curNode->next;
					curNode->next = newNode;
				}
				break;
			}
			else if(curNode->next == tail) {
				newNode->next = curNode->next;
				curNode->next = newNode;
				break;
			}
			
		}
	}
}


void main() {
	LinkedList list;
	list.insert_List(14);
	list.insert_List(12);
	list.insert_List(56);
	list.insert_List(13);

	list.showList();

	system("pause");
}