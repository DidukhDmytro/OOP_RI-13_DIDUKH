#pragma once
#include<string>

class Address {
private:
	std::string city;
	std::string street;
	std::string houseNumber;
	int postIndex;

public:
	std::string getCity() const {
		return city;
	}
	std::string getStreet() const {
		return street;
	}
	std::string getHouseNumber() const {
		return houseNumber;
	}
	int getPostIndex() const {
		return postIndex;
	}

	void setCity(std::string value);
	void setStreet(std::string value);
	void setHouseNumber(std::string value);
	void setPostIndex(int value);

	bool Init(std::string city, std::string street, std::string house, int index);
	void Read();
	void Display() const;
	std::string toString() const;
};