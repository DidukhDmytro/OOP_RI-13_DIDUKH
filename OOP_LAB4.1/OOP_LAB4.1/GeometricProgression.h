#pragma once
#include "Progression.h"

class GeometricProgression : public Progression {
public:
    GeometricProgression(double a, double r);

    double sum(int n) override;
    void showType() override;
};