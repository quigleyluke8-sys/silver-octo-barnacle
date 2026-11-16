
#ifndef BUDGET_H
#define BUDGET_H

//creates the budget class with variables
class Budget
{
private:
    double income;
    double needs;
    double wants;
    double savings;

public:
    // Constructors to assign values
    Budget(double i, double n, double w, double s)
    {
        income = i;
        needs = n;
        wants = w;
        savings = s;
    }

    // Calculate total expenses and savings
    double calculateTotal()
    {
        return needs + wants + savings;
    }

    // Calculate money remaining
    double calculateRemaining()
    {
        return income - calculateTotal();
    }

    // Calculate percentage of income
    // The double amount allows the function to recieve different values
    double calculatePercentage(double amount)
    {
        // This prevents a division by 0 (error)
        if (income == 0)
            return 0;

        return amount / income * 100;
    }

    // Calculate recommended amount
    double recommendedAmount(double percentage)
    {
        return income * percentage / 100;
    }

    // Recommend a budgeting strategy
    int recommendStrategy()
    {
        double needsPercent = calculatePercentage(needs);

        if (needsPercent <= 50)
            return 1;
        else if (needsPercent <= 60)
            return 2;
        else
            return 3;
    }
};

#endif
// A destructor is automatically provided since one isnt defines in the .h file
