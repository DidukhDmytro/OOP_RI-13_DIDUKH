#pragma once
#include <iostream>
#include <string>

class Money {
private:
    int first;   // номінал
    int second;  // кількість
    bool IsValidNominal(int value) const;

public:
    Money();
    Money(int nominal, int count);
    Money(const Money& other);

    int GetFirst() const { return first; }
    int GetSecond() const { return second; }
    void SetFirst(int value);
    void SetSecond(int value);

    void Init(int nominal, int count);
    int summa() const;

    Money& operator = (const Money& other);
    operator std::string() const; // приведення до рядка

    Money& operator ++ ();    // префіксний змінює first
    Money& operator -- ();    // префіксний змінює first
    Money operator ++ (int);  // постфіксний змінює second
    Money operator -- (int);  // постфіксний змінює second

    friend std::ostream& operator << (std::ostream& out, const Money& m);
    friend std::istream& operator >> (std::istream& in, Money& m);
};

Money makeMoney(int nominal, int count);