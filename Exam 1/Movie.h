//I affirm that all code given below was written solely by me, Kay Ratcliff, and that any help I received adhered to the rules stated for this exam.
//Kay Ratcliff
//CS 172

#ifndef Movie_H
#define Movie_H
#include <string>
using namespace std;

class Movie
{
public:
	string title;
	string genre;
	// for Genre, only Action, Comedy, Horror, and Documentary. how??
	int showtime;
	
	Movie(){
		title = "The Hitchhiker's Guide To The Galaxy";
		genre = "Comedy";
		showtime = 12;
	}

	Movie(string Title, string Genre, int Showtime){
		title = Title;
		genre = Genre;
		showtime = Showtime;
	}

	string GetTitle(){
		return title;
	}

	string GetGenre(){
		return genre;
	}

	int GetShowtime(){
		return showtime;
	}
};

#endif