#include "fintechhh.h"
#include <iostream>
using namespace std;

// ==========================
// CLASS 1: USER
// ==========================

User::User() {
    name = "";
    income = 0;
    savings = 0;
}

void User::setDetails() {
    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter monthly income: ";
    cin >> income;

    cout << "Enter total savings: ";
    cin >> savings;
}

void User::displayDetails() {
    cout << "\nName: " << name << endl;
    cout << "Monthly income: " << income << endl;
    cout << "Savings: " << savings << endl;
}


// ==========================
// CLASS 2: BUDGET
// ==========================

Budget::Budget() {
    income = 0;
    expenses = 0;
}

void Budget::setBudget() {
    cout << "Enter monthly income: ";
    cin >> income;

    cout << "Enter monthly expenses: ";
    cin >> expenses;
}

double Budget::calculateRemaining() {
    return income - expenses;
}


// ==========================
// CLASS 3: FINANCIAL ADVISOR
// ==========================

FinancialAdvisor::FinancialAdvisor() {
    income = 0;
    expenses = 0;
}

void FinancialAdvisor::giveAdvice() {
    cout << "Enter monthly income: ";
    cin >> income;

    cout << "Enter monthly expenses: ";
    cin >> expenses;

    double remaining = income - expenses;

    if (remaining < 0) {
        cout << "You are spending more than you earn." << endl;
    }
    else if (remaining < 500) {
        cout << "Consider reducing your expenses." << endl;
    }
    else {
        cout << "You could consider saving or investing." << endl;
    }
}


// ==========================
// CLASS 4: INVESTMENT ADVISOR
// ==========================

InvestmentAdvisor::InvestmentAdvisor() {
    investmentAmount = 0;
    riskLevel = 0;
}

void InvestmentAdvisor::recommendInvestment() {
    cout << "Enter investment amount: ";
    cin >> investmentAmount;

    cout << "Enter risk level (1-3): ";
    cin >> riskLevel;

    if (investmentAmount <= 0) {
        cout << "Investment amount must be positive." << endl;
    }
    else if (riskLevel == 1) {
        cout << "Consider lower-risk savings or investments." << endl;
    }
    else if (riskLevel == 2) {
        cout << "Consider a diversified investment fund." << endl;
    }
    else if (riskLevel == 3) {
        cout << "Higher-risk investments may have larger losses." << endl;
    }
    else {
        cout << "Invalid risk level." << endl;
    }
}


// ==========================
// CLASS 5: TAX ADVISOR
// ==========================

TaxAdvisor::TaxAdvisor() {
    annualIncome = 0;
    taxAmount = 0;
}

void TaxAdvisor::calculateTax() {
    cout << "Enter annual income: ";
    cin >> annualIncome;

    // Example calculation only:
    // Flat 20% rate, not actual Irish tax rules.
    taxAmount = annualIncome * 0.20;

    cout << "Illustrative tax: " << taxAmount << endl;
}
