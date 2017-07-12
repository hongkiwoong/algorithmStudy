#include <iostream>
#include <string>
using namespace std;

void main() {
	string name;
	int val;
	cout << "하하핳";
	cin >> val;

	int** arr_2 = new int*[10];
	for (int i = 0; i < 10; i++) {
		arr_2[i] = new int[3];
	}

	char ch[4] = { 'a', 'b', 'c', 'd' };
	char* ptr = ch;
	cout << *ptr;
	//출력후 값이 변경된다.
	cout << *ptr++;
	cout << *ptr;
}

void delete_arr(int** arr) {
	for (int i = 0; i < 10; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}