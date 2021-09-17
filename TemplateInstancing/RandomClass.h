#pragma once
#include <iostream>

class RandomClass {

public:
	inline virtual void saySomething() {
		std::cout << "random class" << std::endl;
	}
};

class RandomSubclass : public RandomClass
{
public:
	inline virtual void saySomething() {
		std::cout << "random SUBclass" << std::endl;
	}
};