#ifndef MONEY_H
#define MONEY_H

#include <string>

class Money {
private:
    // купюри
    int n500, n200, n100, n50, n20, n10, n5, n2, n1;
    // монетки
    int m50, m25, m10, m5, m2, m1;

public:
    void setN500(int v) { if (v >= 0) n500 = v; }
    void setN200(int v) { if (v >= 0) n200 = v; }
    void setN100(int v) { if (v >= 0) n100 = v; }
    void setN50(int v) { if (v >= 0) n50 = v; }
    void setN20(int v) { if (v >= 0) n20 = v; }
    void setN10(int v) { if (v >= 0) n10 = v; }
    void setN5(int v) { if (v >= 0) n5 = v; }
    void setN2(int v) { if (v >= 0) n2 = v; }
    void setN1(int v) { if (v >= 0) n1 = v; }

    void setM50(int v) { if (v >= 0) m50 = v; }
    void setM25(int v) { if (v >= 0) m25 = v; }
    void setM10(int v) { if (v >= 0) m10 = v; }
    void setM5(int v) { if (v >= 0) m5 = v; }
    void setM2(int v) { if (v >= 0) m2 = v; }
    void setM1(int v) { if (v >= 0) m1 = v; }

    int getN500() const { return n500; }
    int getN200() const { return n200; }
    int getN100() const { return n100; }
    int getN50() const { return n50; }
    int getN20() const { return n20; }
    int getN10() const { return n10; }
    int getN5() const { return n5; }
    int getN2() const { return n2; }
    int getN1() const { return n1; }

    int getM50() const { return m50; }
    int getM25() const { return m25; }
    int getM10() const { return m10; }
    int getM5() const { return m5; }
    int getM2() const { return m2; }
    int getM1() const { return m1; }

    bool Init(int v500, int v200, int v100, int v50, int v20, int v10, int v5, int v2, int v1,
        int c50, int c25, int c10, int c5, int c2, int c1);
    void Read();
    void Display() const;
    std::string toString() const;

    long long toKopecks() const;
    void fromKopecks(long long totalKopecks);

    Money Add(const Money& other) const;
    Money Sub(const Money& other) const;
    Money Multiply(double factor) const;
    Money Divide(double factor) const;
    double DivideByMoney(const Money& other) const;
    int Compare(const Money& other) const;
};

#endif