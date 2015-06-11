//Name: Kay Ratcliff
//Program name: Shuffle
//Class: CS 172

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;

template<typename T>
void shuffle(vector<T> &v);
template <typename T>
bool include(T list[], int size, T key);

int main(){
	srand(time(NULL));
	vector<int> vint;
	for (int i = 0; i < 10; i++){
		vint.push_back(i);
	}
	shuffle(vint);
	for (int i = 0; i < 10; i++){
		cout << vint.at(i) << endl;
	}
}

template<typename T>
void shuffle(vector<T> &v){
	vector<T> temp;
	 T locations[v.size()];
	for (int i = 0; i < v.size(); i++){
		do{
			locations[i] = rand() % v.size();
		} while (i != 0 || include(locations, i, locations[i]));
		temp.push_back(v.at(locations[i]));
	}
	v.swap(temp);
}


template <typename T>
bool include(T list[], int limit, T key){
	for (int i = 0; i < limit; i++){
		if (key == list[i])
			return true;
	}
	return false;
}