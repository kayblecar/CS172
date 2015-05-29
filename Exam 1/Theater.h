//I affirm that all code given below was written solely by me, Kay Ratcliff, and that any help I received adhered to the rules stated for this exam.
//Kay Ratcliff
//CS 172

#include "Movie.h"
using namespace std;

class Theater
{
private:
	Movie currentlyPlaying[30];
	int movieCount = 0;
	string theater;
	string phone;
public:
	Theater(){
		theater = "Magic Lantern";
		phone = "(509) 867-5309";
	}
	Theater(string Name, string Phone){
		theater = Name;
		phone = Phone;
	}
	void AddMovie(Movie& movie){
		currentlyPlaying[movieCount] = movie;
		movieCount++;
	}
	string GetMovieForHour(int Hour){
		if (Hour < 0 || Hour >24)
			return "";
		int i=0;
		while (i < movieCount)
		{
			if (currentlyPlaying[i].GetShowtime() >= Hour)
				return currentlyPlaying[i].GetTitle();
			i++;
		}
		return "";
			
	}

	int GetShowTimeForGenre(string Genre){
		int i = 0;
		while (i < movieCount){
			if (currentlyPlaying[i].GetGenre() == Genre)
				return currentlyPlaying[i].GetShowtime();
		}
		return -1;
	}

	int GetPopcornPrice(){
		return 5;
	}

	int GetCokePrice(){
		return 2;
	}
};
