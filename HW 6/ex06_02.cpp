//Name: Kay Ratcliff
//Program name: Count characters
//Class: CS 172

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	string filename;
	cout << "enter a file name: ";
	cin >> filename;

	ifstream file(filename.c_str());
	char c;
	int charcount = 0;

	while (!file.eof())
	{
		file >> c;
		charcount++;
	}
	cout << charcount << endl;
}