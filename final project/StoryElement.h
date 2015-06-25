#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Fighter.h"
#include "Weapon.h"
using namespace std;
string getWord(string type);

class StoryElement
{
private:
	fstream story;
	string genre;
	string filename;
	string fightname;
	string decisionname;
	vector<string> words;
	string antagonistname;
	string antagonisttype;
	string friendname;
	Fighter opponent;
	Fighter *ptrplayer;

	//words that are consistent through story: antagonist, antagonist type, friend(s? vector?) and accessors. overload constructor for including them in story read
	//opponent variable add to vector in main? or in player fighter?

public:
	StoryElement(){
		genre = "test";
		filename = "test.txt";
		fightname = "skirmish.txt";
		decisionname = "testchoice.txt";
	}
	StoryElement(string genre, string storypart, int i, Fighter & player){
		char c = '0' + i;
		//if i can be more than 9, will need to put if statement in here
		filename = genre + storypart + c + ".txt";
		fightname = genre + "fight.txt";
		decisionname = genre + storypart + "decision.txt";
		ptrplayer = &player;
		(*this).genre = genre;
	}
	StoryElement(string genre, string storypart, int i, string antname, string anttype, string friendname, Fighter& player){
		char c = '0' + i;
		//again if i can be more than 9, will need to put if statement in here
		filename = genre + storypart + c + ".txt";
		fightname = genre + "fight.txt";
		decisionname = genre + storypart + "decision.txt";
		(*this).genre = genre;

		antagonistname = antname;
		antagonisttype = anttype;
		(*this).friendname = friendname;
		ptrplayer = &player;
	}

	void readFile(){
		story.open(filename.c_str());
		while (!story.eof()){
			string word;
			story >> word;
			if (word[0] == '<'){
				if (word == "<location" || word == "<consequence" || word == "<antagonist>" || word == "<anttype>" || word == "<friend>" || word == "<punc" || word == "<opponent>" ){ //commands that can be skipped in read
					while (word[word.size() - 1] != '>'){
						story >> word;
					}
				}
				else if (word == "<weapons>"){
					for (int i = 0; i < 3; i++)
					{
						Weapon newWeapon(genre);
						(*ptrplayer).gainWeapon(newWeapon);
					}
				}
					//(function) nameweapons, keep vector/array of weapons
				else if (word == "<fight"){
					int min, var;
					story >> min >> var;

					string prompt;
					while (word[word.size()-1] != '>')
					{
						story >> word;
						prompt = prompt + " " + word;
					}
					prompt.pop_back();
					opponent = Fighter(min, var, getWord(prompt));
				}
				else if (word == "<get"){ //naming reused variables
					story >> word;
					string named = word;
					string prompt;
					do
					{
						story >> word;
						prompt = prompt + " " + word;
					} while (prompt[prompt.size() - 1] != '>');
					prompt.pop_back();//get rid of ">"

					if (named == "antagonist"){
						antagonistname = getWord(prompt);
					}
					else if (named == "anttype"){
						antagonisttype = getWord(prompt);
					}
					else if (named == "friend"){
						friendname = getWord(prompt);
					}
				}
				else{//word type-> prompt user for madlibs blank
					word.erase(word.begin());
					string command = word;
					while (word[word.size() - 1] != '>'){
						story >> word;
						command = command + " " + word;
					}
					command.pop_back();
					words.push_back(getWord(command));
				}				
		}
		}
		story.close();
	}
	void tellStory(vector<string> consequence, vector<string> location){//need to incorporate last decision in story tell
		string word;
		int i = 0;
		story.open(filename.c_str());
		while (!story.eof()){ 
			story >> word;
			if (word[0] == '<'){

				if (word == "<get"  || word == "<weapons>"){ //commands that can be skipped in telling
					while (word[word.size() - 1] != '>')
					{
						story >> word;
					}
				}
				else if (word == "<fight"){
					while (word[word.size() - 1] != '>')
					{
						story >> word;
					}
					fight(location[location.size()-1]);
				}
				else if (word == "<antagonist>"){//reused words
					cout << antagonistname << " ";
				}
				else if (word == "<anttype>"){
					cout << antagonisttype << " ";
				}
				else if (word == "<friend>"){
					cout << friendname << " ";
				}
				else if (word == "<opponent>"){
					cout << opponent.getName() << " ";
				}
				else if (word == "<consequence"){//consequence of previous decision
					string ref;
					int i;
					story >> ref;
					if (ref == "-1>")
						i = consequence.size() - 1;
					else
						i = rand() % consequence.size();
					cout << consequence[i] << " " ;
				}
				else if (word == "<location"){//location of previous decisions
					string ref;
					int i;
					story >> ref;
					if (ref == "-1>")
						i = location.size()-1;
					else
						i = rand() % location.size();
					cout << location[i] << " ";
				}
				else if (word == "<punc"){
					story >> word;
					cout << "\b" << word[0] << " ";
				}
				else{
					while (word[word.size() - 1] != '>'){
						story >> word;
					}
					cout << words[i] << " ";
					i++;
				}
				
			}
			else
				cout << word << " ";
		}
		story.close();
	}
	void fight(string location){
		ifstream fight(fightname.c_str());
		string prompt;
		cout << opponent.getName() << "'s hp is " << opponent.gethp();
		getline(fight, prompt);// prompt for which weapon to use
		cout << prompt << endl;
		getline(fight, prompt); //line in between fights eg "they're not quite down!"
		(*ptrplayer).coutWeapons();
		(*ptrplayer).attack(opponent);
		cout << opponent.gethp() << endl;
		while (!opponent.isdefeated()){
			cout << prompt << endl;
			cout << opponent.getName() << "'s hp is " << opponent.gethp() << endl;
			(*ptrplayer).coutWeapons();
			(*ptrplayer).attack(opponent);
		}
		getline(fight, prompt); //location specific victory message eg "the locals thank you for your help"

		getline(fight, prompt);//asks which weapon to power up
		cout << prompt << endl;
		int user;
		cin >> user;
		cin.ignore();
		(*ptrplayer).powerup(user, 2);

		fight.close();
	}
	string decide(){ //prompt user for decision
		ifstream decision(decisionname.c_str());
		string prompt;
		getline(decision, prompt);
		cout << prompt << endl;

		vector<string> consequences;
		vector<string> locations;
		while (!decision.eof())
		{
			string line;
			string consequence;
			string location;
			getline(decision, line);
			cout << line << endl;
			getline(decision, consequence);
			getline(decision, location);
			locations.push_back(location);
		}
		decision.close();
		unsigned int user;
		cin >> user;
		user--;
		while (user >= locations.size())
		{
			cout << "You can't do that! Try something else!" << endl;
			cin >> user;
			user--;
		}
		cin.ignore();
		return locations[user];
	}
	string getconsequence(string location){//returns relevant consequence for location decision
		fstream decision(decisionname.c_str());
		string discard;
		string consequence;
		getline(decision, discard);
		do
		{
			getline(decision, discard);
			getline(decision, consequence);
			getline(decision, discard);
		} while (!decision.eof() && discard != location);
		decision.close();
		return consequence;
	}
	string getAntName(){
		return antagonistname;
	}
	string getAntType(){
		return antagonisttype;
	}
	string getFriend(){
		return friendname;
	}


};
