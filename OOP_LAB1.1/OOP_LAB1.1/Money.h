#pragma once
#include <iostream>

class Money
{
private:
    int first;   // номінал
    int second;  // кількість

    bool IsValidNominal(int value) const;

public:
    // Конструктори
    Money();
    Money(int nominal, int count);

    // Методи доступу (get)
    int GetFirst() const;
    int GetSecond() const;

    // Методи запису (set)
    void SetFirst(int value);
    void SetSecond(int value);

    // Ініціалізація
    void Init(int nominal, int count);

    // Ввід / Вивід
    void Read();
    void Display() const;

    // Обчислення суми
    int summa() const;
};

Money makeMoney(int nominal, int count);
