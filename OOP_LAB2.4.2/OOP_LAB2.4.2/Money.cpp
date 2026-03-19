#include "Money.h"
#include <stdexcept>
#include <cctype>

using namespace std;

Money::DigitProxy::DigitProxy(Money& m, int i) : owner(m), index(i) {}

Money::DigitProxy& Money::DigitProxy::operator=(int value) {
    owner.setDigit(index, value);
    return *this;
}

Money::DigitProxy::operator int() const {
    return owner.getDigit(index);
}

Money::Money() {
    size = 3;   // мінімум 1 цифра гривень + 2 цифри копійок
    count = 3;
    for (int i = 0; i < MAX_DIGITS; i++)
        digits[i] = 0;
}

Money::Money(int newSize) {
    for (int i = 0; i < MAX_DIGITS; i++)
        digits[i] = 0;

    if (!isValidSize(newSize))
        size = 3;
    else
        size = newSize;

    count = 3;
}

Money::Money(const string& str, int newSize) {
    for (int i = 0; i < MAX_DIGITS; i++)
        digits[i] = 0;

    if (!isValidSize(newSize))
        size = MAX_DIGITS;
    else
        size = newSize;

    count = 3;
    fromStringInternal(str);
}

Money::Money(const Money& other) {
    size = other.size;
    count = other.count;
    for (int i = 0; i < MAX_DIGITS; i++)
        digits[i] = other.digits[i];
}

Money& Money::operator=(const Money& other) {
    if (this != &other)
    {
        size = other.size;
        count = other.count;
        for (int i = 0; i < MAX_DIGITS; i++)
            digits[i] = other.digits[i];
    }
    return *this;
}

int Money::getSize() const {
    return size;
}

int Money::getCount() const {
    return count;
}

int Money::getDigit(int index) const {
    if (index < 0 || index >= size)
        throw out_of_range("Index out of range");
    return digits[index];
}

void Money::setSize(int newSize) {
    if (!isValidSize(newSize))
        throw invalid_argument("Invalid size");

    if (newSize < count)
    {
        for (int i = newSize; i < MAX_DIGITS; i++)
            digits[i] = 0;
        size = newSize;
        normalize();
    }
    else
    {
        size = newSize;
    }
}

void Money::setDigit(int index, int value) {
    if (index < 0 || index >= size)
        throw out_of_range("Index out of range");
    if (!isValidDigit(value))
        throw invalid_argument("Digit must be in range 0..9");

    digits[index] = value;
    normalize();
}

int Money::sizeOfMoney() const {
    return size;
}

bool Money::isZero() const {
    for (int i = 0; i < size; i++)
    {
        if (digits[i] != 0)
            return false;
    }
    return true;
}

Money::DigitProxy Money::operator[](int index) {
    if (index < 0 || index >= size)
        throw out_of_range("Index out of range");
    return DigitProxy(*this, index);
}

int Money::operator[](int index) const {
    return getDigit(index);
}

Money& Money::operator+=(const Money& other) {
    *this = *this + other;
    return *this;
}

Money& Money::operator-=(const Money& other) {
    *this = *this - other;
    return *this;
}

Money::operator string() const {
    string result;

    int highest = count - 1;
    if (highest < 2)
        highest = 2;

    for (int i = highest; i >= 2; i--)
        result += char('0' + digits[i]);

    if (result.empty())
        result = "0";

    result += '.';
    result += char('0' + digits[1]);
    result += char('0' + digits[0]);

    return result;
}

Money operator+(const Money& left, const Money& right) {
    int resultSize = (left.size > right.size) ? left.size : right.size;
    Money result(resultSize);

    int carry = 0;
    for (int i = 0; i < resultSize; i++)
    {
        int a = (i < left.size) ? left.digits[i] : 0;
        int b = (i < right.size) ? right.digits[i] : 0;

        int sum = a + b + carry;
        result.digits[i] = sum % 10;
        carry = sum / 10;
    }

    if (carry != 0)
    {
        if (resultSize >= Money::MAX_DIGITS)
            throw overflow_error("Overflow: too many digits in result");
        if (resultSize >= result.size)
            throw overflow_error("Overflow inside object size");

        result.digits[resultSize] = carry;
        result.count = resultSize + 1;
    }
    else
    {
        result.normalize();
    }

    return result;
}

Money operator-(const Money& left, const Money& right) {
    if (left < right)
        throw invalid_argument("Result would be negative");

    Money result(left.size);
    int borrow = 0;

    for (int i = 0; i < left.size; i++)
    {
        int a = left.digits[i];
        int b = (i < right.size) ? right.digits[i] : 0;

        int diff = a - b - borrow;
        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        result.digits[i] = diff;
    }

    result.normalize();
    return result;
}

bool operator<(const Money& left, const Money& right) {
    int maxSize = (left.size > right.size) ? left.size : right.size;

    for (int i = maxSize - 1; i >= 0; i--)
    {
        int a = (i < left.size) ? left.digits[i] : 0;
        int b = (i < right.size) ? right.digits[i] : 0;

        if (a < b) return true;
        if (a > b) return false;
    }

    return false;
}

bool operator>(const Money& left, const Money& right) {
    return right < left;
}

bool operator<=(const Money& left, const Money& right) {
    return !(left > right);
}

bool operator>=(const Money& left, const Money& right) {
    return !(left < right);
}

bool operator==(const Money& left, const Money& right) {
    int maxSize = (left.size > right.size) ? left.size : right.size;

    for (int i = 0; i < maxSize; i++)
    {
        int a = (i < left.size) ? left.digits[i] : 0;
        int b = (i < right.size) ? right.digits[i] : 0;

        if (a != b)
            return false;
    }

    return true;
}

bool operator!=(const Money& left, const Money& right) {
    return !(left == right);
}

istream& operator>>(istream& in, Money& value) {
    string str;
    in >> str;
    value.fromStringInternal(str);
    return in;
}

ostream& operator<<(ostream& out, const Money& value) {
    out << static_cast<string>(value);
    return out;
}

void Money::normalize() {
    int lastNonZero = -1;

    for (int i = size - 1; i >= 0; i--)
    {
        if (digits[i] != 0)
        {
            lastNonZero = i;
            break;
        }
    }

    if (lastNonZero < 2)
        count = 3;
    else
        count = lastNonZero + 1;

    clearUnused();
}

void Money::clearUnused() {
    for (int i = size; i < MAX_DIGITS; i++)
        digits[i] = 0;
}

bool Money::isValidDigit(int value) const {
    return value >= 0 && value <= 9;
}

bool Money::isValidSize(int value) const {
    return value >= 3 && value <= MAX_DIGITS;
}

void Money::fromStringInternal(const string& str) {
    for (int i = 0; i < MAX_DIGITS; i++)
        digits[i] = 0;

    string clean;
    bool dotFound = false;
    int dotPos = -1;

    for (int i = 0; i < (int)str.length(); i++)
    {
        if (isdigit((unsigned char)str[i]))
        {
            clean += str[i];
        }
        else if ((str[i] == '.' || str[i] == ',') && !dotFound)
        {
            dotFound = true;
            dotPos = (int)clean.length();
        }
        else
        {
            throw invalid_argument("Invalid money format");
        }
    }

    if (!dotFound)
    {
        clean += "00";
        dotPos = (int)clean.length() - 2;
    }
    else
    {
        int digitsAfterDot = (int)clean.length() - dotPos;
        if (digitsAfterDot == 0)
            clean += "00";
        else if (digitsAfterDot == 1)
            clean += "0";
        else if (digitsAfterDot > 2)
            throw invalid_argument("Too many digits after decimal point");
    }

    if ((int)clean.length() > size)
        throw invalid_argument("Number does not fit into object size");

    int index = 0;
    for (int i = (int)clean.length() - 1; i >= 0; i--)
    {
        digits[index++] = clean[i] - '0';
    }

    normalize();
}