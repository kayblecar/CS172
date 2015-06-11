//Name: Kay Ratcliff
//Program name: Linear search
//Class: CS 172

#include<iostream>
#include<string>
using namespace std;

template<typename T>
int linearSearch(const T list[], T key, int arraySize);

int main(){
	int intarray[3] = { 5, 6, 8 };
	double darray[3] = { 5.5, 6.48, 3.6 };
	string strarray[3] = { "hello", "world", "hi" };
	string hi = "hi";

	cout << linearSearch(intarray, 5, 3) << endl; //0
	cout << linearSearch(darray, 5.8, 3) << endl; //-1
	cout << linearSearch(strarray, hi , 3) << endl; //2
}

template<typename T>
int linearSearch(const T list[], T key, int arraySize){
	for (int i = 0; i < arraySize; i++){
		if (key == list[i])
			return i;
	}
	return -1;
}