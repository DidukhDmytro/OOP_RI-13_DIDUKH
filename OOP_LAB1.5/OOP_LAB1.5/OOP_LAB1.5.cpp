#include<iostream>
#include"Rectangle.h"

int main() {
	Rectangle r1;
	r1.Init(5, 10);
	std::cout << "Object 1(static): " << std::endl;
	r1.Display();
	std::cout << "Area: " << r1.Area() << " Perimetr: " << r1.Perimetr() << std::endl; // з вказаними поч значеннями


	Rectangle r2;
	std::cout << "Enter characteristics for object 2: " << std::endl;
	r2.Read();
	r2.Display();
	std::cout << "Area: " << r2.Area() << " Perimetr: " << r2.Perimetr() << std::endl; //через read

	const int SIZE = 2;
	Rectangle arr[SIZE];
	std::cout << "Filling an array of " << SIZE << " rectangles:" << std::endl;			//мвсив
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << "Element of massiv #" << i + 1 << ":" << std::endl;
		arr[i].Read();
	}

	std::cout << "Massif:" << std::endl;
	for (int i = 0; i < SIZE; i++) {
		std::cout << arr[i].toString() << " | S = " << arr[i].Area() << " P = " << arr[i].Perimetr() << std::endl;
	}

	return 0;
}