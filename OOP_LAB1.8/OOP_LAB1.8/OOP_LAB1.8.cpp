#include <iostream>
#include "Bankomat.h"

int main() {
    // статичний
    std::cout << "STATIC OBJECT" << std::endl;

    Bankomat::Money mStart;
    mStart.Init(10, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

    Bankomat atmOffice;
    atmOffice.Init("OFFICE-01", mStart, 100, 3000);
    atmOffice.Display();

    if (atmOffice.Withdraw(1500)) {
        std::cout << "Successfully withdrew 1500 UAH. Remaining balance: "
            << atmOffice.toString() << std::endl;
    }

    // динамічний
    std::cout << "\nDYNAMIC OBJECT" << std::endl;
    Bankomat* atmMall = new Bankomat();
    atmMall->Init("MALL-X", mStart, 50, 5000);
    atmMall->Display();
    delete atmMall;

    // масив
    std::cout << "\nARRAY OF OBJECTS" << std::endl;
    const int SIZE = 2;
    Bankomat network[SIZE];

    for (int i = 0; i < SIZE; i++) {
        std::cout << "\nConfiguring ATM #" << (i + 1) << " in the array:" << std::endl;
        network[i].Read();
    }

    std::cout << std::endl;
    for (int i = 0; i < SIZE; i++) {
        network[i].Display();
    }

    // зняття грош з масиву
    std::cout << "\nARRAY WITHDRAWAL" << std::endl;
    int idx;
    double val;

    std::cout << "Choose ATM index (0 to " << SIZE - 1 << "): ";
    std::cin >> idx;

    if (idx >= 0 && idx < SIZE) {
        std::cout << "Enter amount to withdraw from " << network[idx].getId() << ": ";
        std::cin >> val;

        if (network[idx].Withdraw(val)) {
            std::cout << "Success! New ATM status:" << std::endl;
            network[idx].Display();
        }
    }
    else {
        std::cout << "Invalid index." << std::endl;
    }

    return 0;
}