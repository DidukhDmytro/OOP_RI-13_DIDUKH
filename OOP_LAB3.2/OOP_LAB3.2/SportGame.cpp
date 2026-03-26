#include "SportGame.h"
#include <sstream>
#include <stdexcept>
#include <cstdlib>

using namespace std;

void SportGame::setNameDirect(const string& value) {
    name = value;
}

void SportGame::setPlayersCountDirect(int value) {
    playersCount = value;
}

SportGame::SportGame(const string& n, int p) {
    Init(n, p);
}

SportGame::SportGame(const SportGame& other) {
    setNameDirect(other.name);
    setPlayersCountDirect(other.playersCount);
}

SportGame::~SportGame(void){}

SportGame& SportGame::operator=(const SportGame& other) {
    if (this != &other) {
        setNameDirect(other.name);
        setPlayersCountDirect(other.playersCount);
    }
    return *this;
}

string SportGame::getName() const {
    return name;
}

int SportGame::getPlayersCount() const {
    return playersCount;
}

void SportGame::setName(const string& value) {
    if (value.empty()){
        throw invalid_argument("Error: game name cannot be empty.");
    }
    setNameDirect(value);
}

void SportGame::setPlayersCount(int value) {
    if (value <= 0){
        throw invalid_argument("Error: players count must be greater than 0.");
    }
    setPlayersCountDirect(value);
}

void SportGame::Init(const string& n, int p) {
    setName(n);
    setPlayersCount(p);
}

void SportGame::Read() {
    string n;
    int p;

    cout << "Game name = ";
    getline(cin >> ws, n);

    cout << "Players count = ";
    cin >> p;

    if (!cin){
        throw invalid_argument("Error: incorrect input.");
    }

    Init(n, p);
}

void SportGame::Display() const {
    cout << "Game name: " << name << endl;
    cout << "Players count: " << playersCount << endl;
}

SportGame::operator string() const {
    stringstream ss;
    ss << "SportGame( name = " << name
        << ", playersCount = " << playersCount << " )";
    return ss.str();
}

ostream& operator<<(ostream& out, const SportGame& game) {
    out << (string)game;
    return out;
}

istream& operator>>(istream& in, SportGame& game) {
    string n;
    int p;

    cout << "Game name = ";
    getline(in >> ws, n);

    cout << "Players count = ";
    in >> p;

    if (!in)    {
        throw invalid_argument("");
    }

    game.Init(n, p);
    return in;
}