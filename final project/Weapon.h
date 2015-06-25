#ifndef WEAPON_H
#define WEAPON_H
#include <string>
using namespace std;
string getWord(string type);


class Weapon
{
private:
	string name;
	int strength;
	string nameTemplate(string filename){
		ifstream weapontemplate(filename.c_str());
		string temp;
		string name;
		int lines = 0;
		while (!weapontemplate.eof())
		{
			getline(weapontemplate, temp);
			lines++;
		}//count number of lines in template
		weapontemplate.close();

		weapontemplate.open(filename.c_str());
		for (int i = 0; i < rand() % lines; i++)
		{
			getline(weapontemplate, temp);
		}//read to random line in fighttemplate
		do
		{
			weapontemplate >> temp;
			if (temp[0] == '<'){//asking for a madlibs word
				string type = temp;
				while (type[type.size() - 1] != '>')
				{
					weapontemplate >> temp;
					type = type + " " + temp;
				}
				type.pop_back();
				type.erase(type.begin());
				name = name + " " + getWord(type); //add madlibbed word to end of name
			}
			else{
				name = name + " " + temp;
			}
		} while (name[name.size() - 1] != '.');
		name.pop_back(); //remove '.'
		if (name[name.size() - 1] == ' ')
			name.pop_back(); //get rid of extra space if necessary
		return name;
	}
public:
	Weapon(){
		strength = rand() % 5 + 1; //initial strength of weapon is minimum of 1
		name = nameTemplate("test.txt");
	}
	Weapon(string genre){
		strength = rand() % 5 + 1;
		string templatefile = genre + "weapontemplate.txt";
		name = nameTemplate(templatefile);
	}
	
	void powerup(int up){
		strength += up;
	}

	string getName(){
		return name;
	}
	int getStrength(){
		return strength;
	}
	
};


#endif
