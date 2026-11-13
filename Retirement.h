
#ifndef Retirement_H
#define Retirement_H

#include <cmath>
using namespace std;

// Class for calculating retirement savings
class Retirement
{
private:
    double savings;
    double monthly;
    int years;
    double rate;

public:
    // Constructor
    Retirement(double s, double m, int y, double r)
    {
        savings = s;
        monthly = m;
        years = y;
        rate = r;
    }

    // Calculate savings using compound interest
    double calculateGrowth()
    {
        double r = rate / 12;
        int n = years * 12;

        if (r == 0)
            return savings + monthly * n;

        double total = savings * pow(1 + r, n)
                     + monthly * (pow(1 + r, n) - 1) / r;

        return total;
    }

    // Calculate inflation-adjusted savings
    double calculateInflation(double balance)
    {
        double inflation = 0.02;

        double adjusted = balance / pow(1 + inflation, years);

        return adjusted;
    }
};

// Class for pension contributions
class Pension
{
private:
    double income;
    double employerPercent;
    double monthlySavings;

public:
    // Constructor
    Pension(double i, double e, double m)
    {
        income = i;
        employerPercent = e;
        monthlySavings = m;
    }

    // Calculate monthly employer contribution
    double employerContribution()
    {
        return income * employerPercent / 100 / 12;
    }

    // Calculate illustrative government contribution
    double governmentContribution()
    {
        return monthlySavings / 3;
    }
};

#endif
