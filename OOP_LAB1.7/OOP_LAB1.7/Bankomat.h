#ifndef BANKOMAT_H
#define BANKOMAT_H

#include "Money.h"
#include <string>

class Bankomat {
private:
    std::string id;
    Money balance;
    double minWithdraw;
    double maxWithdraw;

public:
    void setId(std::string v) {
        if (!v.empty()) id = v;
    }

    void setBalance(Money v) {
        balance = v;
    }

    void setMinWithdraw(double v) {
        if (v >= 0) minWithdraw = v;
    }

    void setMaxWithdraw(double v) {
        if (v >= minWithdraw) maxWithdraw = v;
    }

    std::string getId() const { return id; }
    Money getBalance() const { return balance; }
    double getMinWithdraw() const { return minWithdraw; }
    double getMaxWithdraw() const { return maxWithdraw; }

    bool Init(std::string id_val, Money bal, double min, double max);
    void Read();
    void Display() const;
    std::string toString() const;

    void LoadCash(const Money& cash);
    bool Withdraw(double amount);
};

#endif