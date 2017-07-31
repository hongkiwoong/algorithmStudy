#include <iostream>
#include <algorithm> 
using namespace std;

// ���� : �뷱���� �����־� �־��� ��쿡�� O(log n)�� �ð��� �������ش�.
// ���� : ���԰�, ������ ����� �����Ϳ� ���ؼ��� �뷱�� üũ�� �����̼� �ð��� ���� �ҿ�ȴ�. ( ������ �����Ϳ����� ���� )
// Ư¡ : BST �� �˻�, ����, ������ Ư¡�� ��� ������ �����鼭 Ž���ð��� ������ �شٴ� ������ �ִ�.
//        ������ BST�� ������ ������� �����ϰ�, �뷱�� üũ �� -2, +2 �� �� ���̰� ���� ��带 �����̼� �����־�� �Ѵ�. 

// �����̼� : LL , RR , RL, LR  4���� �����̼� ����� �ִ�.
//            LL�� ���ʿ� ���� ( ���� ����� ���� �ڽ��� left, ���� ����� �θ� �θ�, ���� ����� ���θ� right )
//            RR�� �����ʿ� ������ ( LL�� �ݴ� )
//            RL�� �����ʿ� ���� ( ������尡 �θ� �ǰ� ��������� �θ� right, ��������� ���θ� left �ڽ��� �ȴ�. )
//            LR�� RL �� �ݴ�

class AVL_TREE {
	class Node {
	public:
		int num;
		int blance;
		Node* leftChild;
		Node* rightChild;
	};

public:
	Node* root;

	Node* grandNode;
	Node* parentNode;
	Node* childNode;
	Node* bigNode;

	AVL_TREE(int data);
	void insert_Node(Node* root, int data);
	void delete_Node(Node* root, int data);
	Node* search_Node(Node* root, Node* targetNode , int data);
	Node* isRotate(Node* targetNode);
	int isBalance(Node* targetNode);
	int checkHeight(Node* targetNode);

	Node* RR(Node* parent);
	Node* LL(Node* parent);
	Node* RL(Node* parent);
	Node* LR(Node* parent);

	int balance_check;
};

AVL_TREE::AVL_TREE(int data) {
	root = new Node;
	root->num = data;
	root->blance = 0;
	root->leftChild = NULL;
	root->rightChild = NULL;
}

void AVL_TREE::insert_Node(Node* root,int data) {
	Node* sNode = new Node;
	sNode->blance = 0;
	sNode->num = data;
	sNode->leftChild = NULL;
	sNode->rightChild = NULL;

	Node* temp = root;
	while (1) {

		if (temp->num >= data) {
			if (temp->leftChild != NULL) {
				temp = temp->leftChild;
				continue;
			}
			else {
				temp->leftChild = sNode;
				root = isRotate(root);
				break;
			}
		}
		else {
			if (temp->rightChild != NULL) {
				temp = temp->rightChild;
				continue;
			}
			else {
				temp->rightChild = sNode;
				root = isRotate(root);
				break;
			}
		}

	}

}

void AVL_TREE::delete_Node(Node* root, int data) {
	Node* temp = root;
	Node* parent;
	int check = 0;
	
	while (1) {
		if (temp->num == data) break;

		if (temp->num > data) {
			parent = temp;
			temp = temp->leftChild;
			check = 0;
			continue;
		}
		if (temp->num < data) {
			parent = temp;
			temp = temp->rightChild;
			check = 1;
			continue;
		}
	}

	if (temp->leftChild == NULL && temp->rightChild == NULL) { //�ڽ��� ���� ��� ����
		if (check == 0) parent->leftChild = NULL;
		else parent->rightChild = NULL;
	}
	
	else if (temp->leftChild != NULL || temp->rightChild != NULL) { // �ڽ��� �ϳ��� ��� ����
		temp = temp->leftChild != NULL ? temp->leftChild : temp->rightChild;

		if (parent->num > data) parent->leftChild = temp;
		else parent->rightChild = temp;
	}

	else {
		//������ ��� �������� ū �� ã��
		Node* findMinNext = temp->rightChild;
		
		while (1) {
			if (findMinNext->leftChild != NULL) {
				parent = findMinNext;
				findMinNext = findMinNext->leftChild;
			}
			else {
				break;
			}
		}

		temp->num = findMinNext->num;
		parent->leftChild = NULL;
	}

}

AVL_TREE::Node* AVL_TREE::search_Node(Node* root, Node* targetNode ,int data) {
	return NULL;
}

AVL_TREE::Node* AVL_TREE::isRotate(Node* targetNode) {
	int depth = isBalance(targetNode);

	if (depth > 1)// ���� ���� Ʈ���� ���� ������� �Ѵ�.
	{
		if (isBalance(targetNode->leftChild) > 0) {
			targetNode = LL(targetNode);
		}
		else {
			targetNode = LR(targetNode);
		}
	}
	else if (depth < -1) { //������ ���� Ʈ���� ������Ѵ�.
		if (isBalance(targetNode->rightChild) < 0) {
			targetNode = RR(targetNode);
		}
		else {
			targetNode = RL(targetNode);
		}
	}
	return targetNode;
}

int AVL_TREE::isBalance(Node* targetNode) {
	if (targetNode == NULL) { return 0; }

	return checkHeight(targetNode->leftChild) - checkHeight(targetNode->rightChild);
}

int AVL_TREE::checkHeight(Node* targetNode) {
	int height = 0;
	if (targetNode != NULL) {
		height = 1 + max(checkHeight(targetNode->leftChild),checkHeight(targetNode->rightChild));
	}
	return height;
}

AVL_TREE::Node* AVL_TREE::RR(Node* parent) {
	Node* child = parent->rightChild;
	parent->rightChild = child->leftChild;
	child->leftChild = parent;
	return child;
}

AVL_TREE::Node* AVL_TREE::LL(Node* parent) {
	Node* child = parent->leftChild;
	parent->leftChild = child->rightChild;
	child->rightChild = parent;
	return child;
}

AVL_TREE::Node* AVL_TREE::RL(Node* parent) {
	Node* child = parent->rightChild;
	parent->rightChild = LL(child);
	return RR(parent);
}

AVL_TREE::Node* AVL_TREE::LR(Node* parent) {
	Node* child = parent->leftChild;
	parent->leftChild = RR(child);
	return LL(parent);
}

void main() {
	AVL_TREE avl(9);

	avl.insert_Node(avl.root,9);
	avl.insert_Node(avl.root, 10);
	avl.insert_Node(avl.root, 2);
	avl.insert_Node(avl.root, 1);
	avl.insert_Node(avl.root, 5);
	avl.insert_Node(avl.root, 3);
	avl.insert_Node(avl.root, 6);
	avl.insert_Node(avl.root, 4);
	avl.insert_Node(avl.root, 7);
	avl.insert_Node(avl.root, 11);
	avl.insert_Node(avl.root, 12);
	cout << avl.root->num;
	//avl.delete_Node(avl.root, 7);
}