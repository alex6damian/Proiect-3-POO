#pragma once
#include <iostream>
#include "animal.h"
using namespace std;

class Cow : virtual public Animal {
protected:
	string color; // black, brown, white
	string usage; // milk, meat, both
	bool isPregnant; // true, false
	float price; // $/kg

public:
	// Default Constructor
	Cow();

	// Constructor with parameters
	Cow(int age, float weight, string name, string color, string usage, bool isPregnant);

	// Copy Constructor
	Cow(const Cow& obj);

	// Destructor
	~Cow() = default;

	// Input method
	istream& read(istream& in) override {
		Animal::read(in);
		cout << "\n Color(1-Black, 2-Brown, 3-White): ";
		int option;
		in >> option;
		switch (option) {
		case 1: {
			color = "Black";
			break;}
		case 2: {
			color = "Brown";
			break;}
		case 3: {
			color = "White";
			break;}
		}
		cout << "\n Usage(1-Milk, 2-Meat, 3-Both): ";
		in >> option;
		switch (option) {
		case 1: {
			usage = "Milk";
			break;}
		case 2: {
			usage = "Meat";
			break;
		}
		case 3: {
			usage = "Both";
			break;
		}
		}
		cout << "\n Is Pregnant(1-True, 0-False): ";
		in >> isPregnant;

		this->price=weight*10;

		return in;
	}

	// Output method
	ostream& print(ostream& out) const override {
		Animal::print(out);
		out << "\n Color: " << color;
		out << "\n Usage: " << usage;
		out << "\n Price: " << price<<"$";
		out << "\n Is Pregnant: ";
		if (isPregnant)
			out << "Yes";
		else
			out << "No";

		return out;
	}

	float getPrice() const override {
		return weight*10;
	}

	// Assignment Operator
	Cow& operator=(const Cow& obj);

};

// Default Constructor
Cow::Cow() : Animal(), color("Unknown"), usage("Unknown"), isPregnant(false), price(0) {}

// Constructor with parameters
Cow::Cow(int age, float weight, string name, string color, string usage, bool isPregnant) : Animal(age, weight, name), color(color), usage(usage), isPregnant(isPregnant), price(weight*10) {}

// Copy Constructor
Cow::Cow(const Cow& obj) : Animal(obj), color(obj.color), usage(obj.usage), isPregnant(obj.isPregnant), price(obj.price) {}

// Assignment Operator
Cow& Cow::operator=(const Cow& obj) {
	if (this != &obj) {
		Animal::operator=(obj);
		color = obj.color;
		usage = obj.usage;
		isPregnant = obj.isPregnant;
		price = obj.price;
	}
	return *this;
}