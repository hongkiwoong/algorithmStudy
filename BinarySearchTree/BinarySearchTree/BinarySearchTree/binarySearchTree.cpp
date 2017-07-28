#include <iostream>
#include <queue>
using namespace std;

// BST의 장점 : search가 빠름 ! (log n) , 
// BST의 단점 : 그러나 최악의 경우를 보장해주지 않는다. 트리가 링크드리스트 처럼 편향된 경우 -> 따라서 AVL 트리를 사용하여 단점을 극복!

class binarySearchTree {
public:
	class Node{
	public:
		int num;
		Node* leftChild;
		Node* rightChild;
	};
	
	Node* root;
	Node* temp;
	queue<Node*> queue;
	int Node_count;

	binarySearchTree(int data);
	Node* search_Node(Node* root, int data);
	void insert_Node(Node* root, int data);
	void delete_Node(Node* root, int data);

	void showTree();
};

binarySearchTree::binarySearchTree(int data) {
	root = new Node;
	root->leftChild = NULL;
	root->rightChild = NULL;
	root->num = data;

	queue.push(root);
	Node_count = 1;
}

void binarySearchTree::showTree() {
	Node* tNode = queue.front();
	cout << tNode->num << endl;
	queue.pop();

	int loop = 1;
	int check = 1;
	int temp;

	for (int i = 0; i <=Node_count; i = temp) {
		for (int j = i; j < loop; j++) {
			if (tNode->leftChild != NULL) {
				cout << tNode->leftChild->num << "  ";
			}
			else {
				cout << "  ";
			}
			if (tNode->rightChild != NULL) {
				cout << tNode->rightChild->num << "  ";
			}
			else {
				cout << "  ";
			}
			tNode = queue.front();
			queue.pop();
			if (queue.empty()) {
				break;
			}
		}
		if (queue.empty()) {
			break;
		}
		cout << endl;
		temp = loop;
		loop += check * 2;
		check++;
	}
}

binarySearchTree::Node* binarySearchTree::search_Node(Node* root, int data) {
	temp = NULL;
	for (Node* tNode = root; tNode != NULL; tNode = temp) {
		if (tNode->num < data) {
			if (tNode->rightChild == NULL) {
				return tNode;
			}
			temp = tNode->rightChild;
		}
		else if (tNode->num == data) {
			return tNode;
		}
		else {
			if (tNode->leftChild == NULL) {
				return tNode;
			}
			temp = tNode->leftChild;
		}
	}
	return NULL;
}

void binarySearchTree::insert_Node(Node* root,int data) {
	Node* sNode = new Node;
	sNode->leftChild = NULL;
	sNode->rightChild = NULL;
	sNode->num = data;

	Node_count++;
	Node* tNode;
	tNode = search_Node(root, data);
	if (tNode->num <= sNode->num) {
		tNode->rightChild = sNode;
	}
	else {
		tNode->leftChild = sNode;
	}
	queue.push(sNode);
}

void binarySearchTree::delete_Node(Node* root, int data) {
	Node* dNode = search_Node(root, data);

		
	//자식이 없음
	if (dNode->leftChild == NULL && dNode->rightChild == NULL) {
		delete dNode;
		dNode = NULL;
	}
	//자식이 하나
	else if (dNode->leftChild !=NULL && dNode->rightChild == NULL) {
		dNode->num = dNode->leftChild->num;
		delete dNode->leftChild;
	}
	else if (dNode->leftChild == NULL && dNode->rightChild != NULL) {
		dNode->num = dNode->rightChild->num;
		delete dNode->rightChild;
	}
	// 자식이 여럿
	else {
		Node* findMax = dNode->rightChild;
		if (findMax->leftChild == NULL) {
			dNode->num = findMax->num;
			dNode->rightChild = findMax->rightChild;
			delete findMax;
		}
		else {
			while (findMax->leftChild != NULL) {
				findMax = findMax->leftChild;
			}
			dNode->num = findMax->num;
			delete findMax;
		}
	}
}

void main() {
	binarySearchTree BST(4);

	BST.insert_Node(BST.root, 2);
	BST.insert_Node(BST.root, 5);
	BST.insert_Node(BST.root, 1);
	BST.insert_Node(BST.root, 3);
	BST.insert_Node(BST.root, 7);
	BST.insert_Node(BST.root, 6);

	BST.delete_Node(BST.root,4);

	BST.showTree();
}