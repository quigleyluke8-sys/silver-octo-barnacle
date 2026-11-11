
#include <iostream>
#include <fstream>
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
    double total = 0;
    double credit;
    int choice;

    ofstream file("TaxCredits.txt");

    cout << "IRISH TAX CREDIT CALCULATOR 2026\n";
    cout << "#################################\n";

    // 1: PERSONAL CIRCUMSTANCES

    cout << "\nPERSONAL CIRCUMSTANCES\n";
    cout << "1. Single\n";
    cout << "2. Married / Civil Partner\n";
    cout << "3. Widowed\n";
    cout << "Enter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        total += 2000;
        file << "Single Person: EUR 2000\n";
    }
    else if (choice == 2)
    {
        total += 4000;
        file << "Married Person: EUR 4000\n";
    }
    else if (choice == 3)
    {
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

        total += credit;
        file << "Widowed Person: EUR " << credit << "\n";
    }

    // 2: EMPLOYMENT

    cout << "\nEMPLOYMENT\n";

    if (ask("Are you a PAYE employee?"))
    {
        total += 2000;
        file << "PAYE Credit: EUR 2000\n";
    }
    else if (ask("Are you self-employed?"))
    {
        total += 2000;
        file << "Earned Income Credit: EUR 2000\n";
    }

    // CATEGORY 3: FAMILY

    cout << "\nFAMILY AND DEPENDANTS\n";

    if (ask("Are you a single parent with a qualifying child?"))
    {
        total += 1900;
        file << "Single Parent Credit: EUR 1900\n";
    }

    if (ask("Do you have an incapacitated child?"))
    {
        total += 3800;
        file << "Incapacitated Child Credit: EUR 3800\n";
    }

    if (ask("Do you support a qualifying dependent relative?"))
    {
        total += 305;
        file << "Dependent Relative Credit: EUR 305\n";
    }

    // 4: DISABILITY

    cout << "\nDISABILITY\n";

    if (ask("Are you blind?"))
    {
        total += 1950;
        file << "Blind Tax Credit: EUR 1950\n";
    }

    if (ask("Do you have a qualifying guide dog?"))
    {
        total += 825;
        file << "Guide Dog Allowance: EUR 825\n";
    }

    // 5: HOUSING

    cout << "\nHOUSING\n";

    if (ask("Do you pay rent and qualify for rent tax credit?"))
    {
        if (ask("Are you jointly assessed as married?"))
            credit = 2000;
        else
            credit = 1000;

        total += credit;
        file << "Rent Tax Credit: EUR " << credit << "\n";
    }

    if (ask("Do you qualify for mortgage interest tax credit?"))
    {
        total += 1250;
        file << "Mortgage Interest Credit (max): EUR 1250\n";
    }

    // CATEGORY 6: AGE

    cout << "\nAGE\n";

    if (ask("Are you aged 65 or older?"))
    {
        if (ask("Are you married or in a civil partnership?"))
            credit = 490;
        else
            credit = 245;

        total += credit;
        file << "Age Tax Credit: EUR " << credit << "\n";
    }

    // DISP RESULTS

    cout << "\n#################################\n";
    cout << "TOTAL ANNUAL TAX CREDITS\n";
    cout << "EUR " << total << endl;

    file << "\nTOTAL: EUR " << total << endl;
    file.close();

    cout << "\nResults saved to TaxCredits.txt\n";

    return 0;
}
