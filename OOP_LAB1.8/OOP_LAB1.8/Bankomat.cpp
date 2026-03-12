#include "Bankomat.h"
#include <iostream>
#include <cmath>
#include <string>

Bankomat::Money::Money() {
    n500 = n200 = n100 = n50 = n20 = n10 = n5 = n2 = n1 = 0;
    m50 = m25 = m10 = m5 = m2 = m1 = 0;
}

bool Bankomat::Money::Init(int v500, int v200, int v100, int v50, int v20, int v10, int v5, int v2, int v1,
    int c50, int c25, int c10, int c5, int c2, int c1) {
    if (v500 < 0 || v200 < 0 || v100 < 0 || v50 < 0 || v20 < 0 || v10 < 0 || v5 < 0 || v2 < 0 || v1 < 0 ||
        c50 < 0 || c25 < 0 || c10 < 0 || c5 < 0 || c2 < 0 || c1 < 0) {
        return false;
    }

    n500 = v500; n200 = v200; n100 = v100; n50 = v50; n20 = v20;
    n10 = v10; n5 = v5; n2 = v2; n1 = v1;
    m50 = c50; m25 = c25; m10 = c10; m5 = c5; m2 = c2; m1 = c1;

    return true;
}

void Bankomat::Money::Read() {
    int v[15];

    std::cout << "Enter count of bills (500, 200, 100, 50, 20, 10, 5, 2, 1):" << std::endl;
    for (int i = 0; i < 9; i++) {
        std::cin >> v[i];
    }

    std::cout << "Enter count of coins (50, 25, 10, 5, 2, 1):" << std::endl;
    for (int i = 9; i < 15; i++) {
        std::cin >> v[i];
    }

    if (!Init(v[0], v[1], v[2], v[3], v[4], v[5], v[6], v[7], v[8],
        v[9], v[10], v[11], v[12], v[13], v[14])) {
        std::cout << "[Error] Negative values detected. Resetting to zero." << std::endl;
        Init(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    }
}

long long Bankomat::Money::toKopecks() const {
    return n500 * 50000LL + n200 * 20000LL + n100 * 10000LL + n50 * 5000LL +
        n20 * 2000LL + n10 * 1000LL + n5 * 500LL + n2 * 200LL + n1 * 100LL +
        m50 * 50LL + m25 * 25LL + m10 * 10LL + m5 * 5LL + m2 * 2LL + m1;
}

void Bankomat::Money::fromKopecks(long long t) {
    if (t < 0) t = 0;

    n500 = t / 50000; t %= 50000;
    n200 = t / 20000; t %= 20000;
    n100 = t / 10000; t %= 10000;
    n50 = t / 5000;  t %= 5000;
    n20 = t / 2000;  t %= 2000;
    n10 = t / 1000;  t %= 1000;
    n5 = t / 500;   t %= 500;
    n2 = t / 200;   t %= 200;
    n1 = t / 100;   t %= 100;
    m50 = t / 50;    t %= 50;
    m25 = t / 25;    t %= 25;
    m10 = t / 10;    t %= 10;
    m5 = t / 5;     t %= 5;
    m2 = t / 2;     t %= 2;
    m1 = t;
}

std::string Bankomat::Money::toString() const {
    long long total = toKopecks();
    long long hryvnias = total / 100;
    int kopecks = static_cast<int>(total % 100);

    return std::to_string(hryvnias) + "," + (kopecks < 10 ? "0" : "") + std::to_string(kopecks);
}

void Bankomat::Money::Display() const {
    std::cout << toString() << " UAH";
}

Bankomat::Money Bankomat::Money::Add(const Money& other) const {
    Money res;
    res.fromKopecks(this->toKopecks() + other.toKopecks());
    return res;
}

Bankomat::Money Bankomat::Money::Sub(const Money& other) const {
    Money res;
    long long diff = this->toKopecks() - other.toKopecks();
    res.fromKopecks(diff > 0 ? diff : 0);
    return res;
}

Bankomat::Money Bankomat::Money::Multiply(double factor) const {
    Money res;
    res.fromKopecks(static_cast<long long>(std::round(this->toKopecks() * factor)));
    return res;
}

Bankomat::Money Bankomat::Money::Divide(double factor) const {
    Money res;
    if (factor != 0) {
        res.fromKopecks(static_cast<long long>(std::round(this->toKopecks() / factor)));
    }
    return res;
}

double Bankomat::Money::DivideByMoney(const Money& other) const {
    if (other.toKopecks() == 0) return 0.0;
    return static_cast<double>(this->toKopecks()) / other.toKopecks();
}

int Bankomat::Money::Compare(const Money& other) const {
    long long a = this->toKopecks();
    long long b = other.toKopecks();

    if (a > b) return 1;
    if (a < b) return -1;
    return 0;
}


Bankomat::Bankomat() {
    id = "";
    minWithdraw = 0;
    maxWithdraw = 0;
}

bool Bankomat::Init(std::string id_val, Money bal, double min, double max) {
    if (id_val.empty() || min < 0 || max < min) {
        return false;
    }

    id = id_val;
    balance = bal;
    minWithdraw = min;
    maxWithdraw = max;

    return true;
}

void Bankomat::Read() {
    std::string in_id;
    double in_min, in_max;

    std::cout << "Enter ATM ID: ";
    std::cin >> in_id;

    std::cout << "--- Enter ATM Cash Stock ---" << std::endl;
    balance.Read();

    std::cout << "Enter Min Withdrawal Limit: ";
    std::cin >> in_min;

    std::cout << "Enter Max Withdrawal Limit: ";
    std::cin >> in_max;

    if (!Init(in_id, balance, in_min, in_max)) {
        std::cout << "[Warning] Invalid data. Using defaults (ID = ATM-DEFAULT, limits 0 - 10000)." << std::endl;
        Init("ATM-DEFAULT", balance, 0, 10000);
    }
}

void Bankomat::Display() const {
    std::cout << "\n===============================" << std::endl;
    std::cout << "ATM ID      : " << id << std::endl;
    std::cout << "Min Limit   : " << minWithdraw << std::endl;
    std::cout << "Max Limit   : " << maxWithdraw << std::endl;
    std::cout << "Cash Inside : ";
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
    toSub.fromKopecks(static_cast<long long>(std::round(amount * 100)));

    if (balance.Compare(toSub) >= 0) {
        balance = balance.Sub(toSub);
        return true;
    }

    std::cout << "[Declined] ATM has insufficient funds." << std::endl;
    return false;
}