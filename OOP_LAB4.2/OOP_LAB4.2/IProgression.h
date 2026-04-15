#pragma once

class IProgression {
public:
    virtual double sum(int n) = 0;
    virtual void showType() = 0;

    virtual ~IProgression() {}
};