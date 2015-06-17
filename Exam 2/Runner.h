//I affirm that all code given below was written solely by me, Kay Ratcliff, and that any help I received adhered to the rules stated for this exam.

//Name: Kay Ratcliff
//Class: CS 172

#include <string>
using namespace std;

class Runner{
private:
	string first_name;
	string last_name;
	int pace;
public:
	Runner(){
		first_name = "Kay";
		last_name = "Ratcliff";
		pace = 0;
	}
	Runner(string fname, string lname, int speed){
		first_name = fname;
		last_name = lname;
		pace = speed;
	}
	string get_firstname(){
		return first_name;
	}
	string get_lastname(){
		return last_name;
	}
	int get_pace(){
		return pace;
	}
};