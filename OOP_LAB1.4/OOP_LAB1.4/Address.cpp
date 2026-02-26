#include"Address.h"
#include<iostream>

void Address::setCity(std::string value) {
	if(!value.empty())
	{
		city = value;
	}
}

void Address::setStreet(std::string value) {
	if (!value.empty())
	{
		street = value;
	}
}

void Address::setHouseNumber(std::string value) {
	if (!value.empty())
	{
		houseNumber = value;
	}
}

void Address::setPostIndex(int value) {
	if (value > 0 && value< 100000) // такі межі бо індекс - 5 цифр
	{
		postIndex = value;
	}
	else
	{
		std::cout << "Error. Wrong index" << std::endl;
	}
}

bool Address::Init(std::string c, std::string s, std::string h, int i) {
	setCity(c);
	setStreet(s);
	setHouseNumber(h);
	setPostIndex(i);
	return true;
}

void Address::Read() {
	std::string c, s, h;
	int i;

	std::cout << "Enter city: "; std::cin >> c;
	std::cout << "Enter street: "; std::cin >> s;
	std::cout << "Enter house number: "; std::cin >> h;
	std::cout << "Enter index: "; std::cin >> i;

	if (!Init(c, s, h, i))
	{
		std::cout << "Initialization error!" << std::endl;
	} 
}

void Address::Display() const {
	std::cout << toString() << std::endl;
}

std::string Address::toString() const {
	return "Address: " + city + ", st. " + street + ", house. " + houseNumber + ", index: " + std::to_string(postIndex);
}