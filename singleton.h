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
			break;
		}
		case 2: {
			cout << "\n Read" << '\n';
			break;
		}
		case 3: {
			cout << "\n Update" << '\n';
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