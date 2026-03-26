#include "Football.h"
#include <sstream>
#include <stdexcept>
#include <cstdlib>

using namespace std;

Football::Football(const string& n, int p, int d) : SportGame(n, p)
{
    setMatchDuration(d);
}

Football::Football(const Football& other) : SportGame(other)
{
    matchDuration = other.matchDuration;
}

Football::~Football(void)
{
}

Football& Football::operator=(const Football& other)
{
    if (this != &other)
    {
        SportGame::operator=(other);
        matchDuration = other.matchDuration;
    }
    return *this;
}

int Football::getMatchDuration() const
{
    return matchDuration;
}

void Football::setMatchDuration(int value)
{
    if (value <= 0)
    {
        throw invalid_argument("Error: match duration must be greater than 0.");
    }
    matchDuration = value;
}

void Football::Init(const string& n, int p, int d)
{
    SportGame::Init(n, p);
    setMatchDuration(d);
}

void Football::Read()
{
    string n;
    int p, d;

    cout << "Game name = ";
    getline(cin >> ws, n);

    cout << "Players count = ";
    cin >> p;

    cout << "Match duration = ";
    cin >> d;

    if (!cin) {
        throw invalid_argument("Error: incorrect input.");
    }

    Init(n, p, d);
}

void Football::Display() const
{
    cout << "Game name: " << getName() << endl;
    cout << "Players count: " << getPlayersCount() << endl;
    cout << "Match duration: " << matchDuration << endl;
}

Football::operator string() const
{
    stringstream ss;
    ss << "Football( name = " << getName()
        << ", playersCount = " << getPlayersCount()
        << ", matchDuration = " << matchDuration << " )";
    return ss.str();
}

ostream& operator<<(ostream& out, const Football& game)
{
    out << (string)game;
    return out;
}

istream& operator>>(istream& in, Football& game)
{
    string n;
    int p, d;

    cout << "Game name = ";
    getline(in >> ws, n);

    cout << "Players count = ";
    in >> p;

    cout << "Match duration = ";
    in >> d;

    if (!in) {
        throw invalid_argument("");
    }

    game.Init(n, p, d);
    return in;
}