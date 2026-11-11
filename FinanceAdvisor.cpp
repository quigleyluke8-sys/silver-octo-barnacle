#include <iostream>
#include "fintechhh.h"
using namespace std;

int main() {

    // Create objects from the five classes
    User user;
    Budget budget;
    FinancialAdvisor advisor;
    InvestmentAdvisor investment;
    TaxAdvisor tax;

    int choice = 0;

    do {
        cout << "\n===== FINANCIAL ADVISOR =====" << endl;

        cout << "1. User Details" << endl;
        cout << "2. Budget Calculator" << endl;
        cout << "3. Financial Advice" << endl;
        cout << "4. Investment Advice" << endl;
        cout << "5. Tax Calculator" << endl;
        cout << "0. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                user.setDetails();
                user.displayDetails();
                break;

            case 2:
                budget.setBudget();

                cout << "Remaining money: "
                     << budget.calculateRemaining()
                     << endl;
                break;

            case 3:
                advisor.giveAdvice();
                break;

            case 4:
                investment.recommendInvestment();
                break;

            case 5:
                tax.calculateTax();
                break;

            case 0:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
                break;
        }

    } while (choice != 0);

    return 0;
}
