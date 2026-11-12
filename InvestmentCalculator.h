#ifndef INVESTMENT_CALCULATOR_H
#define INVESTMENT_CALCULATOR_H

class InvestmentCalculator {
private:
    double initialPrincipal;
    double monthlyContribution;
    double annualInterestRate;
    int years;

public:
    InvestmentCalculator(double initial, double monthly, double rate, int timeYears);
    double calculateFutureValue() const;
    double calculateTotalContributions() const;
    double calculateTotalInterestEarned() const;
    void displayReport() const;
};

#endif