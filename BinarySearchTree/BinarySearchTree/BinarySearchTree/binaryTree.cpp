#include <iostream>
#include<queue>
using namespace std;

#define  MAX 100


// 이진트리 : 자식이 왼쪽, 오른쪽 둘. 나의 부모는 하나 !
// 주로 수식계산, pre, in ,post ->재귀와 프린트의 순서를 바꿔주면 된다. 


class Tree {
	class Node {
	public:
		int num;

		Node* leftChild;
		Node* rightChild;
	};
	
public:
	queue<Node*> Queue;
	Node* root_Node;
	
	Tree(int data);
	void insertTree(int data);
	void destroy(Node* dNode);
	void Show_in(Node* next);
	void Show_pre(Node* next);
};

Tree::Tree(int data) {
	root_Node = new Node;
	root_Node->leftChild = NULL;
	root_Node->rightChild = NULL;
	root_Node->num = data;

	Queue.push(root_Node);

}


void Tree::insertTree(int data) {
	Node* newNode = new Node;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	newNode->num = data;

	Queue.push(newNode);
	
	for (int i = 0; i < Queue.size(); i++) {
		Node* sNode = Queue.front();
		if (sNode->leftChild == NULL) {
			sNode->leftChild = newNode;
			break;
		}
		else if (sNode->rightChild == NULL) {
			sNode->rightChild = newNode;
			break;
		}
		Queue.pop();
	}
}

void Tree::destroy(Node* dNode) {
	if (dNode == NULL) {
		return;
	}
	destroy(dNode->leftChild);
	destroy(dNode->rightChild);
	delete dNode;
}

void Tree::Show_in(Node* next) {
	if (next == NULL) {
		return;
	}

	Show_in(next->leftChild);
	cout << next->num << "  ";
	Show_in(next->rightChild);
}

void Tree::Show_pre(Node* next) {
	if (next == NULL) {
		return;
	}

	cout << next->num << "  ";
	Show_pre(next->leftChild);
	Show_pre(next->rightChild);
}

void main() {
	Tree tree(3);
	tree.insertTree(4);
	tree.insertTree(5);
	tree.insertTree(6);

	tree.Show_in(tree.root_Node);
	cout << endl;
	tree.Show_pre(tree.root_Node);

	tree.destroy(tree.root_Node);

	tree.Show_in(tree.root_Node);
}