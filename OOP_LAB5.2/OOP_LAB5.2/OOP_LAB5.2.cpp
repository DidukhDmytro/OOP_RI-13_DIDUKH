#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <cstdlib>

using namespace std;

class Empty
{
};

class Error
{
private:
    int hours;
    int minutes;
    string message;

public:
    Error(int h, int m, const string& msg)
        : hours(h), minutes(m), message(msg) {
    }

    string What() const
    {
        return message + " (" + to_string(hours) + ":" + to_string(minutes) + ")";
    }

    int GetHours() const { return hours; }
    int GetMinutes() const { return minutes; }
};

class TimeError : public exception
{
private:
    int hours;
    int minutes;
    string message;

public:
    TimeError(int h, int m, const string& msg)
        : hours(h), minutes(m), message(msg) {
    }

    const char* what() const noexcept override
    {
        return message.c_str();
    }

    int GetHours() const { return hours; }
    int GetMinutes() const { return minutes; }
};

bool IsValidTime(int hours, int minutes)
{
    return hours >= 0 && hours <= 23 && minutes >= 0 && minutes <= 59;
}

int ToSeconds1(int hours, int minutes)
{
    if (!IsValidTime(hours, minutes))
        throw 1;

    return hours * 3600 + minutes * 60;
}

int ToSeconds2(int hours, int minutes) throw()
{
    if (!IsValidTime(hours, minutes))
        throw 1.0;

    return hours * 3600 + minutes * 60;
}

int ToSeconds3(int hours, int minutes) throw(invalid_argument)
{
    if (!IsValidTime(hours, minutes))
        throw invalid_argument("invalid time");

    return hours * 3600 + minutes * 60;
}

int ToSeconds4(int hours, int minutes) throw(Empty)
{
    if (!IsValidTime(hours, minutes))
        throw Empty();

    return hours * 3600 + minutes * 60;
}

int ToSeconds5(int hours, int minutes) throw(Error)
{
    if (!IsValidTime(hours, minutes))
        throw Error(hours, minutes, "invalid time");

    return hours * 3600 + minutes * 60;
}

int ToSeconds6(int hours, int minutes) throw(int)
{
    if (!IsValidTime(hours, minutes))
        throw TimeError(hours, minutes, "invalid time");

    return hours * 3600 + minutes * 60;
}

void FU()
{
    cout << "unexpected error! - bad_exception" << endl;
    throw bad_exception();
}

void FT()
{
    cout << "unknown error! - terminate" << endl;
    abort();
}

void Demo1(int h, int m)
{
    try
    {
        cout << "ToSeconds1: " << ToSeconds1(h, m) << endl;
    }
    catch (int)
    {
        cout << "catch (int) <= ToSeconds1()" << endl;
    }
}

void Demo2(int h, int m)
{
    try
    {
        cout << "ToSeconds2: " << ToSeconds2(h, m) << endl;
    }
    catch (double)
    {
        cout << "catch (double) <= ToSeconds2()" << endl;
    }
    catch (bad_exception)
    {
        cout << "catch (bad_exception) <= ToSeconds2()" << endl;
    }
}

void Demo3(int h, int m)
{
    try
    {
        cout << "ToSeconds3: " << ToSeconds3(h, m) << endl;
    }
    catch (invalid_argument e)
    {
        cout << "catch (invalid_argument) <= ToSeconds3():" << endl;
        cout << e.what() << endl;
    }
}

void Demo4(int h, int m)
{
    try
    {
        cout << "ToSeconds4: " << ToSeconds4(h, m) << endl;
    }
    catch (Empty)
    {
        cout << "catch (Empty) <= ToSeconds4()" << endl;
    }
}

void Demo5(int h, int m)
{
    try
    {
        cout << "ToSeconds5: " << ToSeconds5(h, m) << endl;
    }
    catch (Error e)
    {
        cout << "catch (Error) <= ToSeconds5():" << endl;
        cout << e.What() << endl;
    }
}

void Demo6(int h, int m)
{
    try
    {
        cout << "ToSeconds6: " << ToSeconds6(h, m) << endl;
    }
    catch (bad_exception)
    {
        cout << "catch (bad_exception) <= ToSeconds6()" << endl;
    }
    catch (TimeError e)
    {
        cout << "catch (TimeError) <= ToSeconds6():" << endl;
        cout << e.what() << endl;
        cout << "hours = " << e.GetHours() << ", minutes = " << e.GetMinutes() << endl;
    }
}

int main()
{
    set_unexpected(FU);
    set_terminate(FT);

    int h, m;
    cout << "hours = ";
    cin >> h;
    cout << "minutes = ";
    cin >> m;

    cout << endl;
    Demo1(h, m);
    cout << endl;

    Demo2(h, m);
    cout << endl;

    Demo3(h, m);
    cout << endl;

    Demo4(h, m);
    cout << endl;

    Demo5(h, m);
    cout << endl;

    Demo6(h, m);
    cout << endl;

    system("pause");
    return 0;
}