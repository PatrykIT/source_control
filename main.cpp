// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>

enum class Dog_Gender { male, female };

struct Dog_Temperament
{
	bool fearless, alert, confident, calm, intelligent, trusting, kind, loyal;
};

struct Dog_Temperament_Basic
{
	bool calm, intelligent, trusting, loyal, aggressive;
};

class Dog
{
protected:
	std::string name;
	int age;
	double height;
	double weight;
	Dog_Temperament temperament;
	Dog_Gender gender;

	virtual void setAge(int age) { this->age = age; }
	virtual void setHeight(double height) { this->height = height; }
	virtual void setWeight(double weight) { this->weight = weight; }
	virtual void setGender(Dog_Gender &gender) { this->gender = gender; }
	virtual void setTemperament(Dog_Temperament &temperament) = 0;

public:
	virtual void setName(std::string &&name) { this->name = std::move(name); } // This method is public as name of a dog can be changed at any time.
	virtual void setName(const std::string &name) { this->name = name; } // Same as above
};

class Husky : protected Dog
{
	struct Husky_Temperament : public Dog_Temperament
	{
		bool charming, kind, gentle;
	};
	
	void setTemperament(Dog_Temperament &temperament) override
	{

	}
};

class Labrador_Retriever : protected Dog
{
	struct Labrador_Temperament : public Dog_Temperament
	{
		bool outgoing, agile, kind;
	};
};

class German_Shepherd : public Dog
{
	struct German_Temperament : public Dog_Temperament
	{
		bool watchful, courageous, obedient;
	};
};

class Mastiff : protected Dog
{
	struct Husky_Temperament : public Dog_Temperament
	{
		bool affectionate, protective, courageous;
	};
};

class Pitbull : protected Dog
{
	struct Husky_Temperament : public Dog_Temperament
	{
		bool confident, charming, kind;
	};
};

class Chihuahua : protected Dog
{

};

class Human
{
protected:
	int age;
	double height;
};

class Female : protected Human
{

};

class Male : protected Human
{

};


class Jury
{
	Human* jury_commitee[4];
};

class Headling_Competition
{
	Jury jury;
	Dog* dogs[10];
};



int main()
{
	//Dog *dog = new German_Shepherd;
	//dog->setAge(10);

    return 0;
}

