#include"Address.h"
#include<iostream>

void showMenu() {
    std::cout << "\n--- MENU ---\n";
    std::cout << "1. Enter new address (Read)\n";
    std::cout << "2. Show address (Display)\n";
    std::cout << "3. Change city (SetCity)\n";
    std::cout << "4. Show with toString\n";
    std::cout << "0. Exit\n";
    std::cout << "Your choice: ";
}

int main() {
    Address adr1;
    adr1.Init("Lviv", "Zelena", "20", 02010); // одинокий об'єкт

    Address offices[2];
    offices[0].Init("Kyiv", "Shevchenka", "11", 80241);
    offices[1].Init("Odessa", "Vokzalna", "124", 1111); // масиі об'єктів

    std::cout << "Demonstating massif of objects:" << std::endl;
    for (int i = 0; i < 2; i++)
    {
        offices[i].Display();
    }

    int choice;
    Address userAddr;
    do
    {
        showMenu();
        std::cin >> choice;
        
        switch (choice) {
         case 1:
         {
             userAddr.Read();
             break;
         }
        case 2:
        {
            userAddr.Display();
            break;
        }
        case 3:
        {
            std::string newCity;
            std::cout << "Enter new city:"; std::cin >> newCity;
            userAddr.setCity(newCity);
            break;
        }
        case 4:
        {
            std::cout << "Line: " << userAddr.toString() << std::endl;
            break;
        }
        }
    } while (choice != 0);
    return 0;
}