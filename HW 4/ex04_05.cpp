//Name: Kay Ratcliff
//Program Name: the course class
//Class: 172

#include <iostream>
#include "Course.h"
using namespace std;

int main(){
	Course c;
	c.addStudent("Frank");
	c.addStudent("Sam");
	c.addStudent("Georgiana");

	c.dropStudent("Sam");
	for (int i = 0; i < c.getNumberOfStudents(); i++)
	{
		cout << *(c.getStudents() + i) << endl;
	}
	int i;
	cin >> i;
	return 0;
}
