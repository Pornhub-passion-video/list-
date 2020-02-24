#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
using namespace std;

int main() {

	list<int> myList;
	for (int i = 0; i < 10; i++) {
		myList.push_back(i);
	}

	list<int>::_Nodeptr node = myList._Myhead->_Next;

	for (int i = 0; i < myList._Mysize * 2; i++) {
		cout << "Node:" << node->_Myval << endl;
		node = node->_Next;
		if (node == myList._Myhead) {
			node = node->_Next;
		}
	}

	system("pause");
	return EXIT_SUCCESS;
}
