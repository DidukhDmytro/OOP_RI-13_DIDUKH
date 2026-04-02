#include "Bankomat.h"
#include <iostream>

BankomatPublic::BankomatPublic() : id(0), balance(0), minWithdraw(0), maxWithdraw(0) {}

BankomatPublic::BankomatPublic(int id, int sum, int minW, int maxW)
{
    Init(id, sum, minW, maxW);
}

void BankomatPublic::Init(int id, int sum, int minW, int maxW)
{
    this->id = id;
    balance.Init(sum);
    minWithdraw = minW;
    maxWithdraw = maxW;
}

void BankomatPublic::LoadMoney(int sum)
{
    balance = balance + Money(sum);
}

bool BankomatPublic::Withdraw(int sum)
{
    if (sum < minWithdraw || sum > maxWithdraw)
        return false;

    Money temp(sum);

    if (balance < temp)
        return false;

    balance = balance - temp;
    return true;
}

void BankomatPublic::Display() const
{
    std::cout << "ATM " << id << " Balance: " << balance << std::endl;
}


BankomatPrivate::BankomatPrivate() : id(0), balance(0), minWithdraw(0), maxWithdraw(0) {}

BankomatPrivate::BankomatPrivate(int id, int sum, int minW, int maxW)
{
    Init(id, sum, minW, maxW);
}

void BankomatPrivate::Init(int id, int sum, int minW, int maxW)
{
    this->id = id;
    balance.Init(sum);
    minWithdraw = minW;
    maxWithdraw = maxW;
}

void BankomatPrivate::LoadMoney(int sum)
{
    balance = balance + Money(sum);
}

bool BankomatPrivate::Withdraw(int sum)
{
    if (sum < minWithdraw || sum > maxWithdraw)
        return false;

    Money temp(sum);

    if (balance < temp)
        return false;

    balance = balance - temp;
    return true;
}

void BankomatPrivate::Display() const
{
    std::cout << "ATM " << id << " Balance: " << balance << std::endl;
}