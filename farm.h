#pragma once
#include <iostream>
#include "animal.h"
#include <set>
#include <map>
#include <vector>
#include "IOInterface.h"
#include "employee.h"
#include <string>
#include "wagyu.h"
#include "cow.h"
using namespace std;

class Farm : public IOInterface {
protected:
	string manager;
	set<Animal> soldAnimals;
	map<string, int> foodStock;
	vector<Animal*> animals;
	vector<Employee> employees;
public:
	// Default constructor
	Farm();
	
	// Constructor with parameters
	Farm(string manager, set<Animal> soldAnimals, map<string,int>foodStock, vector<Animal*> animals, vector<Employee>employees);

	// Copy constructor
	Farm(const Farm& obj);

	// Destructor
	~Farm();

	// Input method
	istream& read(istream& in) override {
		in.get();
		cout << "\n Enter manager: ";
		getline(in, manager);
		cout << "\n Enter the number of normal cows: ";
		int n;
		in >> n;

		for (int i = 0; i < n; i++) {
			in.get();
			Animal* a = new Cow();
			in >> *a;
			animals.push_back(a);
		}

		cout << " \n Enter the number of wagyu cows: ";
		in >> n;

		for (int i = 0; i < n; i++) {
			in.get();
			Animal* a = new Wagyu();
			in >> *a;
			animals.push_back(a);
		}

		cout << "\n Enter the number of employees: ";
		in >> n;

		for (int i = 0; i < n; i++) {
			in.get();
			Employee e;
			in >> e;
			employees.push_back(e);
		}

		cout << "\n Enter the number of food types: ";
		in >> n;

		for (int i = 0;i < n;i++)
		{
			in.get();
			string food;
			int quantity;
			cout << "\n Food type: "; getline(in, food);
			cout << "\n Quantity(kgs): "; in >> quantity;
			foodStock[food] = quantity;
		}

		return in;
	}

	// Output method
	ostream& print(ostream& out) const override {
		out << "\n Manager: " << manager;

		out << "\n Cows: "<<animals.size();

		for (int i = 0; i < animals.size(); i++) 
			out << *animals[i]<<"\n";

		out<<"\n Sold animals: "<<soldAnimals.size();
		for (auto it = soldAnimals.begin(); it != soldAnimals.end(); it++) {
			out << "\n " << *it;
		}

		out << "\n Employees: "<<employees.size();
		for (int i = 0; i < employees.size(); i++) 
			out << employees[i];
		
		out << "\n Food stock: ";
		for (auto it = foodStock.begin(); it != foodStock.end(); it++) {
			out << "\n " << it->first << " " << it->second<<"kgs";
		}
		cout << "\n\n";
		return out;
	}

	// Assignment operator
	Farm& operator=(const Farm& obj);

	// Selling animals
	void sellAnimal(int index) {
		if (typeid(Cow) == typeid(*animals[index])) {
			Cow copy = dynamic_cast<Cow&>(*animals[index]);
			this->soldAnimals.insert(copy);
		}
		else if (typeid(Wagyu) == typeid(*animals[index])){
			Wagyu copy = dynamic_cast<Wagyu&>(*animals[index]);
			this->soldAnimals.insert(copy);
		}
		for (int i = 0; i < this->animals.size(); i++) {
				if (animals[i] == this->animals[index]) {
				this->animals.erase(this->animals.begin() + i);
				break;
			}
		}
	}

	// getter animals
	const vector<Animal*> getAnimals() {
		return animals;
	}

	// getter employees
	const vector<Employee> getEmployees() {
		return employees;
	}

	// setter animals
	void setAnimals(vector<Animal*> animals) {
		this->animals = animals;
	}

	// setter employees
	void setEmployees(vector<Employee> employees) {
		this->employees = employees;
	}

	const string getManager() const{
		return manager;
	}

	void highestPaidEmployee() const {
		try {
			if(employees.size()==0)
				throw out_of_range("\n Error! No employees found!");
			Employee max = employees[0];
			for (int i = 1; i < employees.size(); i++) {
				if (employees[i].getSalary() > max.getSalary()) {
					max = employees[i];
				}
			}
			cout << max;
		}
		catch (out_of_range& e) {
			cout << e.what();
		}
	}

	void busiestEmployee() const{
		
		try {
			if(employees.size()==0)
				throw out_of_range("\n Error! No employees found!");
			Employee max = employees[0];
			for (int i = 1; i < employees.size(); i++) {
				if (employees[i].getTasks().size() > max.getTasks().size()) {
					max = employees[i];
				}
			}
			cout << max;	
		}
		catch (out_of_range& e) {
			cout << e.what();
		}

	}

	friend istream& operator>>(istream& in, Farm& obj);
	friend ostream& operator<<(ostream& out, const Farm& obj);
};

// Default constructor
Farm::Farm():manager("Unknown") {}

// Constructor with parameters
Farm::Farm(string manager, set<Animal> soldAnimals, map<string, int> foodStock, vector<Animal*> animals, vector<Employee> employees) {
	this->manager = manager;
	this->soldAnimals = soldAnimals;
	this->foodStock = foodStock;
	this->employees = employees;

	for(int i=0;i<this->animals.size();i++)
		delete this->animals[i];

	this->animals.clear();

	for(int i=0;i<animals.size();i++)
		if (typeid(Cow) == typeid(*animals[i])) {
			Animal* a = new Cow(dynamic_cast<Cow&>(*animals[i]));
			this->animals.push_back(a);
		}
		else if(typeid(Wagyu) == typeid(*animals[i])) {
			Animal* a = new Wagyu(dynamic_cast<Wagyu&>(*animals[i]));
			this->animals.push_back(a);
		}
}

// Copy constructor
Farm::Farm(const Farm& obj) : manager(obj.manager), soldAnimals(obj.soldAnimals), foodStock(obj.foodStock), employees(obj.employees) {
	
	for (int i = 0;i < this->animals.size();i++)
		delete this->animals[i];

	this->animals.clear();

	for (int i = 0;i < animals.size();i++)
		if (typeid(Cow) == typeid(*animals[i])) {
			Animal* a = new Cow(dynamic_cast<Cow&>(*animals[i]));
			this->animals.push_back(a);
		}
		else if (typeid(Wagyu) == typeid(*animals[i])) {
			Animal* a = new Wagyu(dynamic_cast<Wagyu&>(*animals[i]));
			this->animals.push_back(a);
		}
}

// Destructor
Farm::~Farm() {
	for (int i = 0; i < this->animals.size(); i++) {
		delete animals[i];
	}
	soldAnimals.clear();
	foodStock.clear();
	animals.clear();
	employees.clear();
}

//Assignment operator
Farm& Farm::operator=(const Farm& obj) {
	if (this != &obj) {
		manager = obj.manager;
		soldAnimals = obj.soldAnimals;
		foodStock = obj.foodStock;
		employees = obj.employees;

		for (int i = 0;i < this->animals.size();i++)
			delete this->animals[i];

		this->animals.clear();

		for (int i = 0;i < animals.size();i++)
			if (typeid(Cow) == typeid(*animals[i])) {
				Animal* a = new Cow(dynamic_cast<Cow&>(*animals[i]));
				this->animals.push_back(a);
			}
			else if (typeid(Wagyu) == typeid(*animals[i])) {
				Animal* a = new Wagyu(dynamic_cast<Wagyu&>(*animals[i]));
				this->animals.push_back(a);
			}
	}
	return *this;
}

// Input operator
istream& operator>>(istream& in, Farm& obj) {
	return obj.read(in);
}

// Output operator
ostream& operator<<(ostream& out, const Farm& obj) {
	return obj.print(out);
}