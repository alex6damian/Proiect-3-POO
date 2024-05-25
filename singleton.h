#pragma once
#include <iostream>

using namespace std;

class Singleton {
private:

	static Singleton* instance;
	vector<Farm> farms;

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

	void addFarm(const Farm& farm) {
		farms.push_back(farm);
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
	void print(T obj) {
		cout << obj;
	}

	void run();

	void manageFarm( Farm& obj);

	void farmInfo(const Farm& obj);
};

Singleton* Singleton::instance = NULL;

void Singleton::run() {
	int k = 1;

	while (k) {
		cout << "\n\n 1. Add a new farm" << endl;
		cout << " 2. Get informations" << endl;
		cout << " 3. Manage a farm" << endl;
		cout << " 4. Delete a farm" << endl;
		cout << " 5. Exit" << endl;
		cout << " Enter your choice: ";
		int option;
		cin >> option;
		switch (option) {
		case 1: {
			cout << "\n Create" << '\n';
			addFarm(create<Farm>());
			break;
		}
		case 2: {
			cout << "\n Get informations" << '\n';
			cout << " Select a farm by its manager:";
			for(int i=0;i<farms.size();i++){
				cout << "\n " << i + 1 << ". " << farms[i].getManager();
			}
		int index;
		while(true) {
			cout<<"\n Enter the index of the farm: ";
			cin>>index;
			try {
				if(cin.fail())
					throw invalid_argument("\n Invalid input");
				if(index < 0 || index > farms.size())
					throw out_of_range(" Index out of range");
				break;
			} catch (out_of_range& e) {
				cout << e.what();
			}
			catch(const invalid_argument &e){
				cout<<e.what()<<'\n';
				cin.clear();
				cin.ignore(256, '\n');
			}
			catch(...) {
				cout << "\n Invalid input";
			}
		}
			farmInfo(farms[index - 1]);
			break;
		}
		case 3: {
			cout << "\n Manage a farm" << '\n';
			cout << " Select a farm by its manager:";
			for (int i = 0;i < farms.size();i++) {
				cout << "\n " << i + 1 << ". " << farms[i].getManager();
			}
			int index;
			while (true) {
				cout << "\n Enter the index of the farm: ";
				cin >> index;
				try {
					if (cin.fail())
						throw invalid_argument("\n Invalid input");
					if (index < 0 || index > farms.size())
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
			manageFarm(farms[index - 1]);
			break;
		}
		case 4: {
			cout << "\n Delete" << '\n';
			break;
		}
		case 5: {
			cout << "\n Exit" << '\n';
			k = 0;
			break;}
		}
	}
}

void Singleton::manageFarm( Farm& obj) {
	cout << "\n\n You have selected the farm managed by " << obj.getManager();
	cout << "\n Select what type of operation you would like to perform:";
	int k = 1;
	while (k) {


		int option;
		cin >> option;
		switch (option) {
		case 1: {

			break;}
		case 2: {

			break;}
		case 3: {

			break;}
		case 4: {

			break;}
		case 5: {

			break;
		}
		case 6: {
			k = 0;
			break;
		}
		}
	}

}

void Singleton::farmInfo(const Farm& obj) {
	cout << "\n\n You have selected the farm managed by " << obj.getManager();
	cout << "\n Select what type of information you would like to get:";
	int k = 1;
	while (k) {
		cout << "\n 1. Display all information";
		cout << "\n 2. Display the highest paid employee";
		cout << "\n 3. Display the busiest employee(by the number of tasks)";
		cout << "\n 4. Return to the main menu";
		cout << "\n Enter your choice: ";
		int option;
		cin >> option;
		switch (option) {
		case 1: {
			cout << obj;
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