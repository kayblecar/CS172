//Kay Ratcliff
//CS 172

#include <iostream>
using namespace std;

class QuadraticEquation {
public:
	double a, b, c;

	QuadraticEquation(){
		cout << "Enter values a, b and c in the form ax^2 + bx + c: ";
		cin >> a >> b >> c;
	}

	double geta(){
		return a;
	}
	double getb(){
		return b;
	}
	double getc(){
		return c;
	}

	double getDiscriminant(){
		return b*b - 4 * a*c;
	}

	double getRoot1(){
		if (getDiscriminant() < 0)
			return 0;
		else
			return (-b + sqrt(getDiscriminant())) / (2 * a);
	}
	double getRoot2(){
		if (getDiscriminant() < 0)
			return 0;
		else
			return (-b - sqrt(getDiscriminant())) / (2 * a);
	}
};

int main(){
	QuadraticEquation q;

	if (!q.getDiscriminant())
		cout << "The root is " << q.getRoot1() << endl;
	else if (q.getDiscriminant() > 0)
		cout << "The roots are " << q.getRoot1() << " and " << q.getRoot2() << "." << endl;
	else
		cout << "There are no real roots." << endl;
}