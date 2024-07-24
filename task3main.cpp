#include <iostream>
#include "Customer.h"
#include "Account.h"
#include "Transaction.h"
#include "bankservice.h"
#include <iostream>
#include <cstring>
using namespace std;

void displayMenu() {
    
    

    cout << "Banking System Menu:" << endl;
    cout << "1. Add Customer" << endl;
    cout << "2. Add Account" << endl;
    cout << "3. Perform Transaction" << endl;
    cout << "4. Display Account Info" << endl;
    cout << "5. Exit" << endl;
    cout << "-------------------------------" << endl;
    cout << "Enter your choice: ";
  
}

int main() {
    BankingService bank;
    int choice;

    cout << "\n\t\t\t\t\t======================================================" << endl;
    cout << "\t\t\t\t\t|             Welcome to the Banking System          |" << endl;
    cout << "\t\t\t\t\t======================================================" << endl << endl;

    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore();
        cout << "-------------------------------" << endl;

        switch (choice) 
        {
        case 1:
        {
            string name, id;
            cout << "Enter customer name: ";
            getline(cin, name);
            cout << "Enter customer ID: ";
            getline(cin, id);
            bank.addCustomer(Customer(name, id));
            cout << "Customer added successfully!" << endl;
            cout << "-------------------------------" << endl;
            break;
        }
        case 2:
        {
            string accountID,id;
            double initialBalance;
            cout << "Enter customer ID: ";
            getline(cin, id);
            cout << "Enter account ID: ";
            getline(cin, accountID);
            cout << "Enter initial balance: ";
            cin >> initialBalance;
            bank.addAccount(Account(accountID, initialBalance,id));
            cout << "Account added successfully!" << endl;
            cout << "-------------------------------" << endl;
            break;
        }
        case 3:
        {
            string accountID, type;
            double amount;
            cout << "Enter account ID: ";
            getline(cin, accountID);
            cout << "Enter transaction type (deposit/withdraw): ";
            getline(cin, type);
            cout << "Enter amount: ";
            cin >> amount;
            cout << "-------------------------------" << endl;

            if (type == "deposit") 
            {
                bank.deposit(accountID, amount);
            }
            else if (type == "withdraw") 
            {
                bank.withdraw(accountID, amount);
            }
            else 
            {
                cout << "Invalid transaction type!" << endl;
                cout << "-------------------------------" << endl;
            }
            break;
        }
        case 4:
        {
            string accountID;
            cout << "Enter account ID: ";
            getline(cin, accountID);
            bank.displayAccountInfo(accountID);
            cout << "-------------------------------" << endl;
            break;
        }

        case 5: 
        {
            cout << "Exiting..." << endl;
            cout << "-------------------------------" << endl;
            return 0;
        }
        default: 
        {
            cout << "Invalid choice! Please try again." << endl;
            cout << "-------------------------------" << endl;
            break;
        }
        }
    }

    return 0;
}