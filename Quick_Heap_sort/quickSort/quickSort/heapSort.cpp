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
	�� ���� : �迭�� ����Ͽ����� Ʈ��������� �����ϴ� ���� ����. �θ�� �ڽĺ��� ũĿ�� Ȥ�� ���� ��������Ʈ�� �μ� ���� ū ���� ��Ʈ�� �÷� 
			  ��Ʈ�� ���� ������� �����ϴ� �����μ� n log n �� �ð��� �ɸ���.  �����ϴµ� log n �ð�. n�� ����

	���� : ���� ���� �ð��� ���� �� �� �ִ� ������ �ִ�.
	���� : �迭 �� Ʈ���� �籸���ϴµ� �ҿ�Ǵ� �ð��� �ʿ��ϴ�. 
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
	cout << "�Է��� ���� ������ �Է��Ͻÿ� :  ";
	cin >> loop;
	int* arr = new int[loop];//���ڴ� 7���� �޴´�. 
	for (int i = 0; i < loop; i++) {
		arr[i] = 0;
	}
	cout << "������ ������ ������ �Է��Ͻÿ� :  ";
	scanf("%d", &k);

	for (int i = 0; i < loop; i++) {		
		cout << "���ڸ� �Է����ּ��D :  ";
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