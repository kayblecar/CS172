//Kay Ratcliff
//CS 172

#include <iostream>
using namespace std;

class Fan 
{
public:
	int speed;
	bool on;
	double radius;

	Fan(){
		speed = 1;
		on = false;
		radius = 5;
	}

	void setSpeed(int newSpeed){
		if (newSpeed <= 3 && newSpeed > 0)
			speed = newSpeed;
	}
	void turnOn(){
		on = true;
	}
	void turnOff(){
		on = false;
	}
	void setRadius(double newRadius){
		radius = newRadius;
	}

	bool isOn(){
		return on;
	}

	int getSpeed(){
		return speed;
	}

	double getRadius(){
		return radius;
	}
};

int main(){
	

	Fan fan1;
	Fan fan2;

	fan1.turnOn();
	fan1.setSpeed(3);
	fan1.setRadius(10);

	fan2.turnOn();
	fan2.setSpeed(2);

	cout << boolalpha << "Fan 1: \n\tSpeed: " << fan1.getSpeed() << "\n\tOn: " << fan1.isOn() << "\n\tRadius: " << fan1.getRadius() << endl;
	cout << boolalpha << "Fan 2: \n\tSpeed: " << fan2.getSpeed() << "\n\tOn: " << fan2.isOn() << "\n\tRadius: " << fan2.getRadius() << endl;
}