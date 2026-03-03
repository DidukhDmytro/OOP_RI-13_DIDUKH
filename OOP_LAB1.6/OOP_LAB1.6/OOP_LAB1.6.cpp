#include<iostream>
#include"RectanglePair.h"


int main() {
	//через конструктори

	Rectangle r1;
	r1.Display();
	std::cout << std::endl;

	Rectangle r2(3, 4);
	r2.Display();
	std::cout << std::endl;

	//з клавіатури
	Rectangle r3;
	r3.Read();
	std::cout << r3.toString() << std::endl;
	std::cout << std::endl;

	//массив
	Rectangle arr[2] = { Rectangle(5,6), Rectangle(7, 8) };

	std::cout << "Massiv of rectangles: " << std::endl;
	for (int i = 0; i < 2; i++)
	{
		arr[i].Display();
		std::cout << std::endl;
	}
	return 0;
}