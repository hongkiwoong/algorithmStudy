#include <iostream>
#include <algorithm> 
using namespace std;

// 장점 : 밸런스를 맞춰주어 최악의 경우에도 O(log n)의 시간을 보장해준다.
// 단점 : 삽입과, 삭제가 빈번한 데이터에 대해서는 밸런스 체크와 로테이션 시간이 많이 소요된다. ( 동적인 데이터에대한 단점 )
// 특징 : BST 의 검색, 삭제, 삽입의 특징을 모두 가지고 있으면서 탐색시간을 보장해 준다는 장점이 있다.
//        삭제시 BST와 동일한 방법으로 진행하고, 밸런스 체크 후 -2, +2 의 값 차이가 가는 노드를 로테이션 시켜주어야 한다. 

// 로테이션 : LL , RR , RL, LR  4가지 로테이션 방법이 있다.
//            LL은 왼쪽에 왼쪽 ( 리프 노드의 왼쪽 자식이 left, 리프 노드의 부모가 부모, 리프 노드의 조부모가 right )
//            RR은 오른쪽에 오른쪽 ( LL과 반대 )
//            RL은 오른쪽에 왼쪽 ( 리프노드가 부모가 되고 리프노드의 부모가 right, 리프노드의 조부모가 left 자식이 된다. )
//            LR은 RL 과 반대

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

	if (temp->leftChild == NULL && temp->rightChild == NULL) { //자식이 없는 노드 삭제
		if (check == 0) parent->leftChild = NULL;
		else parent->rightChild = NULL;
	}
	
	else if (temp->leftChild != NULL || temp->rightChild != NULL) { // 자식이 하나인 노드 삭제
		temp = temp->leftChild != NULL ? temp->leftChild : temp->rightChild;

		if (parent->num > data) parent->leftChild = temp;
		else parent->rightChild = temp;
	}

	else {
		//삭제할 노드 다음으로 큰 수 찾기
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

	if (depth > 1)// 왼쪽 서브 트리를 균형 맞춰줘야 한다.
	{
		if (isBalance(targetNode->leftChild) > 0) {
			targetNode = LL(targetNode);
		}
		else {
			targetNode = LR(targetNode);
		}
	}
	else if (depth < -1) { //오른쪽 서브 트리를 맞춰야한다.
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