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
	
	// Input method
	istream& read(istream& in) {
		cout << "\n Enter salary: ";
		in >> salary;
		in.get();
		cout << "\n Enter name: ";
		getline(in, name);
		cout<< "\n Number of tasks: ";
		int n;
		in >> n;
		in.get();
		for(int i=0;i<n;i++){
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
	
	// getter tasks
	list<string> getTasks() const {
		return tasks;
	}

	// Input/Output operators
	friend istream& operator>>(istream& in, Employee& obj);
	friend ostream& operator<<(ostream& out, const Employee& obj);
};
// Default constructor
Employee::Employee() : name(""), salary(0) {
	this->tasks.clear();
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