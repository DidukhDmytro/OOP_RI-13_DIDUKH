#include "Football.h"

using namespace std;

SportGame MakeSportGame(SportGame game)
{
    return game;
}

void ShowSportGame(SportGame game)
{
    cout << game << endl;
}

int main()
{
    SportGame a, b("Basketball", 5), c;
    Football x("Football", 11, 90), y, z(x);

    cout << "Objects of class SportGame:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    cout << endl << "Objects of class Football:" << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;

    cout << endl << "Input SportGame a:" << endl;
    cin >> a;
    cout << "a = " << a << endl;

    cout << endl << "Input Football y:" << endl;
    cin >> y;
    cout << "y = " << y << endl;

    cout << endl << "Copy constructor:" << endl;
    Football k(y);
    cout << "k = " << k << endl;

    cout << endl << "Assignment operator:" << endl;
    c = b;
    cout << "c = " << c << endl;
    z = y;
    cout << "z = " << z << endl;

    cout << endl << "Function that gets and returns object of base class:" << endl;
    SportGame d = MakeSportGame(b);
    cout << "d = " << d << endl;

    cout << endl << "Substitution principle:" << endl;
    ShowSportGame(b);
    ShowSportGame(x);

    cout << endl << "Array of SportGame objects:" << endl;
    SportGame arr1[3] = {
        SportGame("Volleyball", 6),
        SportGame("Tennis", 2),
        SportGame("Hockey", 6)
    };

    for (int i = 0; i < 3; i++)
        cout << "arr1[" << i << "] = " << arr1[i] << endl;

    cout << endl << "Array of Football objects:" << endl;
    Football arr2[3] = {
        Football("Football", 11, 90),
        Football("MiniFootball", 5, 40),
        Football("YouthFootball", 11, 80)
    };

    for (int i = 0; i < 3; i++)
        cout << "arr2[" << i << "] = " << arr2[i] << endl;

    return 0;
}