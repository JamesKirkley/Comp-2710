/* FILE NAME: project1_Kirkley_JJK0020.cpp
* AUTHOR: James Kirkley
* implement the concept of “Flow of Control” in C++
*/

#include <iostream>
using namespace std;

int main() {
    // VARIABLE INITIALIZATION
    float loan = -1;
    float interestRate = -1;
    float monthlyPaid = -1;
    
    // CURRENCY FORMATTING
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    // USER INPUT
    // NOTE: For valid input, the loan, interest, and monthly payment must
    // be positive. The monthly payment must also be large enough to
    // terminate the loan.
    
    while (loan <= 0) {
        cout << "\nLoan Amount: ";
        cin >> loan;
    }
    

    while (interestRate <= -1) {
        cout << "Interest Rate (% per year): ";
        cin >> interestRate;
    }
    
    


    // Interest rate calculations
    float interestRateC = interestRate / 12 / 100;
    
    while (monthlyPaid <= 0 || monthlyPaid <= loan * interestRateC) {
        cout << "Monthly Payments: ";
        cin >> monthlyPaid;
    }


    cout << endl;

    // Table
    cout << "*****************************************************************\n"
        << "\t      Amortization Table\n"
        << "*****************************************************************\n"
        << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";
        
    // Loop to make the table
    
    int currentMonth = 0;
    float interestTotal = 0;
    
    while (loan > 0) {
        if (currentMonth == 0) {
            cout << currentMonth++ << "\t$" << loan;
        if (loan < 1000) cout << "\t"; // Formatting
            cout << "\t" << "N/A\tN/A\tN/A\t\tN/A\n";
        }
        else {
           float interestPayment = loan * interestRateC;
           float tPrincipal = monthlyPaid - interestPayment;
           loan -= tPrincipal;
           interestTotal += interestPayment;
           
           if (loan < 0) {
                tPrincipal += loan;
                monthlyPaid += loan;
                loan = 0;
           }
           
           cout << currentMonth++ << "\t$" << loan;
           if (loan < 1000) cout << "\t";
           cout << " $" << "\t" << interestRateC * 100 << "\t$" << interestPayment << "\t\t$" <<tPrincipal << "\n";
        }    
            
            
    }
    cout << "****************************************************************\n";
    cout << "\nIt takes " << --currentMonth << " months to pay off "
        << "the loan.\n"
        << "Total interest paid is: $" << interestTotal;
    cout << endl << endl;
    
    
    return 0;
}