#include "InvestmentCalculator.h"
#include <iostream>
#include <cmath>
#include <iomanip>

InvestmentCalculator::InvestmentCalculator(double initial, double monthly, double rate, int timeYears) {
    initialPrincipal = initial;
    monthlyContribution = monthly;
    annualInterestRate = rate / 100.0;
    years = timeYears;
}

double InvestmentCalculator::calculateFutureValue() const {
    double monthlyRate = annualInterestRate / 12.0;
    int totalMonths = years * 12;
    double fvPrincipal = initialPrincipal * std::pow(1.0 + monthlyRate, totalMonths);
    double fvContributions = 0.0;
    if (monthlyRate > 0) {
        fvContributions = monthlyContribution * ((std::pow(1.0 + monthlyRate, totalMonths) - 1.0) / monthlyRate);
    } else {
        fvContributions = monthlyContribution * totalMonths;
    }
    return fvPrincipal + fvContributions;
}

double InvestmentCalculator::calculateTotalContributions() const {
    return initialPrincipal + (monthlyContribution * years * 12);
}

double InvestmentCalculator::calculateTotalInterestEarned() const {
    return calculateFutureValue() - calculateTotalContributions();
}

void InvestmentCalculator::displayReport() const {
    double finalVal = calculateFutureValue();
    double totalContr = calculateTotalContributions();
    double interestEarned = calculateTotalInterestEarned();

    std::cout << "\n========================================\n";
    std::cout << "      INVESTMENT GROWTH REPORT          \n";
    std::cout << "========================================\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Initial Investment:     $" << initialPrincipal << "\n";
    std::cout << "Monthly Contribution:   $" << monthlyContribution << "\n";
    std::cout << "Time Horizon:           " << years << " years\n";
    std::cout << "Annual Interest Rate:   " << (annualInterestRate * 100.0) << "%\n";
    std::cout << "----------------------------------------\n";
    std::cout << "Total Contributions:    $" << totalContr << "\n";
    std::cout << "Total Interest Earned:  $" << interestEarned << "\n";
    std::cout << "Final Portfolio Value:  $" << finalVal << "\n";
    std::cout << "========================================\n";
}