#pragma once
#include <iostream>
using namespace std;

class MyException : public exception {
public:
	const char* what() const noexcept override {
		return "\n Please read a valid number!";
	}
};