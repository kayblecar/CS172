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
	//int maxhp;
	int fighthp;
	vector<Weapon> armory;
public:
	Fighter(){
		name = "Player";
		//maxhp = 
		fighthp = rand() % 5 + 1;
	}
	Fighter(int min, int variation, string name){
		(*this).name = name;
		//maxhp = 
		fighthp = min + rand() % variation;
	}

	void attack(Fighter opponent){
		unsigned int choice;
		cin >> choice;
		cin.ignore();
		opponent.takehit(armory[choice - 1]);
	}

	void takehit(Weapon w){
		int temp = fighthp - w.getStrength();
		fighthp = temp;//isn't changing member variable?
		cout << fighthp << endl; //gives correct value after "attacked"
	}
	bool isdefeated(){
		return (fighthp <= 0);
	}
	void gainWeapon(Weapon w){//adding weapons
		armory.push_back(w);
	}
	void powerup(int weapon, int up){ //powering up weapon after fight
		armory[weapon].powerup(up);
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
};
#endif 