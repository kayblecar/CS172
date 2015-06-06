//Name: Kay Ratcliff
//Program Name: rectangle class
//Class: CS 172

#include <iostream>
using namespace std;

class Rectangle2D{
private:
	double x;
	double y;
	double width;
	double height;
public:
	Rectangle2D(){
		x = 0;
		y = 0;
		width = 1;
		height = 1;
	}
	Rectangle2D(double x, double y, double width, double height){
		(*this).x = x;
		(*this).y = y;
		(*this).width = width;
		(*this).height = height;
	}
	double gety() const{
		return y;
	}
	void sety(double newy){
		y = newy;
	}
	double getx() const{
		return x;
	}
	void setx(double newx) {
		x = newx;
	}
	double getWidth() const{
		return width;
	}
	void setWidth(double newWidth){
		width = newWidth;
	}
	double getHeight() const{
		return height;
	}
	void setHeight(double newHeight) {
		height = newHeight;
	}
	double getArea() const{
		return height*width;
	}
	double getPerimeter() const{
		return 2 * width + 2 * height;
	}
	bool contains(double x, double y) const{
		return (x > (*this).x - height / 2
			&& x < (*this).x + height / 2
			&& y < (*this).y + height / 2
			&& y > (*this).y - height / 2);
	}
	bool contains(Rectangle2D &r) const{
		return (x - width / 2 <= r.x - r.width / 2 //left edge to right of left edge 1
			&& x + width / 2 >= r.x + r.width / 2 //right edge to left of right edge 1
			&& y + height / 2 >= r.y + r.height / 2 //top edge below top edge
			&& y - height / 2 <= r.y - r.height / 2); //bottom edge below bottom edge
	}
	bool overlaps(Rectangle2D &r) const{
		return (x - width / 2 < r.x - r.width / 2
			|| x + width / 2 > r.x + r.width / 2
			|| y + height / 2 > r.y + r.height / 2
			|| y - height / 2 > r.y - r.height / 2);
	}
};

int main(){
	Rectangle2D r1(2, 2, 5.5, 4.9), r2(4, 5, 10.5, 3.2), r3(3, 5, 2.3, 5.4);
	cout << boolalpha << "r1 contains (3,3): " << r1.contains(3, 3) << endl;
	cout << boolalpha << "r1 contains r2: " << r1.contains(r2) << endl;
	cout << boolalpha << "r1 overlaps r3: " << r1.overlaps(r3) << endl;
}