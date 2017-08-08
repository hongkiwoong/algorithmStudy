#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <math.h>
#include <stdio.h>
using namespace std;

class Node {
public:
	int x;
	int y;
	int length;
	Node* next;
	Node* queue_next;
};

bool cal(Node* node1, Node* node2) {
	int x1 = node1->x;
	int y1 = node1->y;
	int length1 = node1->length;

	int x2 = node2->x;
	int y2 = node2->y;
	int length2 = node2->length;

	long distance = sqrt(((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)));
	if (length1 + length2 >= distance) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int test_loop, node_loop;
	scanf("%d", &test_loop);//전체 테스트 반복
	int* result = new int[test_loop];

	int check = 0;
	int node_index=0;
	int n_x, n_y, n_length;
	queue<Node*> queue;
	Node* last = NULL;


	while (check < test_loop) {
	
		scanf("%d", &node_loop);//한 테스트 안의 노드 수 입력
		
		Node* newNode;
		for (int i = 0; i < node_loop; i++) { //한 테스트 안의 노드 수 만큼 반복
			scanf("%d %d %d", &n_x, &n_y, &n_length);

			newNode = new Node;
			newNode->x = n_x;
			newNode->y = n_y;
			newNode->length = n_length;
			newNode->next = NULL;
			newNode->queue_next = NULL;

			if (queue.size() == 0) {
				queue.push(newNode);
				last = newNode;
			}
			else {
				int size_check = 0;
				for (Node* sNode = queue.front(); sNode != NULL; sNode = sNode->queue_next) {
					for (Node* fNode = sNode; fNode != NULL; fNode = fNode->next) {
						if (cal(fNode, newNode)) {
						
							for (Node* n_fNode = fNode; fNode != NULL; n_fNode = fNode->next) {
								if (n_fNode->next == NULL) {
									n_fNode->next = newNode;
									size_check = 1;
									break;
								}
							}
							break;
						}
					}
				}
				if (size_check != 1) {
					queue.push(newNode);
				}
			}
		}
		result[check] = queue.size();
		while (!queue.empty()) { queue.pop(); }
		
		check++;
		delete newNode;
	}

	for (int i = 0; i < check; i++) {
		cout << result[i] << endl;
	}

	return 0;

}