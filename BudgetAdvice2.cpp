
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Budget.h"

using namespace std;

int main()
{
    // Output only has 2 decimal places
    cout << fixed << setprecision(2);

    // Setting variables and data types
    double income = 0;
    // Creates an array containing 7 (double) values
    double expenses[7] = {0};
    double needs, wants, savings;
    double recommendedNeeds, recommendedWants, recommendedSavings;

    int strategy;
    int needsPercent, wantsPercent, savingsPercent;
    char student;

    string categories[7] = {
        "Rent / Mortgage",
        "Groceries",
        "Utilities / Bills",
        "Transport",
        "Entertainment",
        "Shopping / Eating Out",
        "Savings / Debt Repayment"
    };

    cout << "Personal Budget Advisor (Ireland)\n";
    cout << "---------------------------------\n";

    // Choosing a budget mode

    cout << "\nAre you a student? (Y/N): ";
    cin >> student;

    // Checks if the user enters Y or N
    while (student != 'Y' && student != 'y' &&
           student != 'N' && student != 'n')
    {
        cout << "Please enter Y or N: ";
        cin >> student;
    }

    // Student Budget Mode

    if (student == 'Y' || student == 'y')
    {
        double partTimeIncome, otherIncome;
        double annualCollegeFees;

        cout << "\nStudent Budget Mode\n";

        // Student monthly income

        cout << "\nMonthly Financial Information\n";

        cout << "Monthly part-time income (EUR): ";
        cin >> partTimeIncome;

        while (partTimeIncome < 0)
        {
            cout << "Value cannot be negative: ";
            cin >> partTimeIncome;
        }

        cout << "Other monthly income (EUR): ";
        cin >> otherIncome;

        while (otherIncome < 0)
        {
            cout << "Value cannot be negative: ";
            cin >> otherIncome;
        }

        // Calculate total student income
        income = partTimeIncome + otherIncome;

        // Student monthly expenses

        string studentCategories[7] = {
            "Accommodation",
            "Groceries",
            "Utilities / Bills",
            "College Transport",
            "Entertainment",
            "Shopping / Eating Out",
            "Savings / Debt Repayment"
        };

        cout << "\nEnter your monthly student expenses\n";

        // Loop to get values for each student expense
        for (int i = 0; i < 7; i++)
        {
            cout << studentCategories[i] << " (EUR): ";
            cin >> expenses[i];

            while (expenses[i] < 0)
            {
                cout << "Value cannot be negative. Try again: ";
                cin >> expenses[i];
            }
        }

        // College fees

        cout << "\nAnnual college fees / costs (EUR): ";
        cin >> annualCollegeFees;

        while (annualCollegeFees < 0)
        {
            cout << "Value cannot be negative: ";
            cin >> annualCollegeFees;
        }

        // Convert annual college costs into monthly costs
        // Add monthly college costs to essential expenses
        expenses[2] = expenses[2] + annualCollegeFees / 12;
    }

    // Standard Budget Mode

    else
    {
        // Monthly income

        cout << "\nMonthly Financial Information\n";

        cout << "Enter monthly take-home income (EUR): ";
        cin >> income;

        while (income <= 0)
        {
            cout << "Income must be greater than zero: ";
            cin >> income;
        }

        // Monthly expenses

        cout << "\nEnter your monthly expenses\n";

        // Loop to get values for each category in the array
        for (int i = 0; i < 7; i++)
        {
            cout << categories[i] << " (EUR): ";
            cin >> expenses[i];

            while (expenses[i] < 0)
            {
                cout << "Value cannot be negative. Try again: ";
                cin >> expenses[i];
            }
        }
    }

    // Check total income is greater than zero
    while (income <= 0)
    {
        cout << "Monthly income must be greater than zero.\n";
        cout << "Enter total monthly income (EUR): ";
        cin >> income;
    }

    // Calculate expense categories

    needs = expenses[0] + expenses[1]
          + expenses[2] + expenses[3];

    wants = expenses[4] + expenses[5];

    savings = expenses[6];

    // Create budget object
    // Values in budget are passed to the constructor in .h
    Budget budget(income, needs, wants, savings);

    // Recommend budgeting strategy
    // Dot operator used to access recommendStrategy function
    strategy = budget.recommendStrategy();

    // Decision making logic to decide a budgeting strategy
    if (strategy == 1)
    {
        needsPercent = 50;
        wantsPercent = 30;
        savingsPercent = 20;
    }
    else if (strategy == 2)
    {
        needsPercent = 60;
        wantsPercent = 20;
        savingsPercent = 20;
    }
    else
    {
        needsPercent = 70;
        wantsPercent = 20;
        savingsPercent = 10;
    }

    // Calculate recommended budget amounts

    recommendedNeeds = budget.recommendedAmount(needsPercent);
    recommendedWants = budget.recommendedAmount(wantsPercent);
    recommendedSavings = budget.recommendedAmount(savingsPercent);

    // Display results

    cout << "\n---------------------------------\n";
    cout << "Monthly Budget Report\n";
    cout << "---------------------------------\n";

    cout << "Monthly income: EUR " << income << endl;

    cout << "\nCurrent spending\n";

    cout << "Needs: EUR " << needs
         << " (" << budget.calculatePercentage(needs) << "%)\n";

    cout << "Wants: EUR " << wants
         << " (" << budget.calculatePercentage(wants) << "%)\n";

    cout << "Savings / Debt: EUR " << savings
         << " (" << budget.calculatePercentage(savings) << "%)\n";

    cout << "\nTotal allocated: EUR "
         << budget.calculateTotal() << endl;

    cout << "Money remaining: EUR "
         << budget.calculateRemaining() << endl;

    // Recommended strategy

    cout << "\nRecommended Budget Strategy\n";

    if (strategy == 1)
        cout << "50/30/20 Rule\n";
    else if (strategy == 2)
        cout << "60/20/20 Rule\n";
    else
        cout << "70/20/10 Rule\n";

    cout << "\nRecommended monthly amounts\n";

    cout << "Needs (" << needsPercent << "%): EUR "
         << recommendedNeeds << endl;

    cout << "Wants (" << wantsPercent << "%): EUR "
         << recommendedWants << endl;

    cout << "Savings (" << savingsPercent << "%): EUR "
         << recommendedSavings << endl;

    // Financial advice

    cout << "\nFinancial Advice\n";

    // Checks the remainder to see if more is allocated than earned
    if (budget.calculateRemaining() < 0)
    {
        cout << "You are spending more than your income.\n";
        cout << "Review your expenses to reduce overspending.\n";
    }
    else
    {
        cout << "You are currently within your monthly income.\n";
    }

    if (needs > recommendedNeeds)
    {
        cout << "Your essential expenses exceed the recommended budget.\n";
        cout << "Consider reviewing bills and transport method.\n";
    }

    if (wants > recommendedWants)
    {
        cout << "Consider reducing entertainment and shopping expenses.\n";
    }

    if (savings < recommendedSavings)
    {
        cout << "Consider increasing your monthly savings.\n";
    }
    else
    {
        cout << "You are meeting your savings target.\n";
    }

    // Additional advice for students

    if (student == 'Y' || student == 'y')
    {
        cout << "\nStudent Financial Advice\n";

        // Check if student is spending more than they earn
        if (budget.calculateRemaining() < 0)
        {
            cout << "Consider reducing non-essential spending.\n";
        }
        else
        {
            cout << "Consider saving for unexpected college costs.\n";
        }

    }

    // Save report to text file
    // Creates a .txt file to store user data
    ofstream file("BudgetReport.txt");
    file << fixed << setprecision(2);

    file << "Personal Budget Report\n";
    file << "----------------------\n";

    // Save the budget mode selected
    if (student == 'Y' || student == 'y')
        file << "Mode: Student\n";
    else
        file << "Mode: Standard\n";

    file << "Monthly income: EUR " << income << endl;

    file << "\nCurrent spending\n";
    file << "Needs: EUR " << needs << endl;
    file << "Wants: EUR " << wants << endl;
    file << "Savings / Debt: EUR " << savings << endl;

    file << "Total allocated: EUR "
         << budget.calculateTotal() << endl;

    file << "Money remaining: EUR "
         << budget.calculateRemaining() << endl;

    file << "\nRecommended budget\n";
    file << needsPercent << "% Needs: EUR "
         << recommendedNeeds << endl;
    file << wantsPercent << "% Wants: EUR "
         << recommendedWants << endl;
    file << savingsPercent << "% Savings: EUR "
         << recommendedSavings << endl;

    // Closes the file after writing
    file.close();

    cout << "\n---------------------------------\n";
    cout << "Results saved to BudgetReport.txt\n";

    return 0;
}
