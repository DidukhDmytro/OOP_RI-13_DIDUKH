#pragma once

class Object
{
private:
    static int count;

public:
    Object();
    Object(const Object&);
    virtual ~Object();

    static int GetCount();
};