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

	// stoi method
	int myStoi(const string& str) {
	try {
		size_t pos;
		int num = stoi(str, &pos); // convert string to integer with pos length
		if (pos != str.length())
			throw invalid_argument("");
		return num;
	}
	catch (const invalid_argument& e) {
		throw MyException();
	}
}
	// Input method
	istream& read(istream& in) override {
		cout << "\n Enter manager: ";
		getline(in, manager);
		int option;
		while (true) {
			cout << "\n Enter the number of normal cows: ";
			string test;
			getline(cin, test);
			try {
				option = myStoi(test);
				if (option < 0)
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

		for (int i = 0; i < option; i++) {
			try {
				Animal* a = new Cow();
				in >> *a;
				animals.push_back(a);
			}
			catch (const bad_alloc& e) {
				cout << e.what()<<'\n';
			}
			catch (...) {
				cout << "\n Unknown error!";
			}
		}

		
		while (true) {
			cout << " \n Enter the number of wagyu cows: ";
			string test;
			getline(cin, test);
			try {
				option = myStoi(test);
				if (option < 0)
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

		for (int i = 0; i < option; i++) {
			try {
				Animal* a = new Wagyu();
				in >> *a;
				animals.push_back(a);
			}
			catch (const bad_alloc& e) {
				cout << e.what()<<'\n';
			}
			catch (...) {
				cout << "\n Unknown error!";
			}
		}

		while (true) {
			cout << "\n Enter the number of employees: ";
			string test;
			getline(cin, test);
			try {
				option = myStoi(test);
				if (option < 0)
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

		for (int i = 0; i < option; i++) {
			Employee e;
			in >> e;
			employees.push_back(e);
		}


		while (true) {
			cout << "\n Enter the number of food types: ";
			string test;
			getline(cin, test);
			try {
				option = myStoi(test);
				if (option < 0)
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

		for (int i = 0;i < option;i++)
		{
			string food;
			int quantity;
			cout << "\n Food type: "; getline(in, food);
			while (true) {
				cout << "\n Quantity(kgs): ";
				string test;
				getline(cin, test);
				try {
					quantity = myStoi(test);
					if (quantity < 0)
						throw out_of_range("\n Wrong input!\n");
					if (cin.fail())
						throw invalid_argument("\n Invalid input type!\n");
					else if (to_string(int(quantity)) != test)
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

		out << "\n\n Employees: "<<employees.size();
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
	void sellAnimal(const Animal& obj) {

		this->soldAnimals.insert(obj);
		for (int i = 0; i < this->animals.size(); i++) {
				if (animals[i] == &obj) {
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
	vector<Employee> getEmployees() {
		return employees;
	}

	// setter employee
	void setEmployees(vector<Employee> employees) {
		this->employees = employees;
	}

	void setTask(int index, string task) {
		employees[index].addTask(task);
		employees[index].setSalary(employees[index].getSalary() + 200);
	}

	// setter animals
	void setAnimals(vector<Animal*> animals) {
		this->animals = animals;
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

	Farm& operator+(const Employee& obj);

	Farm& operator-(const Employee& obj);

	Farm& operator+(const Animal& obj);

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

	try {
		for (int i = 0;i < animals.size();i++)
			if (typeid(Wagyu) == typeid(*animals[i])) {
				this->animals.push_back(new Wagyu(dynamic_cast<Wagyu&>(*animals[i])));
			}
			else if (typeid(Cow) == typeid(*animals[i])) {
				this->animals.push_back(new Cow(dynamic_cast<Cow&>(*animals[i])));
			}
	}
	catch (const bad_alloc& e) {
		cout << e.what()<<'\n';
	}
	catch (const bad_cast& e) {
		cout<<e.what()<<'\n';
	}
	catch (...) {
		cout << "\n Unknown error!\n";
	}

}

// Copy constructor
Farm::Farm(const Farm& obj) : manager(obj.manager), soldAnimals(obj.soldAnimals), foodStock(obj.foodStock), employees(obj.employees) {
	
	for (int i = 0;i < this->animals.size();i++)
		delete this->animals[i];

	this->animals.clear();
	try {
		for (int i = 0;i < obj.animals.size();i++)
			if (typeid(Wagyu) == typeid(*obj.animals[i])) {
				this->animals.push_back(new Wagyu(dynamic_cast<Wagyu&>(*obj.animals[i])));
			}
			else if (typeid(Cow) == typeid(*obj.animals[i])) {
				this->animals.push_back(new Cow(dynamic_cast<Cow&>(*obj.animals[i])));
			}
	}
	catch (const bad_alloc& e) {
		cout << e.what() << '\n';
	}
	catch (const bad_cast& e) {
		cout << e.what() << '\n';
	}
	catch (...) {
		cout << "\n Unknown error!\n";
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
		try {
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
		catch(const bad_alloc &e){
			cout << e.what()<<'\n';
		}
		catch(const bad_cast &e){
			cout<<e.what()<<'\n';
		}
		catch(...){
			cout << "\n Unknown error!\n";
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

Farm& Farm::operator+(const Employee& obj) {
	this->employees.push_back(obj);
	return *this;
}

//DE REZOLVAT AICI(problema la clientii creati prin constructor default)
Farm& Farm::operator-(const Employee& obj) {
	for (int i = 0;i < this->employees.size();i++)
	{
		cout <<( this->employees[i]== obj);
		if (this->employees[i] == obj) {
			this->employees.erase(this->employees.begin() + i);
			break;
		}
	}
	return *this;
}

Farm& Farm::operator+(const Animal& obj) {

	try {
		if (typeid(obj) == typeid(Wagyu))
			this->animals.push_back(new Wagyu(dynamic_cast<const Wagyu&>(obj)));
		else if (typeid(obj) == typeid(Cow))
			this->animals.push_back(new Cow(dynamic_cast<const Cow&>(obj)));
	}
	catch (const bad_alloc& e) {
		cout << e.what()<<'\n';
	}
	catch (const bad_cast& e) {
		cout<<e.what()<<'\n';
	}
	catch (...) {
		cout << "\n Unknown error!";
	}

	return *this;
}