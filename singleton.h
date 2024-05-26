#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "bids.h"
#include <ctime>
#include <cstdlib>
#include "exception.h"
using namespace std;

class Singleton {
private:

	static Singleton* instance;
	vector<Farm*> farms;

	// Default Constructor
	Singleton() = default;

	// Destructor
	~Singleton() {
		if (instance != NULL) {
			delete instance;
		}
	}
public:

	static Singleton* getInstance() {
		if (instance == NULL) {
			instance = new Singleton();
		}
		return Singleton::instance;
	}

	// Disable copy constructor
	Singleton(const Singleton&) = delete;

	// Disable assignment operator
	Singleton& operator=(const Singleton&) = delete;

	void addFarm(Farm& farm) {
		farms.push_back(&farm);
	}

	// Create method
	template<class T>
	T create() {
		T obj;
		cin >> obj;
		cin.get();
		return obj;
	}

	// Print method
	template<class T>
	void print(const T* obj) const{
		cout << *obj;
	}

	void run();

	void manageFarm(Farm& obj);

	void farmInfo(const Farm& obj);

	void deleteFarm(const Farm& obj);

	void bids(Farm& obj);

	int myStoi(const string& str);

};

Singleton* Singleton::instance = NULL;

// de rezolvat exceptiile
void Singleton::run() {
	int k = 1;

	while (k) {
		cout << "\n\n 1. Add a new farm" << endl;
		cout << " 2. Get informations" << endl;
		cout << " 3. Manage a farm" << endl;
		cout << " 4. Delete a farm" << endl;
		cout << " 5. Exit" << endl;

		int option;
		while (true) {
			cout << " Enter your choice: ";
			cin >> option;
			try {
				if (cin.fail())
					throw invalid_argument("\n Invalid input");
				else if (option < 1 || option>5 || option%10>9)
					throw out_of_range("\n Index out of range");
				else break;
			}
			catch (out_of_range& e) {
				cout << e.what() << '\n';
			}
			catch (const invalid_argument& e) {
				cout << e.what() << '\n';
				cin.clear();
				cin.ignore(256, '\n');
			}
			catch (...) {
				cout << "\n Invalid input";
			}
		}
			switch (option) {
			case 1: {
				cout << "\n Create" << '\n';
				Farm f = create<Farm>();
				addFarm(f);
				break;
			}
			case 2: {
				cout << "\n Get informations" << '\n';
				cout << " Select a farm by its manager:";
				for (int i = 0;i < farms.size();i++) {
					cout << "\n " << i + 1 << ". " << farms[i]->getManager();
				}
				int index;
				while (true) {
					cout << "\n Enter the index of the farm: ";
					cin >> index;
					try {
						if (cin.fail())
							throw invalid_argument("\n Invalid input");
						if (index < 1 || index > farms.size())
							throw out_of_range(" Index out of range");
						break;
					}
					catch (out_of_range& e) {
						cout << e.what();
					}
					catch (const invalid_argument& e) {
						cout << e.what() << '\n';
						cin.clear();
						cin.ignore(256, '\n');
					}
					catch (...) {
						cout << "\n Invalid input";
					}
				}
				farmInfo(*farms[index - 1]);
				break;
			}
			case 3: {
				cout << "\n Manage a farm" << '\n';
				cout << " Select a farm by its manager:";
				for (int i = 0;i < farms.size();i++) {
					cout << "\n " << i + 1 << ". " << farms[i]->getManager();
				}
				int index;
				while (true) {
					cout << "\n Enter the index of the farm: ";
					cin >> index;
					try {
						if (cin.fail())
							throw invalid_argument("\n Invalid input");
						if (index < 1 || index > farms.size())
							throw out_of_range(" Index out of range");
						break;
					}
					catch (out_of_range& e) {
						cout << e.what();
					}
					catch (const invalid_argument& e) {
						cout << e.what() << '\n';
						cin.clear();
						cin.ignore(256, '\n');
					}
					catch (...) {
						cout << "\n Invalid input";
					}
				}
				manageFarm(*farms[index - 1]);
				break;
			}
			case 4: {
				if (farms.size()) {
					cout << "\n Delete a farm" << '\n';
					cout << " Select a farm by its manager:";
					for (int i = 0;i < farms.size();i++) {
						cout << "\n " << i + 1 << ". " << farms[i]->getManager();
					}
					int index;
					while (true) {
						cout << "\n Enter the index of the farm: ";
						cin >> index;
						try {
							if (cin.fail())
								throw invalid_argument("\n Invalid input");
							if (index < 1 || index > farms.size())
								throw out_of_range(" Index out of range");
							break;
						}
						catch (out_of_range& e) {
							cout << e.what();
						}
						catch (const invalid_argument& e) {
							cout << e.what() << '\n';
							cin.clear();
							cin.ignore(256, '\n');
						}
						catch (...) {
							cout << "\n Invalid input";
						}
					}
				deleteFarm(*farms[index - 1]);
				}
				else {
					cout << "\n There are no farms to delete";
				}
				break;
			}
			case 5: {
				cout << "\n Exit" << '\n';
				k = 0;
				break;}
			}
	}
}

// de rezolvat exceptiile
void Singleton::manageFarm( Farm& obj) {
	cout << "\n\n You have selected the farm managed by " << obj.getManager();
	cout << "\n Select what type of operation you would like to perform:";
	list<string> tasks;
	srand(static_cast<unsigned int>(time(NULL)));
	Employee e1(tasks, "John", rand()%10000);
	Employee e2(tasks, "Alice", rand() % 10000);
	Employee e3(tasks, "Bob", rand() % 10000);
	Employee e4(tasks, "Charlie", rand() % 10000);
	Employee e5(tasks, "David", rand() % 10000);
	vector<Employee> employees;
	employees.push_back(e1);
	employees.push_back(e2);
	employees.push_back(e3);
	employees.push_back(e4);
	employees.push_back(e5);
	int k = 1;
	while (k) {

		cout << "\n\n 1. Hire a new employee";
		cout << "\n 2. Fire an employee";
		cout << "\n 3. Assign a task to an employee";
		cout<< "\n 4. Get a new cow";
		cout<< "\n 5. Sell a cow";
		cout << "\n 6. Bid for cows";
		cout << "\n 7. Return to the main menu";
		int option;
		while (true) {
			cout<<"\n Enter your choice: ";
			cin >> option;
			try {
				if (cin.fail())
					throw invalid_argument("\n Invalid input");
				if(option<1 || option>7)
					throw out_of_range("\n Index out of range");
			break;
			}
			catch (out_of_range& e) {
				cout << e.what();
			}
			catch (const invalid_argument& e) {
				cout << e.what() << '\n';
				cin.clear();
				cin.ignore(256, '\n');
			}
			catch (...) {
				cout << "\n Invalid input";
			}
		}
		
		switch (option) {
		case 1: {
			if (employees.size()) {
			cout << "\n\n Select an employee to hire: ";
			for (int i = 0;i < employees.size();i++) {
				cout << "\n " << i + 1 << ". " << employees[i].getName();
				cout<<", requested salary: "<<employees[i].getSalary()<<"$";
			}
			int index;
			while (true) {
					cout << "\n Enter the index of the employee: ";
					cin >> index;
					try {
						if (cin.fail())
							throw invalid_argument("\n Invalid input");
						if (index<1 || index>employees.size())
							throw out_of_range("\n Index out of range");
						
						break;
					}
					catch (out_of_range& e) {
						cout << e.what();
					}
					catch (const invalid_argument& e) {
						cout << e.what() << '\n';
						cin.clear();
						cin.ignore(256, '\n');
					}
					catch (...) {
						cout << "\n Invalid input";
					}
				}
				obj = obj + employees[index - 1];
				employees.erase(employees.begin() + index - 1);
				cout << " The employee has been successfully hired";
			}
			else cout << "\n There are no more employees to hire";
			break;}
		case 2: {
			if (obj.getEmployees().size()) {
				cout << "\n\n Select an employee to fire: ";
				for (int i = 0;i < obj.getEmployees().size();i++) {
					cout << "\n " << i + 1 << ". " << obj.getEmployees()[i].getName();
				}
				int index;
				while (true) {
					cout << "\n Enter the index of the employee: ";
					cin >> index;
					try {
						if (cin.fail())
							throw invalid_argument("\n Invalid input");
						if (index<1 || index>employees.size())
							throw out_of_range("\n Index out of range");
						
						break;
					}
					catch (out_of_range& e) {
						cout << e.what();
					}
					catch (const invalid_argument& e) {
						cout << e.what() << '\n';
						cin.clear();
						cin.ignore(256, '\n');
					}
					catch (...) {
						cout << "\n Invalid input";
					}
				}
				obj = obj - obj.getEmployees()[index - 1];
				cout << " The employee has been successfully fired";
			}
			else {
				cout << "\n There are no employees to fire";
			}
			break;}
		case 3: {
			if (obj.getEmployees().size()) {
				cout << "\n\n Select an employee to assign a task: ";
				for (int i = 0;i < obj.getEmployees().size();i++) {
					cout << "\n " << i + 1 << ". " << obj.getEmployees()[i].getName();
				}
				int index;
				while (true) {
					cout << "\n Enter the index of the employee: ";
					cin >> index;
					try {
						if (cin.fail())
							throw invalid_argument("\n Invalid input");
						if (index<1 || index>employees.size())
							throw out_of_range("\n Index out of range");

						break;
					}
					catch (out_of_range& e) {
						cout << e.what();
					}
					catch (const invalid_argument& e) {
						cout << e.what() << '\n';
						cin.clear();
						cin.ignore(256, '\n');
					}
					catch (...) {
						cout << "\n Invalid input";
					}
				}
				string task;
			cout << "\n Enter the task: ";
			cin.get();
			getline(cin, task);
			obj.setTask(index-1, task);
			}
			else {
				cout << "\n There are no employees!";
			}
			break;}
		case 4: {
			cout << "\n Select a cow to buy:";
			cout << "\n 1. Wagyu cow";
			cout << "\n 2. Romanian cow";
			int index;
			while (true) {
				cout << "\n Enter the index of the cow: ";
				cin >> index;
				try {
					if (cin.fail())
						throw invalid_argument("\n Invalid input");
					if (index<1 || index>employees.size())
						throw out_of_range("\n Index out of range");

					break;
				}
				catch (out_of_range& e) {
					cout << e.what();
				}
				catch (const invalid_argument& e) {
					cout << e.what() << '\n';
					cin.clear();
					cin.ignore(256, '\n');
				}
				catch (...) {
					cout << "\n Invalid input";
				}
			}
			if (index == 1) {
				cin.get();
				obj=obj + create<Wagyu>();
			}
			else if (index == 2) {
				cin.get();
				obj = obj + create<Cow>();
			}
			break;}
		case 5: {
			if (obj.getAnimals().size()) {
				cout << "\n Select a cow to sell:";
				for (int i = 0;i < obj.getAnimals().size();i++) {
					cout << "\n " << i + 1 << ". " << obj.getAnimals()[i]->getName();
					cout<<", price: "<<obj.getAnimals()[i]->getPrice()<<"$";
				}
				int index;
				while (true) {
					cout << "\n Enter the index of the cow: ";
					cin >> index;
					try {
						if (cin.fail())
							throw invalid_argument("\n Invalid input");
						if (index<1 || index>obj.getAnimals().size())
							throw out_of_range("\n Index out of range");

						break;
					}
					catch (out_of_range& e) {
						cout << e.what();
					}
					catch (const invalid_argument& e) {
						cout << e.what() << '\n';
						cin.clear();
						cin.ignore(256, '\n');
					}
					catch (...) {
						cout << "\n Invalid input";
					}
				}
				cout<<"\n The cow has been successfully sold for "<<obj.getAnimals()[index-1]->getPrice()<<"$";
				obj.sellAnimal(*obj.getAnimals()[index-1]);

			}
			else cout<<"\n There are no cows to sell";
			break;
		}
		case 6: {
			cout<<"\n Bid for cows";
			bids(obj);
			break;
		}
		case 7: {
			k = 0;
			break;
		}
		}
	}

}

// exceptii tratate
void Singleton::farmInfo(const Farm& obj) {
	cout << "\n\n You have selected the farm managed by " << obj.getManager();
	cout << "\n Select what type of information you would like to get:";
	int k = 1;
	while (k) {
		cout << "\n 1. Display all information";
		cout << "\n 2. Display the highest paid employee";
		cout << "\n 3. Display the busiest employee(by the number of tasks)";
		cout << "\n 4. Return to the main menu";
		int index;
		while (true) {
			cout << "\n Enter your choice : ";
			cin >> index;
			try {
				if (cin.fail())
					throw invalid_argument("\n Invalid input");
				if (index<1 || index>4)
					throw out_of_range("\n Index out of range");
				break;
			}
			catch (out_of_range& e) {
				cout << e.what();
			}
			catch (const invalid_argument& e) {
				cout << e.what() << '\n';
				cin.clear();
				cin.ignore(256, '\n');
			}
			catch (...) {
				cout << "\n Invalid input";
			}
		}
		switch (index) {
		case 1: {
			print<Farm>(farms[index-1]);
			break;
		}
		case 2: {
			cout << "\n The highest paid employee is: ";
			obj.highestPaidEmployee();
			break;
		}
		case 3: {
			cout << "\n The busiest employee is: ";
			obj.busiestEmployee();
			break;
		}
		case 4: {
			k = 0;
			break;
		}
		}
	}
}

void Singleton::deleteFarm(const Farm& obj) {
	for (int i = 0;i < farms.size();i++) {
		if (farms[i] == &obj) {
			farms.erase(farms.begin() + i);
			break;
		}
	}
	cout<<"\n The farm has been successfully deleted";
}

void Singleton::bids(Farm& obj) {
	srand(static_cast<unsigned int>(time(NULL)));
	Licitatie<Cow> lCows;
	Licitatie<Wagyu> lWagyu;
	Cow c1(rand()%100+5, rand() % 2000 + 200, "Cow 1", "Brown", "Meat", rand()%2);
	Cow c2(rand()%100+5, rand() % 2000 + 100, "Cow 2", "Black", "Milk", rand()%2);
	Wagyu w1(rand()%100+10, rand()%2000+300, "Wagyu 1", "White", "Meat", rand()%2, "Australian", "A4", rand()%100);
	Wagyu w2(rand()%150+20, rand() % 2000 + 300, "Wagyu 2", "Brown", "Milk", rand()%2, "Japanese", "A5", rand()%100);
	lCows.addBid(c1, c1.getWeight()*10);
	lCows.addBid(c2, c2.getWeight()*10);
	lWagyu.addBid(w1, w1.getWeight()*100);
	lWagyu.addBid(w2, w2.getWeight()*100);

	cout << "\n 1. Normal cows";
	cout << "\n 2. Wagyu cows";
	string nr;
	int index;
	cin.get();
	while (true) {
		cout<<"\n Select the type of cows: ";		
		
		getline(cin, nr);
		try {
			if(cin.fail())
				throw invalid_argument("\n Invalid input");
			index = myStoi(nr);
			if(to_string(index)!=nr)
				throw MyException();
			else if (index<1 || index>2)
				throw out_of_range("\n Index out of range");
			break;
		}
		catch (const out_of_range& e) {
			cout << e.what()<<'\n';
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
	if (index == 1 && lCows.getBids().size()) {
		cout<<"\n Available normal cows: \n";
		const Animal* a = lCows.tryBid();
		if (a) obj=obj+*a;
	}
	else if (index == 2 && lWagyu.getBids().size()) {
		cout<<"\n Available Wagyu cows: \n";
		const Animal* a = lWagyu.tryBid();
		if (a) obj=obj+*a;
	}
}

int Singleton::myStoi(const string& str) {
	try {
		size_t pos;
		int num = stoi(str, &pos);
		if (pos != str.length())
			throw invalid_argument("");
		return num;
	}
	catch (const invalid_argument& e) {
		throw MyException();
		return 0;
	}
}