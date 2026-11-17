#include "fintechhh2.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>
#include <limits>
using namespace std;

// CLASS 1: USER

User::User() {
    name = "";
    income = 0;
    savings = 0;
}


void User::setDetails()
{
    cout << "\n===== USER DETAILS =====\n";

    cout << "Enter your full name: ";
    getline(cin >> ws, name);

    cout << "Enter monthly income: EUR ";
    while (!(cin >> income) || income < 0)
    {
        cout << "Invalid income. Enter a positive number: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Enter total savings: EUR ";
    while (!(cin >> savings) || savings < 0)
    {
        cout << "Invalid savings. Enter a positive number: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "\nUser details saved successfully.\n";
}

void User::displayDetails()
{
    cout << fixed << setprecision(2);

    cout << "\n===== USER FINANCIAL PROFILE =====\n";

    cout << "Name: " << name << endl;
    cout << "Monthly income: EUR " << income << endl;
    cout << "Annual income: EUR " << income * 12 << endl;
    cout << "Total savings: EUR " << savings << endl;

    if (income > 0)
    {
        double savingsRatio = savings / income;

        cout << "Savings equal to "
             << savingsRatio
             << " months of income.\n";
    }
}


bool User::loadProfile()
{
    ifstream file("UserProfile.txt");
    if (!file) return false;

    string savedName;
    double savedIncome, savedSavings;
    if (!getline(file, savedName) ||
        !(file >> savedIncome >> savedSavings) ||
        savedName.empty() || savedIncome < 0 || savedSavings < 0)
        return false;

    name = savedName;
    income = savedIncome;
    savings = savedSavings;
    return true;
}

void User::saveProfile() const
{
    ofstream file("UserProfile.txt");
    if (!file) {
        cout << "Could not save UserProfile.txt\n";
        return;
    }
    file << name << '\n' << setprecision(17) << income << '\n' << savings << '\n';
}

double User::getIncome() const { return income; }
double User::getSavings() const { return savings; }
string User::getName() const { return name; }


 // CLASS 2: BUDGET CALCULATOR

Budget::Budget()
{
    income = 0;
    expenses = 0;

    housing = 0;
    utilities = 0;
    groceries = 0;  
    transport = 0;
    insurance = 0;
    debt = 0;
    entertainment = 0;
    shopping = 0;
    other = 0;

    savingsGoal = 0;
}

// Collect financial information
void Budget::setBudget(double monthlyIncome)
{
    cout << "\n===== MONTHLY BUDGET CALCULATOR =====\n";

    income = monthlyIncome;
    cout << "\nMonthly income from profile: EUR " << income << endl;

    cout << "\nEnter your monthly expenses\n";

    cout << "Rent / Mortgage: ";
    cin >> housing;

    cout << "Utilities (electricity, internet, etc.): ";
    cin >> utilities;

    cout << "Groceries: ";
    cin >> groceries;

    cout << "Transport: ";
    cin >> transport;

    cout << "Insurance: ";
    cin >> insurance;

    cout << "Debt repayments: ";
    cin >> debt;

    cout << "Entertainment: ";
    cin >> entertainment;

    cout << "Shopping: ";
    cin >> shopping;

    cout << "Other expenses: ";
    cin >> other;

    cout << "\nMonthly savings goal: ";
    cin >> savingsGoal;

    // Calculate total expenses
    expenses = housing + utilities + groceries +
               transport + insurance + debt +
               entertainment + shopping + other;

    cout << "\nBudget information recorded.\n";
}

// Calculate remaining money
double Budget::calculateRemaining()
{
    return income - expenses;
}

// Display detailed budget report
void Budget::displayReport()
{
    cout << fixed << setprecision(2);

    double remaining = calculateRemaining();
    double expensePercent = 0;
    double savingsPercent = 0;

    if (income > 0)
    {
        expensePercent = (expenses / income) * 100;
        savingsPercent = (remaining / income) * 100;
    }

    cout << "\n=====================================\n";
    cout << "         MONTHLY BUDGET REPORT       \n";
    cout << "=====================================\n";

    cout << "Monthly Income:       EUR " << income << endl;
    cout << "Total Expenses:       EUR " << expenses << endl;
    cout << "Remaining Balance:    EUR " << remaining << endl;

    cout << "\nExpense Breakdown\n";

    cout << "Housing:              EUR " << housing << endl;
    cout << "Utilities:            EUR " << utilities << endl;
    cout << "Groceries:            EUR " << groceries << endl;
    cout << "Transport:            EUR " << transport << endl;
    cout << "Insurance:            EUR " << insurance << endl;
    cout << "Debt Repayments:      EUR " << debt << endl;
    cout << "Entertainment:        EUR " << entertainment << endl;
    cout << "Shopping:             EUR " << shopping << endl;
    cout << "Other:                EUR " << other << endl;

    cout << "\nFinancial Ratios\n";
    cout << "Income spent:         " << expensePercent << "%\n";
    cout << "Income remaining:     " << savingsPercent << "%\n";

    // 50/30/20 budget rule
    double needs = housing + utilities + groceries +
                   transport + insurance + debt;

    double wants = entertainment + shopping + other;

    double needsPercent = 0;
    double wantsPercent = 0;

    if (income > 0)
    {
        needsPercent = (needs / income) * 100;
        wantsPercent = (wants / income) * 100;
    }

    cout << "\n50/30/20 Budget Analysis\n";

    cout << "Needs (target 50%):    " << needsPercent << "%\n";
    cout << "Wants (target 30%):    " << wantsPercent << "%\n";
    cout << "Savings (target 20%):  " << savingsPercent << "%\n";

    cout << "\nSavings Goal\n";
    cout << "Target savings:        EUR " << savingsGoal << endl;
    cout << "Available to save:     EUR " << remaining << endl;

    if (remaining >= savingsGoal)
    {
        cout << "Status: Savings goal achievable.\n";
    }
    else
    {
        cout << "Status: Savings goal not achieved.\n";
        cout << "Shortfall: EUR "
             << savingsGoal - remaining << endl;
    }

    // Emergency fund
    double emergencyFund = expenses * 3;

    cout << "\nEmergency Fund Estimate\n";
    cout << "3 months of expenses: EUR "
         << emergencyFund << endl;

    cout << "6 months of expenses: EUR "
         << expenses * 6 << endl;
}

// Give personalised budget advice
void Budget::giveBudgetAdvice()
{
    cout << "\n===== FINANCIAL RECOMMENDATIONS =====\n";

    double remaining = calculateRemaining();

    if (remaining < 0)
    {
        cout << "WARNING: You are spending more than you earn.\n";
        cout << "Reduce non-essential expenses.\n";
    }
    else if (remaining == 0)
    {
        cout << "You are breaking even each month.\n";
        cout << "Try to create a monthly savings surplus.\n";
    }
    else
    {
        cout << "Your monthly budget has a surplus.\n";
    }

    if (income > 0)
    {
        double housingPercent = (housing / income) * 100;

        if (housingPercent > 35)
        {
            cout << "Housing exceeds 35% of income.\n";
            cout << "Consider reviewing housing costs.\n";
        }

        double wantsPercent =
            ((entertainment + shopping + other) / income) * 100;

        if (wantsPercent > 30)
        {
            cout << "Discretionary spending exceeds 30%.\n";
            cout << "Consider reducing entertainment or shopping.\n";
        }

        if (remaining / income < 0.20)
        {
            cout << "Your potential savings rate is below 20%.\n";
            cout << "Review expenses to increase savings.\n";
        }
    }

    if (debt > 0)
    {
        cout << "Review outstanding debts and interest rates.\n";
        cout << "Prioritise expensive debt where appropriate.\n";
    }

    if (remaining >= savingsGoal && savingsGoal > 0)
    {
        cout << "You can meet your monthly savings target.\n";
    }

    cout << "Review your budget regularly.\n";
}

// Save budget report
void Budget::saveReport()
{
    ofstream file("BudgetReport.txt");

    if (!file.is_open())
    {
        cout << "Error creating BudgetReport.txt\n";
        return;
    }

    file << fixed << setprecision(2);

    file << "MONTHLY BUDGET REPORT\n";
    file << "=====================\n";

    file << "Monthly income: EUR " << income << endl;
    file << "Total expenses: EUR " << expenses << endl;
    file << "Remaining balance: EUR "
         << calculateRemaining() << endl;

    file << "\nEXPENSE BREAKDOWN\n";

    file << "Housing: EUR " << housing << endl;
    file << "Utilities: EUR " << utilities << endl;
    file << "Groceries: EUR " << groceries << endl;
    file << "Transport: EUR " << transport << endl;
    file << "Insurance: EUR " << insurance << endl;
    file << "Debt: EUR " << debt << endl;
    file << "Entertainment: EUR " << entertainment << endl;
    file << "Shopping: EUR " << shopping << endl;
    file << "Other: EUR " << other << endl;

    file << "\nSavings goal: EUR " << savingsGoal << endl;

    if (calculateRemaining() >= savingsGoal)
        file << "Savings goal achieved.\n";
    else
        file << "Savings goal not achieved.\n";

    file << "\nEmergency fund (3 months): EUR "
         << expenses * 3 << endl;

    file << "Emergency fund (6 months): EUR "
         << expenses * 6 << endl;

    file.close();

    cout << "\nReport saved to BudgetReport.txt\n";
}


 // ==========================
 // CLASS 3: FINANCIAL ADVISOR
 // ==========================

FinancialAdvisor::FinancialAdvisor()
{
    income = 0;
    expenses = 0;
}

void FinancialAdvisor::giveAdvice(double monthlyIncome)
{
    cout << "\n===== FINANCIAL ADVISOR =====\n";

    income = monthlyIncome;
    cout << "Monthly income from profile: EUR " << income << endl;

    cout << "Enter your monthly expenses (EUR): ";
    cin >> expenses;

    if (income < 0 || expenses < 0)
    {
        cout << "Invalid amounts entered.\n";
        return;
    }

    double remaining = income - expenses;

    cout << fixed << setprecision(2);

    cout << "\n===== FINANCIAL ANALYSIS =====\n";
    cout << "Monthly income: EUR " << income << endl;
    cout << "Monthly expenses: EUR " << expenses << endl;
    cout << "Remaining balance: EUR " << remaining << endl;

    if (remaining < 0)
    {
        cout << "\nWARNING: You are spending more than you earn.\n";
        cout << "Consider reducing unnecessary expenses.\n";
        cout << "Prioritise essential spending and debt repayments.\n";
    }
    else if (remaining == 0)
    {
        cout << "\nYou are breaking even each month.\n";
        cout << "Try to reduce expenses to create savings.\n";
    }
    else
    {
        cout << "\nYou have a positive monthly balance.\n";

        double savingsRate = (remaining / income) * 100;

        cout << "Potential savings rate: "
             << savingsRate << "%\n";

        if (savingsRate >= 20)
        {
            cout << "You have the potential to save at least 20% of your income.\n";
        }
        else
        {
            cout << "Consider increasing your monthly savings.\n";
        }
    }

    cout << "\n===== GENERAL FINANCIAL ADVICE =====\n";
    cout << "1. Build an emergency fund covering 3-6 months of essential expenses.\n";
    cout << "2. Pay off high-interest debt where possible.\n";
    cout << "3. Save regularly and review your budget.\n";
    cout << "4. Consider pension contributions for retirement.\n";
    cout << "5. Review your financial goals annually.\n";
}



// CLASS 4: INVESTMENT ADVISOR

InvestmentAdvisor::InvestmentAdvisor()
{
    savings = 0;
    riskLevel = 0;
    years = 0;
}

void InvestmentAdvisor::giveAdvice(double savedSavings)
{
    double monthlyExpenses;
    double emergencyFund;
    double availableMoney;

    cout << "\nINVESTMENT ADVISOR\n";
    cout << "########################\n";

    savings = savedSavings;
    cout << "Total savings from profile: EUR " << savings << endl;

    cout << "Enter your monthly expenses: EUR ";
    cin >> monthlyExpenses;

    if (savings < 0 || monthlyExpenses < 0)
    {
        cout << "Invalid amount entered.\n";
        return;
    }

    // Emergency fund calculation
    emergencyFund = monthlyExpenses * 6;
    availableMoney = savings - emergencyFund;

    cout << "\nRecommended emergency fund: EUR "
         << emergencyFund << endl;

    if (availableMoney <= 0)
    {
        cout << "Advice: Build your emergency fund "
             << "before investing your savings.\n";
        return;
    }

    cout << "Potentially available to invest: EUR "
         << availableMoney << endl;

    // Investment timeframe
    cout << "\nHow many years will you invest? ";
    cin >> years;

    // Risk tolerance
    cout << "\nChoose your risk tolerance:\n";
    cout << "1. Low risk\n";
    cout << "2. Medium risk\n";
    cout << "3. High risk\n";
    cout << "Enter choice: ";
    cin >> riskLevel;

    if (years <= 0 || riskLevel < 1 || riskLevel > 3)
    {
        cout << "Invalid choice.\n";
        return;
    }

    // Short-term investments
    if (years < 3)
    {
        cout << "\nSHORT-TERM INVESTMENT\n";
        cout << "Consider savings accounts or "
             << "term deposits.\n";
        cout << "Avoid relying on volatile shares "
             << "for short-term goals.\n";
    }

    // Low risk
    else if (riskLevel == 1)
    {
        cout << "\nLOW-RISK STRATEGY\n";
        cout << "Consider deposits and "
             << "high-quality bonds.\n";
        cout << "Focus on preserving capital.\n";
    }

    // Medium risk
    else if (riskLevel == 2)
    {
        cout << "\nMEDIUM-RISK STRATEGY\n";
        cout << "Consider diversified stock "
             << "and bond funds.\n";
        cout << "Balance long-term growth "
             << "with stability.\n";
    }

    // High risk
    else
    {
        cout << "\nHIGH-RISK STRATEGY\n";
        cout << "Consider diversified equity "
             << "index funds for long-term growth.\n";
        cout << "Expect significant market "
             << "fluctuations and possible losses.\n";
    }

    // General financial advice
    cout << "\nADDITIONAL ADVICE\n";
    cout << "- Pay off expensive debt first.\n";
    cout << "- Diversify your investments.\n";
    cout << "- Consider pension contributions.\n";
    cout << "- Review investment fees and taxes.\n";
    cout << "- Never invest money you need soon.\n";
}


// CLASS 5: TAX ADVISOR


#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

// Ask a Yes/No question
bool ask(string question)
{
    char answer;
    cout << question << " (Y/N): ";
    cin >> answer;
    return answer == 'Y' || answer == 'y';
}

// Constructor
TaxAdvisor::TaxAdvisor()
{
    annualIncome = 0;
    taxAmount = 0;
}

// Tax calculator
void TaxAdvisor::calculateTax(double monthlyIncome)
{
    double totalCredits = 0;
    double credit = 0;
    double taxBand = 44000;
    double secondIncome = 0;
    double standardTax, higherTax, grossTax;
    int choice;
    bool married = false;
    bool singleParent = false;

    ofstream file("TaxCredits.txt");

    cout << fixed << setprecision(2);

    cout << "\nIRISH TAX CALCULATOR 2026\n";
    cout << "##########################\n";

    // ANNUAL INCOME
    annualIncome = monthlyIncome * 12;
    cout << "\nAnnual income from profile: EUR " << annualIncome << endl;

    if (annualIncome < 0)
    {
        cout << "Invalid income.\n";
        return;
    }

    // PERSONAL CIRCUMSTANCES
    cout << "\nPERSONAL CIRCUMSTANCES\n";
    cout << "1. Single\n";
    cout << "2. Married / Civil Partner\n";
    cout << "3. Widowed\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        totalCredits += 2000;
        taxBand = 44000;
        file << "Single Person: EUR 2000\n";
    }
    else if (choice == 2)
    {
        married = true;
        totalCredits += 4000;
        taxBand = 53000;

        file << "Married Person: EUR 4000\n";

        if (ask("Does your spouse also earn income?"))
        {
            cout << "Enter spouse's annual income: ";
            cin >> secondIncome;

            if (secondIncome < 0)
            {
                cout << "Invalid income.\n";
                return;
            }

            // Additional band limited to lower earner
            double lowerIncome = min(annualIncome,
                                     secondIncome);

            taxBand += min(35000.0, lowerIncome);
            annualIncome += secondIncome;
        }
    }
    else if (choice == 3)
    {
        taxBand = 44000;

        if (ask("Did your spouse die this year?"))
        {
            credit = 4000;
        }
        else if (ask("Do you have dependent children?"))
        {
            cout << "Years since spouse died (1-5): ";
            cin >> choice;

            switch (choice)
            {
                case 1: credit = 3600; break;
                case 2: credit = 3150; break;
                case 3: credit = 2700; break;
                case 4: credit = 2250; break;
                case 5: credit = 1800; break;
                default: credit = 2000;
            }
        }
        else
        {
            credit = 2540;
        }

        totalCredits += credit;
        file << "Widowed Person: EUR "
             << credit << "\n";
    }
    else
    {
        cout << "Invalid choice.\n";
        return;
    }

    // EMPLOYMENT
    cout << "\nEMPLOYMENT\n";

    if (ask("Are you a PAYE employee?"))
    {
        totalCredits += 2000;
        file << "PAYE Credit: EUR 2000\n";
    }
    else if (ask("Are you self-employed?"))
    {
        totalCredits += 2000;
        file << "Earned Income Credit: EUR 2000\n";
    }

    // Second PAYE credit for a second employee
    if (married && secondIncome > 0)
    {
        if (ask("Is your spouse a PAYE employee?"))
        {
            totalCredits += 2000;
            file << "Spouse PAYE Credit: EUR 2000\n";
        }
    }

    // FAMILY
    cout << "\nFAMILY AND DEPENDANTS\n";

    if (!married &&
        ask("Are you a single parent with a qualifying child?"))
    {
        singleParent = true;
        totalCredits += 1900;
        file << "Single Parent Credit: EUR 1900\n";

        taxBand = 48000;
    }

    if (ask("Do you have an incapacitated child?"))
    {
        totalCredits += 3800;
        file << "Incapacitated Child Credit: EUR 3800\n";
    }

    if (ask("Do you support a qualifying dependent relative?"))
    {
        totalCredits += 305;
        file << "Dependent Relative Credit: EUR 305\n";
    }

    // DISABILITY
    cout << "\nDISABILITY\n";

    if (ask("Are you blind?"))
    {
        totalCredits += 1950;
        file << "Blind Tax Credit: EUR 1950\n";
    }

    if (ask("Do you have a qualifying guide dog?"))
    {
        totalCredits += 825;
        file << "Guide Dog Allowance: EUR 825\n";
    }

    // HOUSING
    cout << "\nHOUSING\n";

    if (ask("Do you qualify for rent tax credit?"))
    {
        if (married)
            credit = 2000;
        else
            credit = 1000;

        totalCredits += credit;
        file << "Rent Tax Credit: EUR "
             << credit << "\n";
    }

    if (ask("Do you qualify for mortgage interest tax credit?"))
    {
        totalCredits += 1250;
        file << "Mortgage Interest Credit: EUR 1250\n";
    }

    // AGE
    cout << "\nAGE\n";

    if (ask("Are you aged 65 or older?"))
    {
        if (married)
            credit = 490;
        else
            credit = 245;

        totalCredits += credit;
        file << "Age Tax Credit: EUR "
             << credit << "\n";
    }

    // INCOME TAX CALCULATION
    double standardIncome = min(annualIncome, taxBand);
    double higherIncome = max(0.0, annualIncome - taxBand);

    standardTax = standardIncome * 0.20;
    higherTax = higherIncome * 0.40;

    grossTax = standardTax + higherTax;

    // Credits cannot make income tax negative
    taxAmount = max(0.0, grossTax - totalCredits);

    // DISPLAY RESULTS
    cout << "\n##########################\n";
    cout << "2026 INCOME TAX RESULTS\n";
    cout << "##########################\n";

    cout << "Annual income: EUR "
         << annualIncome << endl;

    cout << "20% tax band: EUR "
         << taxBand << endl;

    cout << "Tax at 20%: EUR "
         << standardTax << endl;

    cout << "Tax at 40%: EUR "
         << higherTax << endl;

    cout << "Gross income tax: EUR "
         << grossTax << endl;

    cout << "Total tax credits: EUR "
         << totalCredits << endl;

    cout << "FINAL ANNUAL INCOME TAX: EUR "
         << taxAmount << endl;

    cout << "Monthly income tax: EUR "
         << taxAmount / 12 << endl;

    // SAVE RESULTS
    file << "\nAnnual income: EUR "
         << annualIncome << endl;

    file << "Standard rate band: EUR "
         << taxBand << endl;

    file << "Gross income tax: EUR "
         << grossTax << endl;

    file << "Total tax credits: EUR "
         << totalCredits << endl;

    file << "Final income tax: EUR "
         << taxAmount << endl;

    file.close();

    cout << "\nResults saved to TaxCredits.txt\n";
}

 // ==========================
 // CLASS 6: RETIREMENT ADVISOR
 // ==========================

bool RetirementAdvisor::ask(string question)
{
    char answer;

    cout << question << " (Y/N): ";
    cin >> answer;

    return answer == 'Y' || answer == 'y';
}

double RetirementAdvisor::calculateGrowth(
    double savings, double monthly, int years, double rate)
{
    double r = rate / 12;
    int n = years * 12;

    if (r == 0)
        return savings + monthly * n;

    double total = savings * pow(1 + r, n)
                 + monthly * (pow(1 + r, n) - 1) / r;

    return total;
}

double RetirementAdvisor::calculateInflation(
    double balance, int years)
{
    double inflation = 0.02;

    return balance / pow(1 + inflation, years);
}

void RetirementAdvisor::run(double monthlyIncome, double savedSavings)
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

    cout << "\nRetirement Planning Advisor (Ireland)\n";
    cout << "-------------------------------------\n";

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

    cout << "\nFinancial information\n";

    income = monthlyIncome * 12;
    savings = savedSavings;
    cout << "Annual income from profile (EUR): " << income << endl;
    cout << "Savings from profile (EUR): " << savings << endl;

    cout << "Monthly retirement savings (EUR): ";
    cin >> monthlySavings;

    while (income < 0 || savings < 0 || monthlySavings < 0)
    {
        cout << "Values cannot be negative. Try again.\n";
        cout << "Monthly savings: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> monthlySavings;
    }

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

    cout << "\nInvestment risk level\n";
    cout << "1. Low risk (3% annual growth)\n";
    cout << "2. Medium risk (5% annual growth)\n";
    cout << "3. High risk (7% annual growth)\n";
    cout << "Enter choice: ";
    cin >> risk;

    while (risk < 1 || risk > 3)
    {
        cout << "Invalid choice. Enter 1, 2 or 3: ";
        cin >> risk;
    }

    if (risk == 1)
        rate = 0.03;
    else if (risk == 2)
        rate = 0.05;
    else
        rate = 0.07;

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

    employerMonthly = income * employerPercent / 100 / 12;

    // Simplified MyFutureFund contribution model
    governmentMonthly = monthlySavings / 3;

    occupational = calculateGrowth(
        savings, monthlySavings + employerMonthly, years, rate);

    prsa = calculateGrowth(
        savings, monthlySavings, years, rate);

    myFutureFund = calculateGrowth(
        savings, monthlySavings * 2 + governmentMonthly,
        years, rate);

    occupationalToday = calculateInflation(occupational, years);
    prsaToday = calculateInflation(prsa, years);
    myFutureFundToday = calculateInflation(myFutureFund, years);

    cout << "\n-------------------------------------\n";
    cout << "Retirement savings projections\n";
    cout << "-------------------------------------\n";

    cout << "Years until retirement: " << years << endl;
    cout << "Monthly savings: EUR " << monthlySavings << endl;
    cout << "Annual growth rate: " << rate * 100 << "%\n";
    cout << "Annual inflation assumption: 2%\n";

    cout << "\nOccupational Pension\n";
    cout << "Future balance: EUR " << occupational << endl;
    cout << "Value in today's money: EUR "
         << occupationalToday << endl;

    cout << "\nPRSA\n";
    cout << "Future balance: EUR " << prsa << endl;
    cout << "Value in today's money: EUR "
         << prsaToday << endl;

    cout << "\nMyFutureFund (illustrative)\n";
    cout << "Future balance: EUR " << myFutureFund << endl;
    cout << "Value in today's money: EUR "
         << myFutureFundToday << endl;

    cout << "\nRecommended plan based on projected savings\n";

    string recommendation;

    if (employment == 1 && workplacePension)
    {
        if (occupational >= prsa)
            recommendation = "Occupational Pension";
        else
            recommendation = "PRSA";
    }
    else if (eligibleMyFutureFund)
    {
        if (myFutureFund >= prsa)
            recommendation = "MyFutureFund";
        else
            recommendation = "PRSA";
    }
    else
    {
        recommendation = "PRSA or Personal Pension";
    }

    cout << "Suggested plan: " << recommendation << endl;

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
        cout << "Try to begin saving when affordable.\n";
    else if (income > 0 && monthlySavings * 12 < income * 0.10)
        cout << "Consider increasing monthly contributions.\n";
    else
        cout << "Continue making regular contributions.\n";

    if (years <= 10)
        cout << "Review investment risk before retirement.\n";
    else
        cout << "Consider diversified long-term investments.\n";

    // Save report

    if (file.is_open())
    {
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
        file << "Value in today's money: EUR "
             << occupationalToday << endl;

        file << "\nPRSA\n";
        file << "Future balance: EUR " << prsa << endl;
        file << "Value in today's money: EUR "
             << prsaToday << endl;

        file << "\nMyFutureFund (Illustrative)\n";
        file << "Future balance: EUR " << myFutureFund << endl;
        file << "Value in today's money: EUR "
             << myFutureFundToday << endl;

        file << "\nSuggested plan: " << recommendation << endl;

        file.close();

        cout << "\nResults saved to RetirementPlan.txt\n";
    }
    else
    {
        cout << "\nCould not save RetirementPlan.txt\n";
    }
}

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
