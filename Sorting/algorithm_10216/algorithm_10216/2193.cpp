#include <iostream>
using namespace std;

#define MAX 91

int main() {
	int num = 0;
	cin >> num;

	long long arr[MAX];
	arr[0] = 1;
	arr[1] = 1;
	if (num == 1 || num == 2) {
		cout << arr[0];
		return 0;
	}
	int result = 0;

	for (int i = 2; i <= num; i++) {
		arr[i] = arr[i - 2] + arr[i - 1];
	}
	cout << arr[num-1];

	return 0;
}