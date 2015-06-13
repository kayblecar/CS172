//name: Kay Ratcliff
//Program name: Create a text file
//Class: CS 172

#include <iostream>
#include<string>
#include <fstream>
#include <ctime>
using namespace std;

int main(){
	srand(time(NULL));
	fstream file("Exercise13_1.txt", ios::app);
	for (int i = 0; i < 100; i++){
		file << rand() << " ";
	}
	
}