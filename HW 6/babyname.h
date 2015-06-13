#include <string>

class BabyName{
private:
	string name;
	int rank;
public:
	BabyName(){
		name = "";
		rank = 0;
	}
	BabyName(string enterName, int enterRank){
		name = enterName;
		rank = enterRank;
	}
	string getName(){
		return name;
	}
	int getRank(){
		return rank;
	}
};