#pragma once
#include <iostream>
#include <map>
#include <string>
using namespace std;

template<class T>
class Licitatie {
protected:
	map<T, float> bids;
public:
	// CD
	Licitatie() {}

	// CP
	Licitatie(map<T, float> bids) {
		this->bids = bids;
	}

	// CC
	Licitatie(const Licitatie& l) {
		this->bids = l.bids;
	}

	void addBid(T obj, float price) {
		bids[obj] = price;
	}

	void displayBids() {
		int i = 1;
		for (auto it = bids.begin(); it != bids.end(); it++) {
			cout << "\n Animal number "<<i++ << it->first << "\n Price: " << it->second << "$ \n";
		}
	}

	// Bid function
	const T* tryBid() {
		this->displayBids();
		int i;
		while (true) {
			cout << "\n Select a cow to bid on: ";
			cin >> i;
			try {
				if (cin.fail())
					throw invalid_argument("\n Invalid input");
				if (i<1 || i>bids.size())
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
		auto it = bids.begin();
		advance(it, i - 1);
		float bid;
		while (true) {
			cout << "\n Please enter your bid(curent bid is " << it->second << "$): ";
			
			cin >> bid;
			try {
				if (cin.fail())
					throw invalid_argument("\n Invalid input!");
				if (bid <= it->second) {
					throw "\n Bid is too low! You lost!";
				}
				break;
			}
			catch (const char* msg) {
				cout << msg << "\n";
				return nullptr;
			}
			catch (const invalid_argument& e) {
				cout << e.what() << "\n";
				cin.clear();
				cin.ignore(256, '\n');
			}
			catch (...) {
				cout << "\n Unknown error!";
			}
		}
		vector<int> v = { 1, 1, 1};
		srand(static_cast<unsigned int>(time(NULL)));
		int rNumber = rand() % 3;
		if (v[rNumber]) {
			cout << "\n You won the bid!";
			const T* copy = &it->first;
			return copy;
		}
		else {
		
			cout << "\n You lost the bid!";
			return nullptr;
		}

	}

	// Remove bid
	void removeBid(const T& obj) {
		bids.erase(obj);
	}

	// Getter bids
	map<T, float> getBids() {
		return bids;
	}
};
