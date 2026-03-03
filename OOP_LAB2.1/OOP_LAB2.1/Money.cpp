#include "Money.h"
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

bool Money::IsValidNominal(int value) const {
    int allowed[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500 };
    for (int i = 0; i < 9; i++)
        if (allowed[i] == value) return true;
    return false;
}

Money::Money() : first(1), second(1) {}
Money::Money(int nominal, int count) { Init(nominal, count); }
Money::Money(const Money& other) : first(other.first), second(other.second) {}

void Money::SetFirst(int value) {
    if (!IsValidNominal(value)) throw invalid_argument("Incorrect nominal!");
    first = value;
}

void Money::SetSecond(int value) {
    if (value < 0) throw invalid_argument("Wrong amount!");
    second = value;
}

void Money::Init(int nominal, int count) {
    SetFirst(nominal);
    SetSecond(count);
}

int Money::summa() const { return first * second; }

Money& Money::operator = (const Money& other) {
    if (this != &other) {
        first = other.first;
        second = other.second;
    }
    return *this;
}

Money::operator string() const {
    stringstream ss;
    ss << "Nominal: " << first << ", Amount: " << second << ", Total: " << summa();
    return ss.str();
}

Money& Money::operator ++ () {
    first++;
    return *this;
}

Money& Money::operator -- () {
    first--;
    return *this;
}

Money Money::operator ++ (int) {
    Money temp(*this);
    second++;
    return temp;
}

Money Money::operator -- (int) {
    Money temp(*this);
    if (second > 0) second--;
    return temp;
}

ostream& operator << (ostream& out, const Money& m) {
    out << (string)m;
    return out;
}

istream& operator >> (istream& in, Money& m) {
    int f, s;
    cout << "Enter nominal: "; in >> f;
    cout << "Enter amount: "; in >> s;
    m.Init(f, s);
    return in;
}

Money makeMoney(int nominal, int count) {
    return Money(nominal, count);
}