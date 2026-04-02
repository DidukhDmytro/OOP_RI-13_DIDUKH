#pragma once
#include "Money.h"

class BankomatPublic : public Money
{
private:
    int id;
    Money balance;
    int minWithdraw;
    int maxWithdraw;

public:
    BankomatPublic();
    BankomatPublic(int id, int sum, int minW, int maxW);

    void Init(int id, int sum, int minW, int maxW);
    void LoadMoney(int sum);
    bool Withdraw(int sum);

    void Display() const;
};

class BankomatPrivate : private Money
{
private:
    int id;
    Money balance;
    int minWithdraw;
    int maxWithdraw;

public:
    BankomatPrivate();
    BankomatPrivate(int id, int sum, int minW, int maxW);

    void Init(int id, int sum, int minW, int maxW);
    void LoadMoney(int sum);
    bool Withdraw(int sum);

    void Display() const;
};