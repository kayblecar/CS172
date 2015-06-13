//Name: Kay Ratcliff
//Project name: Baby Name Popularity Ranking
//Class CS 172

#include <iostream>
#include <fstream>
#include <vector>
#include "babyname.h"
using namespace std;

int main(){
	ifstream names2001("babynameranking2001.txt");
	vector<BabyName> male2001;
	vector<BabyName> female2001;
	while (!names2001.eof())
	{
		int rank;
		string mname, fname;
		int number;
		names2001 >> rank >> mname >> number >> fname >> number;
		BabyName male(mname, rank), female(fname, rank);
		male2001.push_back(male);
		female2001.push_back(female);
	}
	//why can't I increment variable and file names!?
}