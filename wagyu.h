#pragma once
#include <iostream>
#include "animal.h"
#include "cow.h"
using namespace std;

class Wagyu : public Cow {
protected:
	string breed; // Japanese, American, Australian
	string grade; // A5, A4, A3, A2, A1
	float marbling; // 0-100

public:
	// Default Constructor
	Wagyu();

	// Constructor with parameters
	Wagyu(int age, float weight, string name, string color, string usage, bool isPregnant, string breed, string grade, float marbling);

	// Copy Constructor
	Wagyu(const Wagyu& obj);

	// Destructor
	~Wagyu()=default;

	// Input method
	istream& read(istream& in) override {
		Cow::read(in);
		cout << "\n Breed(1-Japanese, 2-American, 3-Australian): ";
		int option;
		in >> option;
		switch (option) {
		case 1: {
			breed = "Japanese";
			break;
			}
		case 2: {
			breed = "American";
			break;
			}
		case 3: {
			breed = "Australian";
			break;
		}
		}
		cout << "\n Grade(5-A5, 4-A4, 3-A3, 2-A2, 1-A1): ";
		in >> option;
		switch (option) {
		case 5: {
				grade = "A5";
				break;
			}
		case 4: {
				grade = "A4";
				break;
			}
		case 3: {
				grade = "A3";
				break;
			}
		case 2: {
				grade = "A2";
				break;
			}
		case 1: {
				grade = "A1";
				break;
			}
		}
		cout << "\n Marbling score(0-100): ";
		in >> marbling;
		this->price=weight*10*marbling/10;
		return in;
	}

	// Output method
	ostream& print(ostream& out) const override {
		Cow::print(out);
		out << "\n Breed: " << breed;
		out << "\n Grade: " << grade;
		out << "\n Marbling score: " << marbling;

		return out;
	}

	// Assignment Operator
	Wagyu& operator=(const Wagyu& obj);

	float getPrice() const override{
		return price;
	}

};

// Default Constructor
Wagyu::Wagyu() : Animal(), Cow(), breed("Unknown"), grade("Unknown"), marbling(0) {}

// Constructor with parameters
Wagyu::Wagyu(int age, float weight, string name, string color, string usage, bool isPregnant, string breed, string grade, float marbling) :Animal(age, weight, name), Cow(age, weight, name, color, usage, isPregnant), breed(breed), grade(grade), marbling(marbling) {
	this->price=weight*100;
}

// Copy Constructor
Wagyu::Wagyu(const Wagyu& obj) : Animal(obj), Cow(obj), breed(obj.breed), grade(obj.grade), marbling(obj.marbling) {}

// Assignment Operator
Wagyu& Wagyu::operator=(const Wagyu& obj) {
	if (this != &obj) {
		Cow::operator=(obj);
		breed = obj.breed;
		grade = obj.grade;
		marbling = obj.marbling;
	}
	return *this;
}

// Input/Output operators
istream& operator>>(istream& in, Wagyu& obj) {
	return obj.read(in);
}

ostream& operator<<(ostream& out, const Wagyu& obj) {
	return obj.print(out);
}

