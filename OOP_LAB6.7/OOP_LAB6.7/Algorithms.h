#pragma once

template<class T>
class Predicate
{
public:
    virtual bool operator()(T x) = 0;
};

template<class T>
class Zero : public Predicate<T>
{
public:
    bool operator()(T x) override
    {
        T zero = T();
        return x == zero;
    }
};

template<class T>
class Positive : public Predicate<T>
{
public:
    bool operator()(T x) override
    {
        return x > 0;
    }
};

template<class T>
class Negative : public Predicate<T>
{
public:
    bool operator()(T x) override
    {
        return x < 0;
    }
};

template<class T>
int erase(T* begin, T* end, T* to, T value)
{
    int n = 0;

    for (T* from = begin; from < end; from++)
    {
        if (*from != value)
        {
            *to = *from;
            to++;
            n++;
        }
    }

    return n;
}

template<class T>
int erase_if(T* begin, T* end, T* to, Predicate<T>& p)
{
    int n = 0;

    for (T* from = begin; from < end; from++)
    {
        if (!p(*from))
        {
            *to = *from;
            to++;
            n++;
        }
    }

    return n;
} 