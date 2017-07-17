#include <iostream>
using namespace std;

//장점
// 동적으로 메모리를 사용할 수 있다
// 배열이 가지고 있는 단점( 삽입과 삭제에 있어서 )을 극복 ! , 삽입 삭제 용이
//단점
// search 에 있어서는 발전 x
// 주소를 저장하기 때문에 추가적인 메모리 요구

//이중 링크드 리스트
// 장점 : 한 노드에서 다른 노드로의 접근 가능(앙뱡향)
//환영 링크드 리스트
// 장점 : 한 노드에서 다른 노드로의 접근 가능(앙뱡향)
// 단점 : 무한루프에 빠질 가능성이 있다. - 결국 검색을 끝낼 노드를 주는 것이 좋다


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