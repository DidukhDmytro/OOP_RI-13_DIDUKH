#pragma once
#include "SportGame.h"

class Football : public SportGame
{
private:
    int matchDuration;

public:
    Football(const string& n = "Football", int p = 11, int d = 90);
    Football(const Football& other);
    ~Football(void);

    Football& operator=(const Football& other);

    int getMatchDuration() const;
    void setMatchDuration(int value);

    void Init(const string& n, int p, int d);
    void Read();
    void Display() const;

    operator string() const;

    friend ostream& operator<<(ostream& out, const Football& game);
    friend istream& operator>>(istream& in, Football& game);
};