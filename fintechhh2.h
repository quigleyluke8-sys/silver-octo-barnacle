#ifndef FINTECHHH_H
#define FINTECHHH_H
#include <string>
using namespace std;

class User {
private:
    string name;
    double income;
    double savings;
public:
    User();
    void setDetails();
    void displayDetails();
    bool loadProfile();
    void saveProfile() const;
    double getIncome() const;
    double getSavings() const;
    string getName() const;
};

class Budget {
private:
    double income, expenses;
    double housing, utilities, groceries, transport, insurance, debt;
    double entertainment, shopping, other, savingsGoal;
public:
    Budget();
    void setBudget(double monthlyIncome);
    double calculateRemaining();
    void displayReport();
    void giveBudgetAdvice();
    void saveReport();
};

class FinancialAdvisor {
private:
    double income, expenses;
public:
    FinancialAdvisor();
    void giveAdvice(double monthlyIncome);
};

class InvestmentAdvisor {
private:
    double savings;
    int riskLevel, years;
public:
    InvestmentAdvisor();
    void giveAdvice(double savedSavings);
};

class TaxAdvisor {
private:
    double annualIncome, taxAmount;
public:
    TaxAdvisor();
    void calculateTax(double monthlyIncome);
};

class RetirementAdvisor {
private:
    bool ask(string question);
    double calculateGrowth(double savings, double monthly, int years, double rate);
    double calculateInflation(double balance, int years);
public:
    void run(double monthlyIncome, double savedSavings);
};

class InvestmentCalculator {
private:
    double initialPrincipal, monthlyContribution, annualInterestRate;
    int years;
public:
    InvestmentCalculator(double initial, double monthly, double rate, int timeYears);
    double calculateFutureValue() const;
    double calculateTotalContributions() const;
    double calculateTotalInterestEarned() const;
    void displayReport() const;
};
#endif
