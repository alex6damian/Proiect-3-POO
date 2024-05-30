#pragma once
#include <iostream>
#include <list>
#include <cstdlib>
#include <string>
using namespace std;

class Employee
{
protected:
	list<string> tasks;
	string name;
	float salary;
public:
	// Default constructor
	Employee();

	// Constructor with parameters
	Employee(list<string>tasks, string name, float salary);

	// Copy constructor
	Employee(const Employee& obj);

	// Destructor
	~Employee() = default;
	
	// stoi method
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

	// Input method
	istream& read(istream& in) {
		
		int option;
		while (true) {
			cout << "\n Enter salary: ";
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
			catch (...) { cout << "\n Invalid input!";cin.clear(); }
		}
		salary = option;
		cout << "\n Enter name: ";
		getline(in, name);
		while (true) {
			cout << "\n Enter the number of tasks: ";
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
		for(int i=0;i<option;i++){
			string task;
			cout << "\n Enter task: ";
			getline(in, task);
			tasks.push_back(task);
		}
		return in;
	}

	// Output method
	ostream& print(ostream& out) const {
		out << "\n Name: " << name;
		out << "\n Salary: " << salary << "$";
		out << "\n Tasks: "<<tasks.size();
		int i = 0;
		for(auto task:tasks){
			
			out << "\n "<<++i<<". "<< task;
		}
		out << '\n';
		return out;
	}

	// Assignment operator
	Employee& operator=(const Employee& obj);

	// Getter salary
	float getSalary() const {
		return salary;
	}

	void setSalary(float salary) {
		this->salary = salary;
	}
	
	// getter tasks
	list<string> getTasks() const {
		return tasks;
	}

	// getter name	
	string getName() const {
		return name;
	}

	bool operator==(const Employee& obj);

	void addTask(string task);

	// Input/Output operators
	friend istream& operator>>(istream& in, Employee& obj);
	friend ostream& operator<<(ostream& out, const Employee& obj);
};
// Default constructor
Employee::Employee() : name("Unknown"), salary(500) {
	this->tasks = {};
}

// Constructor with parameters
Employee::Employee(list<string>tasks, string name, float salary): name(name), salary(salary)
{
	this->tasks.clear();
	this->tasks = tasks;
}
// Copy constructor
Employee::Employee(const Employee& obj):tasks(obj.tasks), name(obj.name), salary(obj.salary) {}

// Assignment operator
Employee& Employee::operator=(const Employee& obj) {
	if (this != &obj) {
		tasks = obj.tasks;
		name = obj.name;
		salary = obj.salary;
	}
	return *this;
}

// Input operator
istream& operator>>(istream& in, Employee& obj) {
	return obj.read(in);
}

// Output operator
ostream& operator<<(ostream& out, const Employee& obj) {
	return obj.print(out);
}

bool Employee::operator==(const Employee& obj) {
	return this->salary=obj.salary && this->name==obj.name && this->tasks==obj.tasks;
}

void Employee::addTask(string task){
	tasks.push_back(task);
	cout << "\n " << name << " has recieved a salary bonus!\n +200$";
	salary += 200;
}