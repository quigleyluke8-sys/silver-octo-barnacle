#include <iostream>
#include <limits>
#include "fintechhh2.h"
using namespace std;

int main()
{
    User user;
    Budget budget;
    FinancialAdvisor advisor;
    InvestmentAdvisor investment;
    TaxAdvisor tax;
    RetirementAdvisor retirement;

    if (user.loadProfile()) {
        cout << "\nWelcome back, " << user.getName() << "! Profile loaded.\n";
    } else {
        cout << "\nNo saved profile found. Enter your details once.\n";
        user.setDetails();
        user.saveProfile();
    }

    int choice = -1;
    do {
        cout << "\n===== FINANCIAL ADVISOR =====\n";
        cout << "1. View / Update User Details\n";
        cout << "2. Budget Calculator\n";
        cout << "3. Financial Advice\n";
        cout << "4. Investment Advice\n";
        cout << "5. Tax Calculator\n";
        cout << "6. Retirement Planning Advisor\n";
        cout << "7. Investment Calculator\n";
        cout << "0. Exit\n";
        cout << "\nEnter your choice: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a menu number.\n";
            continue;
        }
        switch (choice) {
        case 1: {
            user.displayDetails();
            char change;
            cout << "Update these details? (Y/N): ";
            cin >> change;
            if (change == 'Y' || change == 'y') {
                user.setDetails();
                user.saveProfile();
            }
            break;
        }
        case 2:
            budget.setBudget(user.getIncome());
            budget.displayReport();
            budget.giveBudgetAdvice();
            budget.saveReport();
            break;
        case 3:
            advisor.giveAdvice(user.getIncome());
            break;
        case 4:
            investment.giveAdvice(user.getSavings());
            break;
        case 5:
            tax.calculateTax(user.getIncome());
            break;
        case 6:
            retirement.run(user.getIncome(), user.getSavings());
            break;
        case 7: {
            double initial, monthly, rate;
            int years;
            cout << "\nInitial investment (EUR): "; cin >> initial;
            cout << "Monthly contribution (EUR): "; cin >> monthly;
            cout << "Annual interest rate (%): "; cin >> rate;
            cout << "Number of years: "; cin >> years;
            if (!cin || initial < 0 || monthly < 0 || rate < 0 || years < 0) {
                cout << "Invalid investment inputs.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            InvestmentCalculator calculator(initial, monthly, rate, years);
            calculator.displayReport();
            break;
        }
        case 0:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);
    return 0;
}
