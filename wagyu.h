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
		int option;
		while (true) {
			cout << "\n Breed(1-Japanese, 2-American, 3-Australian): ";
			string test;
			getline(cin, test);
			try {
				option = myStoi(test);
				if (option < 1 || option>3)
					throw out_of_range("\n Wrong input!\n");
				else if (cin.fail())
					throw invalid_argument("\n Invalid input type!\n");
				else if (to_string(int(option)) != test)
					throw MyException();
				break;
			}
			catch (const out_of_range& e)
			{
				cout << e.what();
			}
			catch (const invalid_argument& e) {
				cout << e.what();
				cin.clear(); cin.ignore(256, '\n');
				cin.get();
			}
			catch (const MyException& e) {
				cout << e.what() << "\n";
				cin.clear();
			}
			catch (...) { cout << "\n Invalid input!"; }
		}
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
		
		while (true) {
			cout << "\n Grade(5-A5, 4-A4, 3-A3, 2-A2, 1-A1): ";
			string test;
			getline(cin, test);
			try {
				option = myStoi(test);
				if (option < 1 || option>5)
					throw out_of_range("\n Wrong input!\n");
				else if (cin.fail())
					throw invalid_argument("\n Invalid input type!\n");
				else if (to_string(int(option)) != test)
					throw MyException();
				break;
			}
			catch (const out_of_range& e)
			{
				cout << e.what();
			}
			catch (const invalid_argument& e) {
				cout << e.what();
				cin.clear(); cin.ignore(256, '\n');
				cin.get();
			}
			catch (const MyException& e) {
				cout << e.what() << "\n";
				cin.clear();
			}
			catch (...) { cout << "\n Invalid input!"; }
		}
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
		while (true) {
			cout << "\n Marbling score(1-100): ";
			string test;
			getline(cin, test);
			try {
				option = myStoi(test);
				if (option < 1 || option>100)
					throw out_of_range("\n Wrong input!\n");
				else if (cin.fail())
					throw invalid_argument("\n Invalid input type!\n");
				else if (to_string(int(option)) != test)
					throw MyException();
				break;
			}
			catch (const out_of_range& e)
			{
				cout << e.what();
			}
			catch (const invalid_argument& e) {
				cout << e.what();
				cin.clear(); cin.ignore(256, '\n');
				cin.get();
			}
			catch (const MyException& e) {
				cout << e.what() << "\n";
				cin.clear();
			}
			catch (...) { cout << "\n Invalid input!"; }
		}
		marbling = option;
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

