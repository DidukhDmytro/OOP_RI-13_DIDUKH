#include "Bankomat.h"
#include <iostream>

bool Bankomat::Init(std::string id_v, Money bal, double min, double max) {
    if (min < 0 || max < min) {
        return false;
    }

    id = id_v;
    balance = bal;
    minWithdraw = min;
    maxWithdraw = max;

    return true;
}

void Bankomat::Read() {
    std::string in_id;
    double in_min, in_max;

    std::cout << "Enter ATM ID (string): ";
    std::cin >> in_id;

    std::cout << "--- Enter ATM Cash Stock ---" << std::endl;
    balance.Read();

    std::cout << "Enter Min Withdrawal Limit: ";
    std::cin >> in_min;

    std::cout << "Enter Max Withdrawal Limit: ";
    std::cin >> in_max;

    if (!Init(in_id, balance, in_min, in_max)) {
        std::cout << "[Warning] Invalid limits. Using defaults (0 - 10000)." << std::endl;
        Init(in_id, balance, 0, 10000);
    }
}

void Bankomat::Display() const {
    std::cout << "\n===============================" << std::endl;
    std::cout << " ATM ID      : " << id << std::endl;
    std::cout << " Min Limit   : " << minWithdraw << std::endl;
    std::cout << " Max Limit   : " << maxWithdraw << std::endl;
    std::cout << " Cash Inside : ";
    balance.Display();
    std::cout << "\n===============================" << std::endl;
}

std::string Bankomat::toString() const {
    return balance.toString();
}

void Bankomat::LoadCash(const Money& cash) {
    balance = balance.Add(cash);
}

bool Bankomat::Withdraw(double amount) {
    if (amount < minWithdraw || amount > maxWithdraw) {
        std::cout << "[Declined] Amount " << amount << " is out of limits." << std::endl;
        return false;
    }

    Money toSub;
    toSub.fromKopecks(static_cast<long long>(amount * 100));

    if (balance.Compare(toSub) >= 0) {
        balance = balance.Sub(toSub);
        return true;
    }

    std::cout << "[Declined] ATM has insufficient funds." << std::endl;
    return false;
}