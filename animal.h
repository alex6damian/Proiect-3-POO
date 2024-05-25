#pragma once
#include <iostream>
#include "IOInterface.h"
#include <string>
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

	// Input/Output methods
	istream& read(istream& in) override {
	cout << "\n Name: ";
	getline(in, name);
	while (true) {
		cout << "\n Age(months): ";
		in >> age;
		try {
			
			if ((age <= 0 && age <=120) || cin.fail())
				throw invalid_argument("\n Invalid input type. Please enter a positive integer. \n");
			break;
		}
		catch (const invalid_argument &e) {
			cout << e.what();
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
	while (true) {
		cout << "\n Weight(kgs): ";
		in >> weight;
		try {

			if (weight <= 0 || cin.fail())
				throw invalid_argument("\n Invalid input type. Please enter a positive integer. \n");
			break;
		}
		catch (const invalid_argument& e) {
			cout << e.what();
			cin.clear();
			cin.ignore(256, '\n');
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
