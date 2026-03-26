#pragma once
#include <iostream>
#include <string>

using namespace std;

class SportGame
{
private:
    string name;
    int playersCount;

protected:
    void setNameDirect(const string& value);
    void setPlayersCountDirect(int value);

public:
    SportGame(const string& n = "Unknown", int p = 1);
    SportGame(const SportGame& other);
    ~SportGame(void);

    SportGame& operator=(const SportGame& other);

    string getName() const;
    int getPlayersCount() const;

    void setName(const string& value);
    void setPlayersCount(int value);

    void Init(const string& n, int p);
    void Read();
    void Display() const;

    operator string() const;

    friend ostream& operator<<(ostream& out, const SportGame& game);
    friend istream& operator>>(istream& in, SportGame& game);
};