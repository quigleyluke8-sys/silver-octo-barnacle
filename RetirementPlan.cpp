
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include "Retirement.h"
using namespace std;

// Ask a Yes or No question
bool ask(string question)
{
    char answer;

    cout << question << " (Y/N): ";
    cin >> answer;

    return answer == 'Y' || answer == 'y';
}

int main()
{
    cout << fixed << setprecision(2);

    int age, retirementAge, employment;
    int years, risk;
    double income, savings, monthlySavings;
    double rate, employerPercent = 0;
    bool workplacePension = false;
    bool eligibleMyFutureFund = false;
    double employerMonthly, governmentMonthly;
    double occupational, prsa, myFutureFund;
    double occupationalToday, prsaToday, myFutureFundToday;

    ofstream file("RetirementPlan.txt");
    file << fixed << setprecision(2);

    cout << "Retirement Planning Advisor (Ireland)\n";
    cout << "-------------------------------------\n";

    // Personal questions

    cout << "\nPersonal circumstances\n";

    cout << "Enter your age: ";
    cin >> age;

    cout << "Enter desired retirement age: ";
    cin >> retirementAge;

    while (age < 18 || retirementAge <= age ||
           retirementAge > 100)
    {
        cout << "Invalid ages. Try again.\n";
        cout << "Your age: ";
        cin >> age;
        cout << "Retirement age: ";
        cin >> retirementAge;
    }

    years = retirementAge - age;

    // Financial questions

    cout << "\nFinancial information\n";

    cout << "Annual income (EUR): ";
    cin >> income;

    cout << "Current retirement savings (EUR): ";
    cin >> savings;

    cout << "Monthly retirement savings (EUR): ";
    cin >> monthlySavings;

    while (income < 0 || savings < 0 || monthlySavings < 0)
    {
        cout << "Values cannot be negative. Try again.\n";

        cout << "Annual income: ";
        cin >> income;

        cout << "Current savings: ";
        cin >> savings;

        cout << "Monthly savings: ";
        cin >> monthlySavings;
    }

    // Employment questions

    cout << "\nEmployment\n";

    cout << "1. Employed\n";
    cout << "2. Self-employed\n";
    cout << "3. Unemployed\n";
    cout << "Enter choice: ";
    cin >> employment;

    while (employment < 1 || employment > 3)
    {
        cout << "Enter 1, 2 or 3: ";
        cin >> employment;
    }

    // Investment risk level

    cout << "\nInvestment risk level\n";
    cout << "1. Low risk (3% annual growth)\n";
    cout << "2. Medium risk (5% annual growth) (best case scenario)\n";
    cout << "3. High risk (7% annual growth) (best case scenario)\n";
    cout << "Enter choice: ";
    cin >> risk;

    while (risk < 1 || risk > 3)
    {
        cout << "Invalid choice. Enter 1, 2 or 3: ";
        cin >> risk;
    }

    if (risk == 1)
    {
        rate = 0.03;
    }
    else if (risk == 2)
    {
        rate = 0.05;
    }
    else
    {
        rate = 0.07;
    }

    // Employer contributions

 
    // Employer contributions

    cout << "\nEmployer contributions\n";

    if (employment == 1)
    {
        workplacePension = ask(
            "Are you contributing to a qualifying workplace pension?");

        if (workplacePension)
        {
            if (ask("Does your employer contribute to your pension?"))
            {
                cout << "Employer contribution (% of salary): ";
                cin >> employerPercent;

                while (employerPercent < 0 || employerPercent > 100)
                {
                    cout << "Enter a percentage between 0 and 100: ";
                    cin >> employerPercent;
                }
            }
        }

        if (!workplacePension && age >= 23 &&
            age < 60 && income >= 20000)
        {
            eligibleMyFutureFund = true;
        }
    }

Pension pension(income, employerPercent, monthlySavings);

    employerMonthly = pension.employerContribution();
    
    governmentMonthly = pension.governmentContribution();

    // Calculate retirement savings

    Retirement occupationalPlan(
        savings, monthlySavings + employerMonthly, years, rate);

    Retirement prsaPlan(
        savings, monthlySavings, years, rate);

    Retirement myFutureFundPlan(
        savings, monthlySavings * 2 + governmentMonthly, years, rate);

    occupational = occupationalPlan.calculateGrowth();
    prsa = prsaPlan.calculateGrowth();
    myFutureFund = myFutureFundPlan.calculateGrowth();

    // Calculate inflation-adjusted savings

    occupationalToday = occupationalPlan.calculateInflation(occupational);

    prsaToday = prsaPlan.calculateInflation(prsa);

    myFutureFundToday = myFutureFundPlan.calculateInflation(myFutureFund);

    // Display results

    cout << "\n-------------------------------------\n";
    cout << "Retirement savings projections\n";
    cout << "-------------------------------------\n";

    cout << "Years until retirement: " << years << endl;
    cout << "Monthly savings: EUR " << monthlySavings << endl;
    cout << "Annual growth rate: " << rate * 100 << "%\n";
    cout << "Annual inflation assumption: 2%\n";

    cout << "\nOccupational Pension\n";
    cout << "Future balance: EUR " << occupational << endl;
    cout << "Value in today's money: EUR " << occupationalToday << endl;

    cout << "\nPRSA\n";
    cout << "Future balance: EUR " << prsa << endl;
    cout << "Value in today's money: EUR " << prsaToday << endl;

    cout << "\nMyFutureFund (illustrative)\n";
    cout << "Future balance: EUR " << myFutureFund << endl;
    cout << "Value in today's money: EUR " << myFutureFundToday << endl;

    // Compare retirement plans


    // Compare retirement plans

    cout << "\nRecommended plan based on projected savings\n";

    if (employment == 1 && workplacePension)
    {
        if (occupational >= prsa)
        {
            cout << "Occupational Pension has the highest projection.\n";
            file << "Highest projection: Occupational Pension\n";
        }
        else
        {
            cout << "PRSA has the highest projection.\n";
            file << "Highest projection: PRSA\n";
        }
    }
    else if (eligibleMyFutureFund)
    {
        if (myFutureFund >= prsa)
        {
            cout << "MyFutureFund has the highest projection.\n";
            file << "Highest projection: MyFutureFund\n";
        }
        else
        {
            cout << "PRSA has the highest projection.\n";
            file << "Highest projection: PRSA\n";
        }
    }
    else
    {
        cout << "Consider a PRSA or Personal Pension.\n";
        file << "Suggested plan: PRSA or Personal Pension\n";
    }


    // Financial advice

    cout << "\nFinancial advice\n";

    if (employment == 1)
    {
        cout << "Consider an Occupational Pension.\n";
        cout << "Check available employer contributions.\n";

        if (eligibleMyFutureFund)
        {
            cout << "You may qualify for MyFutureFund if you\n";
            cout << "have no qualifying payroll pension.\n";
        }
    }
    else if (employment == 2)
    {
        cout << "Consider a PRSA or Personal Pension.\n";
        cout << "Compare pension fees and tax relief.\n";
    }
    else
    {
        cout << "Consider a PRSA when financially possible.\n";
        cout << "Build emergency savings first.\n";
    }

    if (monthlySavings == 0)
    {
        cout << "Try to begin saving when affordable.\n";
    }
    else if (income > 0 && monthlySavings * 12 < income * 0.10)
    {
        cout << "Consider increasing monthly contributions.\n";
    }
    else
    {
        cout << "Continue making regular contributions.\n";
    }

    if (years <= 10)
    {
        cout << "Review investment risk before retirement.\n";
    }
    else
    {
        cout << "Consider diversified long-term investments.\n";
    }

    // Save results to file

    file << "Retirement Planning Report\n";
    file << "--------------------------\n";

    file << "Current age: " << age << endl;
    file << "Retirement age: " << retirementAge << endl;
    file << "Years until retirement: " << years << endl;

    file << "\nFinancial information\n";
    file << "Annual income: EUR " << income << endl;
    file << "Current savings: EUR " << savings << endl;
    file << "Monthly savings: EUR " << monthlySavings << endl;
    file << "Annual growth rate: " << rate * 100 << "%\n";
    file << "Annual inflation assumption: 2%\n";

    file << "\nRetirement projections\n";

    file << "\nOccupational Pension\n";
    file << "Future balance: EUR " << occupational << endl;
    file << "Value in today's money: EUR " << occupationalToday << endl;

    file << "\nPRSA\n";
    file << "Future balance: EUR " << prsa << endl;
    file << "Value in today's money: EUR " << prsaToday << endl;

    file << "\nMyFutureFund (Estimated)\n";
    file << "Future balance: EUR " << myFutureFund << endl;
    file << "Value in today's money: EUR " << myFutureFundToday << endl;

    file.close();

    cout << "\n-------------------------------------\n";
    cout << "Results saved to RetirementPlan.txt\n";

    return 0;
}
