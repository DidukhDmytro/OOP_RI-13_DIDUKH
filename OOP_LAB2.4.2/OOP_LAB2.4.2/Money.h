#pragma once
#include <iostream>
#include <string>

class Money
{
private:
    static const int MAX_DIGITS = 100;

    int digits[MAX_DIGITS]; // молодший індекс = молодша цифра
    int size;               // встановлена довжина масиву для об'єкта
    int count;              // фактична кількість значущих цифр

    void normalize();
    void clearUnused();
    bool isValidDigit(int value) const;
    bool isValidSize(int value) const;
    void fromStringInternal(const std::string& str);

public:
    class DigitProxy
    {
    private:
        Money& owner;
        int index;

    public:
        DigitProxy(Money& m, int i);
        DigitProxy& operator=(int value);
        operator int() const;
    };

    Money();
    Money(int newSize);
    Money(const std::string& str, int newSize = MAX_DIGITS);
    Money(const Money& other);

    ~Money() = default;

    Money& operator=(const Money& other);

    int getSize() const;
    int getCount() const;
    int getDigit(int index) const;

    void setSize(int newSize);
    void setDigit(int index, int value);

    int sizeOfMoney() const;

    bool isZero() const;

    DigitProxy operator[](int index);
    int operator[](int index) const;

    Money& operator+=(const Money& other);
    Money& operator-=(const Money& other);

    operator std::string() const;

    friend Money operator+(const Money& left, const Money& right);
    friend Money operator-(const Money& left, const Money& right);

    friend bool operator<(const Money& left, const Money& right);
    friend bool operator>(const Money& left, const Money& right);
    friend bool operator<=(const Money& left, const Money& right);
    friend bool operator>=(const Money& left, const Money& right);
    friend bool operator==(const Money& left, const Money& right);
    friend bool operator!=(const Money& left, const Money& right);

    friend std::istream& operator>>(std::istream& in, Money& value);
    friend std::ostream& operator<<(std::ostream& out, const Money& value);
};