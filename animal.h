#pragma once
#include <iostream>
#include "IOInterface.h"
#include <string>
#include "exception.h"
using namespace std;

// Abstract class Animal
class Animal: public IOInterface {
protected:
	int age;
	float weight;
	string name;
	const int id;
	static int idCounter;
public:
	// Default Constructor
	Animal();

	// Constructor with parameters
	Animal(int age, float weight, string name);

	// Copy Constructor
	Animal(const Animal& obj);

	// Destructor
	virtual ~Animal()=default;

	int myStoi(const string& str) {
		try {
			size_t pos;
			int num = stoi(str, &pos);
			if (pos != str.length())
				throw invalid_argument("");
			return num;
		}
		catch (const invalid_argument& e) {
			throw MyException();
		}
	}

	// Input/Output methods
	istream& read(istream& in) override {
	cin.clear();
	cout << "\n Name: ";
	getline(in, name);
	while (true) {
		cout << "\n Age(months): ";
		string test;
		getline(cin, test);
		try {
			age = myStoi(test);
			if (cin.fail())
				throw invalid_argument("\n Invalid input type. Please enter a positive integer. \n");
			else if (age <= 0 && age <= 180)
				throw out_of_range("\n Wrong index\n");
			else if (to_string(age) != test)
				throw MyException();
			break;
		}
		catch (const out_of_range& e) {
			cout << e.what();
		}
		catch (const invalid_argument& e) {
			cout << e.what() << '\n';
			cin.clear();
			cin.ignore(256, '\n');
		}
		catch (const MyException& e) {
			cout << e.what() << "\n";
			cin.clear();
		}
		catch (...) {
			cout << "\n Invalid input";
		}
	}
	while (true) {
		cout << "\n Weight(kgs): ";
		string test;
		getline(cin, test);
		try {
			weight = myStoi(test);
			if (weight <= 0 || weight > 2500)
				throw out_of_range("\n Wrong input!\n");
			else if(cin.fail())
				throw invalid_argument("\n Invalid input type. Please enter a positive integer. \n");
			else if (to_string(int(weight)) != test)
				throw MyException();
			break;
		}
		catch (const out_of_range& e) {
			cout << e.what();
		}
		catch (const invalid_argument& e) {
			cout << e.what();
			cin.clear();
			cin.ignore(256, '\n');
		}
		catch (const MyException& e) {
			cout << e.what() << "\n";
			cin.clear();
		}
		catch (...) {
			cout << "\n Invalid input";
		}
	}

	return in;
	}

	ostream& print(ostream& out) const override {
		out << "\n Animal ID: " << id;
		out << "\n Name: " << name;
		out << "\n Age: " << age<<" months";
		out << "\n Weight: " << weight<<" kgs";
	
	return out;
	}

	// Assignment operator
	Animal& operator=(const Animal& obj);

	// Pure virtual method to get the price of the animal
	virtual float getPrice() const { return 0; }

	// getter id
	string getName() const { return name; }

	friend istream& operator>>(istream& in, Animal& obj);
	friend ostream& operator<<(ostream& out, const Animal& obj);
	
	// getter weight
	float getWeight() const { return weight; }

	bool operator<(const Animal& obj) const {
		if(weight==obj.weight)
			return id>obj.id;
		return weight < obj.weight;
	}

};

// Default Constructor
Animal::Animal(): age(0), weight(0), name("Unknown"), id(++idCounter) {}

// Constructor with parameters
Animal::Animal(int age, float weight, string name): age(age), weight(weight), name(name), id(++idCounter) {}

// Copy Constructor
Animal::Animal(const Animal& obj):age(obj.age), weight(obj.weight), name(obj.name), id(obj.id) {}

// Assignment operator
Animal& Animal::operator=(const Animal& obj) {
	if (this != &obj) {
		age = obj.age;
		weight = obj.weight;
		name = obj.name;
	}
	return *this;
}

// Input/Output operators
istream& operator>>(istream& in, Animal& obj) {
	return obj.read(in);
}

ostream& operator<<(ostream& out, const Animal& obj) {
	return obj.print(out);
}

int Animal::idCounter = 0;
