//Kay Ratcliff
//CS 172

#include <iostream>
using namespace std;

class EvenNumber{
public:
	int value;

	EvenNumber(){
		value = 0;
	}
	EvenNumber(int number){
		if (number % 2 == 0)
			value = number;
		else
			value = 0;
	}

	int getValue(){
		return value;
	}
	int getNext(){
		return value + 2;
	}
	int getPrevious(){
		return value - 2;
	}
};

int main(){
	EvenNumber e (16);
	cout << "The value is " << e.getValue() << ", the next value is " << e.getNext() << ", and the previous value is " << e.getPrevious() << endl;
}