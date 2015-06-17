//I affirm that all code given below was written solely by me, Kay Ratcliff, and that any help I received adhered to the rules stated for this exam.

//name: Kay Ratcliff
//Program name: Exam 2
//Class: CS 172

#include <iostream>
#include <fstream>
#include <vector>
#include "Runner.h"
using namespace std;

void vectorSort(vector<Runner> &v);

int main(){
	ifstream registrants("registrants.txt");
	vector<Runner> runners; //create array
	while (!registrants.eof())
	{
		int pace;
		string first_name, last_name;
		registrants >> first_name >> last_name >> pace;
		Runner x(first_name, last_name, pace);
		runners.push_back(x);
	}

	vectorSort(runners);

	ofstream white("white.txt");
	ofstream yellow("yellow.txt");
	ofstream green("green.txt");
	ofstream orange("orange.txt");
	ofstream blue("blue.txt");
	ofstream lilac("lilac.txt");
	ofstream red("red.txt");

	for (unsigned int i = 0; i < runners.size(); i++)
	{
		if (runners[i].get_pace() <= 630)
			white << runners[i].get_firstname() << " " << runners[i].get_lastname() << " " << runners[i].get_pace() << endl;
		else if (runners[i].get_pace() <= 420)
			yellow << runners[i].get_firstname() << " " << runners[i].get_lastname() << " " << runners[i].get_pace() << endl;
		else if (runners[i].get_pace() <=480)
			green << runners[i].get_firstname() << " " << runners[i].get_lastname() << " " << runners[i].get_pace() << endl;
		else if(runners[i].get_pace() <= 540)
			orange << runners[i].get_firstname() << " " << runners[i].get_lastname() << " " << runners[i].get_pace() << endl;
		else if (runners[i].get_pace() <= 600)
			blue << runners[i].get_firstname() << " " << runners[i].get_lastname() << " " << runners[i].get_pace() << endl;
		else if (runners[i].get_pace() <=720)
			lilac << runners[i].get_firstname() << " " << runners[i].get_lastname() << " " << runners[i].get_pace() << endl;
		else if (runners[i].get_pace() <= 1200)
			red << runners[i].get_firstname() << " " << runners[i].get_lastname() << " " << runners[i].get_pace() << endl;
	}
	cout << "done" << endl;
	fcloseall();

	//while loop that checks each file, cout "error" if pace incorrect
}

void vectorSort(vector<Runner> &v){
	vector<Runner> temp;
	unsigned int i, j, fast; //let i be index v, j intex temp, fast is temporary index of fastest
	unsigned int length = v.size();
	vector<int> used;
	
	for ( j = 0; j < length; j++)
	{ 
		fast = 0;
		for ( i = 0; i < length - j; i++)
		{
			if (v[fast].get_pace() > v[i].get_pace())
				fast = i;
		}
		//cout << j << ": " << i << " fast: " << fast << " v[fast]: " << v[fast].get_pace() << endl;
		temp.push_back(v[fast]);
		v.erase(v.begin() + fast); //erase fastest element so that you can go back into inner for loop without getting a vector full of usain bolt.
	}

	v.swap(temp);
}