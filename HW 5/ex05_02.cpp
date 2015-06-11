//Name: Kay Ratcliff
//Program name: is sorted?
//Class: CS 172

#include <iostream>
#include <string>
using namespace std;

template <typename T>
bool isSorted(const T list[], int size);

int main(){
	int intarray[5] = { 5, 5, 4, 2, 1 };
	double darray[5] = { 1.0, 3.5, 5.8, 6.1, 9 };
	string strarray[5] = { "Luke", "I", "am", "your", "father" };

	cout << boolalpha << isSorted(intarray, 5) << endl; //true
	cout << boolalpha << isSorted(darray, 5) << endl; //true
	cout << boolalpha << isSorted(strarray, 5) << endl; //false
}

template <typename T>
bool isSorted(const T list[], int size){
	if (list[0] <= list[1]){ //check for sorted ascending
		for (int i = 2; i < size; i++){ //starting with second term to compare to previous term, already compared first two
			if (list[i-1] > list[i]){ // if the array does not continue following the pattern of the first two values, it is not sorted
				if (list[0] == list[1])
					continue; //allows list starting with repeat values to be checked for descending sort
				else
					return false;
			}
		}
	}

	if (list[0] >= list[1]){ //check for sorted descending
		for (int i = 2; i < size; i++){
			if (list[i-1] < list[i])
				return false;
		}
	}
	return true;
}