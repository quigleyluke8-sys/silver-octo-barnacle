#ifndef FINANCE_H
#define FINANCE_H

#include <iostream>
#include <string>
using namespace std;

// Class 1: User
class User {
private:
    string name;
    double income;
    double savings;

public:
    User();
    void setDetails();
    void displayDetails();
};

// Class 2: Budget
class Budget {
private:
    double income;
    double expenses;

public:
    Budget();
    void setBudget();
    double calculateRemaining();
};

// Class 3: Financial Advisor
class FinancialAdvisor {
private:
    double income;
    double expenses;

public:
    FinancialAdvisor();
    void giveAdvice();
};

// Class 4: Investment Advisor
class InvestmentAdvisor {
private:
    double investmentAmount;
    double riskLevel;

public:
    InvestmentAdvisor();
    void recommendInvestment();
};

// Class 5: Tax Advisor
class TaxAdvisor {
private:
    double annualIncome;
    double taxAmount;

public:
    TaxAdvisor();
    void calculateTax();
};

#endif
