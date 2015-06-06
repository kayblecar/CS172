//Name: Kay Ratcliff
//Program name: Increase array size
//Class: CS 172

#include <iostream>
using namespace std;

int* doubleCapacity(const int*list, int size);

int main(){
	int size1;
	cin >> size1;
	int* list1 = new int[size1];
	int *list2 = doubleCapacity(list1, size1);

	return 0;
}

int* doubleCapacity(const int*list, int size){
	int *newList = new int[2 * size];
	return newList;
}