//Name: Kay Ratcliff
//Program name: Analyze input
//Class: CS 172

#include <iostream>
using namespace std;

double average(int values[], int size);
int aboveAverage(int values[], int size, double avg);

int main(){
	int size;
	cin >> size;
	int *list = new int[size];

	for (int i = 0; i < size; i++)
	{
		
		cin >> *(list + i);
	}

	double avg = average(list, size);
	cout << "Average: " << avg << endl;
	cout << "Number above average: " << aboveAverage(list, size, avg) << endl;


}

double average(int values[], int size){
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += values[i];
	}
	return sum / static_cast<double>(size);
}

int aboveAverage(int values[], int size, double avg){
	int total = 0;
	for (int i = 0; i < size; i++)
	{
		if (values[i] > avg)
			total++;
	}
	return total;
}