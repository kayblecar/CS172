#ifndef FIGHTER_H
#define FIGHTER_H

#include "Weapon.h"
#include <string>
#include <vector>
using namespace std;

class Fighter
{
private:
	string name;
	int fighthp;
	vector<Weapon> armory;
	vector<Fighter> defeated;
public:
	Fighter(){
		name = "Player";
		fighthp = rand() % 5 + 1;
	}
	Fighter(int min, int variation, string name){
		(*this).name = name;
		fighthp = min + rand() % variation;
	}

	void attack(Fighter &opponent){
		unsigned int choice;
		cin >> choice;
		while (choice > armory.size())
		{
			cout << "You don't have that many! Try again: ";
			cin >> choice;
		}
		cin.ignore();
		opponent.takehit(armory[choice - 1]);
	}

	void takehit(Weapon w){
		int temp = fighthp - w.getStrength();
		fighthp = temp;
	}
	bool isdefeated(){
		return (fighthp <= 0);
	}

	void gainWeapon(Weapon w){//adding weapons
		armory.push_back(w);
	}
	void powerup(int weapon, int up){ //powering up weapon after fight
		armory[weapon].powerup(up);
		cout << armory[weapon].getName() << " now has strength " << armory[weapon].getStrength() << endl;
	}
	void addDefeated(Fighter opponent){
		defeated.push_back(opponent);
	}
	string randomDefeated(){
		int i = rand() % defeated.size();
		return defeated[i].getName();
	}
	void coutWeapons(){
		for (unsigned int i = 0; i < armory.size(); i++)
		{
			cout << i + 1 << ": " << armory[i].getName() << ": " << armory[i].getStrength() << endl;
		}
	}
	string getName(){
		return name;
	}
	int gethp(){
		return fighthp;
	}
	int getArmorySize(){
		return armory.size();
	}
};
#endif 