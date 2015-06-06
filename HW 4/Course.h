#ifndef COURSE_H
#define COURSE_H
#include <string>
using namespace std;

class Course{
private:
	string courseName;
	string* students;
	int numberOfStudents;
	int capacity; 
public:
	Course(const string& courseName, int capacity){
		(*this).courseName = courseName;
		(*this).capacity = capacity;
		numberOfStudents = 0; 
		students = new string[capacity];
	}
	~Course(){
		delete[] students;
		courseName = "";
		numberOfStudents = 0;
		capacity = 0;
	}
	Course(){
		courseName = "Intro to Computer Science";
		capacity = 30;
		numberOfStudents = 0;
		students = new string[capacity];
	}
	Course(const Course& c){
		courseName = c.courseName;
		numberOfStudents = c.numberOfStudents;
		capacity = c.capacity;
		students = new string[capacity];
		for (int i = 0; i < numberOfStudents; i++)
		{
			students[i] = c.students[i];
		}
	}
	string getCourseName() const{
		return courseName;
	}
	void addStudent(const string& name){
		if (numberOfStudents == capacity){
			capacity *= 2;
			string*list = new string[capacity];
			for (int i = 0; i < numberOfStudents; i++)
			{
				list[i] = students[i];
			}
			delete[] students;
			students = list;
		}
		students[numberOfStudents++] = name;
	}
	void dropStudent(const string& name){
		int j;
		for (int i = 0; i < numberOfStudents; i++)
		{
			if (students[i] == name){
				j = i;
				continue;
			}
		}
		for (int i = j; i < numberOfStudents - 1; i++)
		{
			students[i] = students[i + 1];
		}
		students[numberOfStudents - 1] = "";
		numberOfStudents--;
	}
	string* getStudents() const{
		return students;
	}
	int getNumberOfStudents() const{
		return numberOfStudents;
	}
	void clear(){
		for (int i = 0; i < numberOfStudents; i++)
		{
			students[i] = "";
		}
		numberOfStudents = 0;
	}

};

#endif