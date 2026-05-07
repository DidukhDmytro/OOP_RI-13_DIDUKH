#include "Object.h"

int Object::count = 0;

Object::Object()
{
    ++count;
}

Object::Object(const Object&)
{
    ++count;
}

Object::~Object()
{
    --count;
}

int Object::GetCount()
{
    return count;
}