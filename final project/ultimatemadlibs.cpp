#include<iostream>
#include<fstream>
#include <string>
#include<vector>
#include <ctime>
#include "StoryElement.h"
#include "Fighter.h"
#include "Weapon.h"
using namespace std;
string getWord(string type);
int menu(vector<string> genres);


int main(){
	srand(time(NULL));
	vector<string> consequences; //consequences add to player character's reputation, will be mentioned by opponents
	vector<string> locations;
	//vector<string> opponents; or in player's fighter object?
	vector<string> genres = { "Fantasy", "Science Fiction" };
	Fighter player;
	
	int genreint = menu(genres);//save int to allow case function
	string genre = genres[genreint];
	if (genre == "Science Fiction")
		genre = "scifi";

	int introIndex, part1Index, finaleIndex; //used to randomize which file is used for each story part
	switch (genreint) //have different numbers of files for different genres
	{
	case 0:
		introIndex = rand() % 1;
		part1Index = rand() % 1;
		finaleIndex = rand() % 1;
		break;
	case 1:
		introIndex = rand() % 1;
		part1Index = rand() % 1;
		finaleIndex = rand() % 1;
		break;

	default:
		break;
	}

	StoryElement intro(genre, "intro", introIndex, player);//get words for introduction
	intro.readFile();
	string antagonist = intro.getAntName();
	string antagonisttype = intro.getAntType();
	string friendname = intro.getFriend();


	StoryElement part1(genre, "chapter", part1Index, antagonist, antagonisttype, friendname, player); //get words for part 1
	part1.readFile();

	intro.tellStory(consequences, locations);//telling story
	locations.push_back(intro.decide());
	consequences.push_back(intro.getconsequence(locations[0]));

	part1.tellStory(consequences, locations);
	locations.push_back(part1.decide());
	consequences.push_back(part1.getconsequence(locations[1]));


	//finish fight
	//write finales
	
}

int menu(vector<string> genres){
	cout << "What type of adventure would you like to have?" << endl;
	for (unsigned int i = 0; i < genres.size(); i++)
	{
		cout << i + 1 << ": " << genres[i] << endl;
	}
	unsigned int choice;
	cin >> choice;
	choice--;
	while (choice >= genres.size())
	{
		cout << "I don't know any stories of that genre! Try one I do know." << endl;
		cin >> choice;
		choice--;
	}
	cin.ignore();
	return choice;
}

string getWord(string type){
	cout << "Give me a";
	if (type[0] == 'a' || type[0] == 'e' || type[0] == 'i' || type[0] == 'o' || type[0] == 'u')
		cout << "n";
	cout << " " << type << ": ";
	string word;
	getline(cin, word);
	return word;
}