//Name: Kay Ratcliff
//Program name: Find smallest element
//Class: CS 172

#include <iostream>
using namespace std;

int *smallestElement(int *list, int size);


int main(){
	int list[8] = { 1, 2, 4, 5, 10, 100, 2, -22 };
	int *small = smallestElement(list, 8);
	cout << *small << endl;
}
int *smallestElement(int *list, int size){
	int *small = list;
	for (int i = 0; i < size; i++)
	{
		if (*small > *(list+i))
			small = list + i;
	}
	return small;
}