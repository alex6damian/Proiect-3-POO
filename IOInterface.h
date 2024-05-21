#pragma once
#include <iostream>
using namespace std;

class IOInterface {
public:
	virtual istream& read(istream&) = 0;
	virtual ostream& print(ostream&) const = 0;
	virtual ~IOInterface()=default;
};