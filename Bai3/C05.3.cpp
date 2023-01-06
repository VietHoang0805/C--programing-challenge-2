#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
int main()
{
    const int MONTHS = 12;
    
    float starting_balance,
          annual_interest_rate,
          amount_deposited,
          amount_withdrawn,

          interest_rate,
          monthly_interest_rate,
          
          balance,
          total_deposits,
          total_withdrawn,
          total_interest_earned;

    int months_since_established;

	ofstream outfile;
    outfile.open("Report.txt");
    cout << "\nEnter annual interest rate: ";
    while (!(cin >> annual_interest_rate))
    {
        cout << "Error: a number must be entered... ";
        cin.clear();
        cin.ignore(123, '\n');
    }
    outfile <<cout << "Annual interest rate: " << annual_interest_rate << endl;

    cout << "Enter starting balance: ";
    while (!(cin >> starting_balance))
    {
        cout << "Error: a number must be entered... ";
        cin.clear();
        cin.ignore(123, '\n');
    }
	outfile <<cout << "Starting balance: " << starting_balance << endl;

    balance = starting_balance;

    cout << "Enter months passed since account "
         << "was established: ";
    while (!(cin >> months_since_established) || 
             months_since_established < 0)
    {
        cout << "Error: a number must be entered... ";
        cin.clear();
        cin.ignore(123, '\n');
    }
	outfile <<cout << "Months passed since account " << months_since_established << endl;

    monthly_interest_rate = annual_interest_rate / MONTHS;

    for (int i = 0; i < months_since_established; i++)
    {
        cout << "Enter the amount deposited for month " 
             << (i + 1) << ": ";
        while (!(cin >> amount_deposited) || 
                 amount_deposited < 0)
        {
            cout << "Error: a positive number must be "
                 << "entered.\nEnter the amount deposited "
                 << "for month " 
                 << (i + 1) << ": ";
            cin.clear();
            cin.ignore(123, '\n');
        }
	outfile << "The amount deposited for month: " << months_since_established << endl;
        total_deposits += amount_deposited;
        balance += amount_deposited;

        if (balance < 0)
            break;

        cout << "Enter the amount withdrawn for month " 
             << (i + 1) << ": ";
        while (!(cin >> amount_withdrawn) || 
                 amount_withdrawn < 0)
        {
            cout << "Error: a positive number must be "
                 << "entered. Enter the amount withdrawn "
                 << "for month " 
                 << (i + 1) << ": ";
            cin.clear();
            cin.ignore(123, '\n');
        }
        outfile << cout <<"The amount withdrawn for month: "<<amount_withdrawn<<endl;

        total_withdrawn += amount_withdrawn;
        balance -= amount_withdrawn;

        if (balance < 0)
            break;

        interest_rate = (monthly_interest_rate * balance);
        balance += interest_rate;

        if (balance < 0)
            break;

        total_interest_earned += (interest_rate);
    } // for loop end

    if(balance < 0)
    {
        cout << "I'm sorry, your account has been closed\n"; 
        cout << "due to having a negative balance." << endl;
    }
    else
    {
        outfile << cout << setprecision(2) << fixed << endl;
        outfile << cout << "Starting balance            = $" 
             << starting_balance << endl;

        outfile << cout << "Ending balance              = $" 
             << balance << endl;

        outfile << cout << "Total amount in deposits    = $" 
             << total_deposits << endl;

        outfile << cout << "Total amount in withdrawals = $" 
             << total_withdrawn << endl;

        outfile << cout << "Total interest earned       = $" 
             << total_interest_earned 
             << endl 
             << endl;
    }
    
    

    return 0;
}
