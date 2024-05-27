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
		int option;
		while (true) {
			cout << "\n Color(1-Black, 2-Brown, 3-White): ";
			string test;
			getline(cin, test);
			try {
				option = myStoi(test);
				if (option < 1 || option>3)
					throw out_of_range("\n Wrong input!\n");
				if (cin.fail())
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
			}
			catch (const MyException& e) {
				cout << e.what() << "\n";
				cin.clear();
			}
			catch (...) { cout << "\n Invalid input!"; }
		}
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
		while (true) {
			cout << "\n Usage(1-Milk, 2-Meat, 3-Both): ";
			string test;
			getline(cin, test);
			try {
				option = myStoi(test);
				if (option < 1 || option>3)
					throw out_of_range("\n Wrong input!\n");
				if (cin.fail())
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
			}
			catch (const MyException& e) {
				cout << e.what() << "\n";
				cin.clear();
			}
			catch (...) { cout << "\n Invalid input!"; }
		}
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
		while (true) {
			cout << "\n Is pregnant?(1-Yes, 0-No): ";
			string test;
			getline(cin, test);
			try {
				option = myStoi(test);
				if (option < 0 || option>1)
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
		isPregnant = option;

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

	void setPrice(float price) {
		this->price = price;
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