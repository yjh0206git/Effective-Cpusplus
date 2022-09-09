#pragma once
#include<iostream>
#include<functional>
using namespace std;
//NVI:Template Method

/*
class GameCharacter {
public:
	int healthValue() const {
		int retVal = doHealthValue();
		return retVal;
	}
private:
	virtual int doHealthValue() const {

	}
};
*/

//Function Pointers:Strategy
//Function Objection
/*
class GameCharacter;
int defaultHealthCalc(const GameCharacter& gc);
class GameCharacter {
public:
	//typedef int (*HealthCalcFunc)(const GameCharacter&);
	typedef std::tr1::function<int (const GameCharacter&)> HealthCalcFunc;
	explicit GameCharacter(HealthCalcFunc hcf=defaultHealthCalc)
		:healthFunc(hcf){}
	int healthValue() const { 
		return healthFunc(*this);
	}
private:
	HealthCalcFunc healthFunc;
};

class EvilBadGuy :public GameCharacter {
public:
	explicit EvilBadGuy(HealthCalcFunc hcf=defaultHealthCalc)
		:GameCharacter(hcf){}
};

int loseHealthQuickly(const GameCharacter&);
int loseHealthSlowly(const GameCharacter&);

short calHealth(const GameCharacter&);

struct HealthCalculator {
	int operator()(const GameCharacter&) const;
};

class GameLevel {
public:
	float health(const GameCharacter&) const;
};

GameLevel currentLevel;

EvilBadGuy ebg1(loseHealthQuickly);
EvilBadGuy ebg2(loseHealthSlowly);
EvilBadGuy ebg3(calHealth);
EvilBadGuy ebg4(HealthCalculator());
*/

//¹ÅµäµÄStrategy
class GameCharacter;
class HealthCalcFunc {
public:
	virtual int calc(const GameCharacter& gc) const
	{}
};

HealthCalcFunc defaultHealthCalc;

class GameCharacter {
public:
	explicit GameCharacter(HealthCalcFunc* phcf = &defaultHealthCalc)
		:pHealthCalc(phcf) 
	{}
	int healthValue() const {
		return pHealthCalc->calc(*this);
	}
private:
	HealthCalcFunc* pHealthCalc;
};



