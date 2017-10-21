// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include <array>

enum class Gender { male, female };

struct Dog_Temperament
{
	bool calm, intelligent, trusting, loyal, aggressive;
	void printAttribtutes()
	{
		std::cout << std::boolalpha << "Calm: " << calm << "\nInteligent: " << intelligent << "\nTrusting: " << trusting << "\nLoyal: " << loyal << "\nAggressive: " << aggressive << std::endl;
	}
};


class Dog
{
protected:
	std::string name;
	std::string gender_name;
	int age;
	double height;
	double weight;
	Dog_Temperament temperament;
	Gender gender;

	virtual void setAge(int age) { this->age = age; }
	virtual void setHeight(double height) { this->height = height; }
	virtual void setWeight(double weight) { this->weight = weight; }
	virtual void setGender(const Gender &gender)
	{
		this->gender = gender;
		
		if (gender == Gender::male)
			gender_name = "male";
		else
			gender_name = "female"; 
	}
	virtual void setTemperament(Dog_Temperament &dog_temperament) = 0;

public:
	virtual void setName(std::string &&name) { this->name = std::move(name); } // This method is public as name of a dog can be changed at any time.
	virtual void setName(const std::string &name) { this->name = name; } // Same as above

	virtual void printInformation() = 0;

};

class Husky : public Dog
{
	struct Husky_Temperament : public Dog_Temperament
	{
		bool charming, kind, gentle;
		
		void printSpecific_Attribtutes()
		{
			std::cout << std::boolalpha << "Charming: " << charming << "\nKind: " << kind << "\nGentle: " << gentle << std::endl;
		}
	};

	Husky_Temperament temperament;
	
public:
	
	Husky() = delete;
	Husky(int age, double height, double weight, const Gender &gender, Dog_Temperament &dog_temperament, const std::string &name)
	{
		setAge(age);
		setHeight(height);
		setWeight(weight);
		setGender(gender);
		setTemperament(dog_temperament);
		setName(name);
	}

	void setTemperament(Dog_Temperament &dog_temperament) override
	{
		temperament.calm = dog_temperament.calm;
		temperament.intelligent = dog_temperament.intelligent;
		temperament.trusting = dog_temperament.trusting;
		temperament.loyal = dog_temperament.loyal;
		temperament.aggressive = dog_temperament.aggressive;
		
		temperament.charming = true;
		temperament.kind = true;
		temperament.gentle = true;
	}

	void printInformation() override
	{
		std::cout << "This is a Husky dog. Its name is: " << name << ". It is: " << age << " years old.\nHeight: " << height << " cm." << "\nWeight: " << weight << " kg.";
		std::cout << "\nIts gender is: " << gender_name <<"\n";
		temperament.printAttribtutes();
		temperament.printSpecific_Attribtutes();
	}

};

class Labrador_Retriever : public Dog
{
	struct Labrador_Temperament : public Dog_Temperament
	{
		bool outgoing, agile, kind;

		void printSpecific_Attribtutes()
		{
			std::cout << std::boolalpha << "Outgoing: " << outgoing << "\nAgile: " << agile << "\nKind: " << kind << std::endl;
		}
	};

	Labrador_Temperament temperament;

public:
	Labrador_Retriever() = delete;
	Labrador_Retriever(int age, double height, double weight, const Gender &gender, Dog_Temperament &dog_temperament, const std::string &name)
	{
		setAge(age);
		setHeight(height);
		setWeight(weight);
		setGender(gender);
		setTemperament(dog_temperament);
		setName(name);
	}


	void setTemperament(Dog_Temperament &dog_temperament) override
	{
		temperament.calm = dog_temperament.calm;
		temperament.intelligent = dog_temperament.intelligent;
		temperament.trusting = dog_temperament.trusting;
		temperament.loyal = dog_temperament.loyal;
		temperament.aggressive = dog_temperament.aggressive;

		temperament.outgoing = true;
		temperament.agile = true;
		temperament.kind = true;
	}

	void printInformation() override
	{
		std::cout << "This is a Labrador Retriever dog. Its name is: " << name << ". It is: " << age << " years old.\nHeight: " << height << " cm." << "\nWeight: " << weight << " kg.";
		std::cout << "\nIts gender is: " << gender_name << "\n";
		temperament.printAttribtutes();
		temperament.printSpecific_Attribtutes();
	}
};

class German_Shepherd : public Dog
{
	struct German_Temperament : public Dog_Temperament
	{
		bool watchful, courageous, obedient;
	};

	German_Temperament temperament;

	void setTemperament(Dog_Temperament &dog_temperament) override
	{
		temperament.calm = dog_temperament.calm;
		temperament.intelligent = dog_temperament.intelligent;
		temperament.trusting = dog_temperament.trusting;
		temperament.loyal = dog_temperament.loyal;
		temperament.aggressive = dog_temperament.aggressive;

		temperament.watchful = true;
		temperament.courageous = true;
		temperament.obedient = true;
	}
};

class Mastiff : protected Dog
{
	struct Mastiff_Temperament : public Dog_Temperament
	{
		bool affectionate, protective, courageous;
	};

	Mastiff_Temperament temperament;

	void setTemperament(Dog_Temperament &dog_temperament) override
	{
		temperament.calm = dog_temperament.calm;
		temperament.intelligent = dog_temperament.intelligent;
		temperament.trusting = dog_temperament.trusting;
		temperament.loyal = dog_temperament.loyal;
		temperament.aggressive = dog_temperament.aggressive;

		temperament.affectionate = true;
		temperament.protective = true;
		temperament.courageous = true;
	}
};

class Pitbull : protected Dog
{
	struct Pitbull_Temperament : public Dog_Temperament
	{
		bool fearless, alert;
	};

	Pitbull_Temperament temperament;

	void setTemperament(Dog_Temperament &dog_temperament) override
	{
		temperament.calm = dog_temperament.calm;
		temperament.intelligent = dog_temperament.intelligent;
		temperament.trusting = dog_temperament.trusting;
		temperament.loyal = dog_temperament.loyal;
		temperament.aggressive = dog_temperament.aggressive;

		temperament.fearless = true;
		temperament.alert = true;
	}
};

class Chihuahua : protected Dog
{
	struct Chihuahua_Temperament : public Dog_Temperament
	{
		bool lively, quick;
	};

	Chihuahua_Temperament temperament;

	void setTemperament(Dog_Temperament &dog_temperament) override
	{
		temperament.calm = dog_temperament.calm;
		temperament.intelligent = dog_temperament.intelligent;
		temperament.trusting = dog_temperament.trusting;
		temperament.loyal = dog_temperament.loyal;
		temperament.aggressive = dog_temperament.aggressive;

		temperament.lively = true;
		temperament.quick = true;
	}
};

class Human
{
protected:
	std::string name;
	int age;
	double height;
};


class Jury_Worker : public Human
{
private:
	int years_of_experience;

public:
	Jury_Worker(int years_of_experience) { this->years_of_experience = years_of_experience; }
	enum class skill { GREAT, GOOD, NORMAL, BAD };
};

class Headling_Competition
{
	std::vector<const Dog*> dogs;
	std::array<const Jury_Worker*, 4> jury_commitee; //Commitee is 4 people: 2 males and 2 females.
	int committee_count;

public:
	void addDog_to_Contest(const Dog &dog)
	{
		dogs.push_back(&dog);
	}

	void addJury_to_Contest(const Jury_Worker &person)
	{
		if (committee_count > 3)
		{
			std::cout << "Committee full. Can't add a new person.\n";
		}
		
		jury_commitee.at(committee_count) = &person;
		++committee_count;
	}
};


#define YES true
#define NO false
//	bool calm, intelligent, trusting, loyal, aggressive;

int main()
{
	Dog_Temperament temperament{ YES, YES, YES, YES, NO };
	Husky husky(5, 50.5, 7.5, Gender::male, temperament, "Allo");
	husky.printInformation();

	Labrador_Retriever labrador(7, 60.3, 12, Gender::female, temperament, "Labi");
	labrador.printInformation();

    return 0;
}

