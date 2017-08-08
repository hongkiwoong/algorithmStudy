#include <iostream>
using namespace std;

/*class HeapTree {
	class Node {
	public:
		int num;
		Node* leftChild;
		Node* rightChild;
	};

public:
	HeapTree();
	Node* root;
	void insertNode(int data);
	Node* searchNode(int data);
	void deleteNode(int data);
};

HeapTree::HeapTree(){
	root = new Node;
	root = NULL;
	root->leftChild = NULL;
	root->rightChild = NULL;
}

void HeapTree::insertNode(int data) {
	if (root == NULL) {
		root->num = data;
	}
	else {
		Node* nNode = new Node;
		nNode->num = data;
		nNode->leftChild = NULL;
		nNode->rightChild = NULL;

		for (Node* i = root; i != NULL; i = i) {

		}
	}	
	
}

HeapTree::Node* HeapTree::searchNode(int num) {

}

void HeapTree::deleteNode(int num) {

}
*/

 
/*
	힙 정렬 : 배열을 사용하였지만 트리구조라고 생각하는 것이 쉽다. 부모는 자식보다 크커나 혹은 작은 완전이진트리 로서 가장 큰 수를 루트로 올려 
			  루트의 수를 순서대로 정렬하는 것으로서 n log n 의 시간이 걸린다.  삽입하는데 log n 시간. n번 추출

	장점 : 비교적 빠른 시간에 정렬 할 수 있는 장점이 있다.
	단점 : 배열 및 트리를 재구성하는데 소요되는 시간이 필요하다. 
*/




void array_swap(int * arr, int a, int b)
{
	int temp;
	temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void Heapify(int * arr, int parent_position, int heap_size)
{
	int left, right, largest;
	left = 2 * parent_position + 1;
	right = 2 * parent_position + 2;

	if ((left<heap_size) && (arr[left]>arr[parent_position]))
		largest = left;
	else
		largest = parent_position;

	if ((right<heap_size) && (arr[right]>arr[largest]))
		largest = right;

	if (largest != parent_position)
	{
		array_swap(arr, parent_position, largest);
		Heapify(arr, largest, heap_size);
	}
}

void Build_Heap(int * arr, int length)
{
	int parent_position;

	for (parent_position = length / 2 - 1; parent_position >= 0; parent_position--)
		Heapify(arr, parent_position, length);
}

void Heap_Sort(int * arr, int length, int k)
{
	Build_Heap(arr, length);
	int last_row;
	int count = 0;

	for (last_row = length - 1; last_row>0; last_row--)
	{
		if (count == k)
			break;
		array_swap(arr, 0, last_row);
		length--;
		count++;

		Heapify(arr, 0, length);
	}
}

void main() {
	int length = 10;
	int k, i;

	int num;
	int loop;
	cout << "입력할 수의 갯수를 입력하시오 :  ";
	cin >> loop;
	int* arr = new int[loop];//숫자는 7개만 받는다. 
	for (int i = 0; i < loop; i++) {
		arr[i] = 0;
	}
	cout << "추출할 숫자의 갯수를 입력하시옹 :  ";
	scanf("%d", &k);

	for (int i = 0; i < loop; i++) {		
		cout << "숫자를 입력해주세묭 :  ";
		scanf("%d", &num);
		arr[i] = num;
	}
	Heap_Sort(arr, loop, k);

	for (i = loop - 1; i > (loop - 1) - k; i--)
		cout << arr[i] << "  ";

	cout << endl;
	for (i = 0; i <= (loop - 1) - k; i++)
		cout << arr[i] << "  ";

	cout << endl;
}