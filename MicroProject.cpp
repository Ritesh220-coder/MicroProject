#include <iostream>
#include <iomanip>  
using namespace std;

int main() {
    int n;
    string category[100];
    float amount[100];
    string date[100];
    float total = 0;

    cout << "--- Expense Tracker ---\n";
    cout << "How many expenses do you want to enter? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nExpense #" << i + 1 << endl;
        cout << "Enter date (DD/MM/YYYY): ";
        cin >> date[i];
        cout << "Enter category: ";
        cin >> category[i];
        cout << "Enter amount (Rs): ";
        cin >> amount[i];
        total += amount[i];
    }

    cout << "\n--- Monthly Expense Summary ---\n";
    cout << left << setw(15) << "Date" << setw(15) << "Category" << setw(15) << "Amount (₹)" << endl;
    cout << "---------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << left << setw(15) << date[i]
             << setw(15) << category[i]
             << "Rs" << fixed << setprecision(2) << amount[i] << endl;
    }
    cout << "---------------------------------------------\n";
    cout << left << setw(30) << "Total Monthly Expense:"
         << "Rs" << fixed << setprecision(2) << total << endl;

    return 0;
}
