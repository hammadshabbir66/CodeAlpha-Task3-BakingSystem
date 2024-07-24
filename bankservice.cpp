#pragma once

#include "bankservice.h"
#include <algorithm>
#include <iostream>
#include "bankservice.h"
#include <iostream>

void BankingService::addCustomer(const Customer& customer) {
    customers.push_back(customer);
}

void BankingService::addAccount(const Account& account) {
    accounts.push_back(account);
    for (auto& customer : customers) {
        if (customer.getID() == account.getCustomerID()) { 
            customer.addAccountID(account.getAccountID());
            break;
        }
    }
}

void BankingService::addTransaction(const Transaction& transaction) {
    transactions.push_back(transaction);
}

void BankingService::deposit(const std::string& accountID, double amount) {
    Account* account = getAccount(accountID);
    if (account) 
    {
        account->deposit(amount);
        cout << "Deposit of $" << amount << " successful to account " << accountID << "." << endl;
    }
    else 
    {
        cout << "Error: Account with ID " << accountID << " does not exist." << endl;
    }
}

void BankingService::withdraw(const std::string& accountID, double amount) {
    Account* account = getAccount(accountID);
    if (account) 
    {
        if (account->getBalance() >= amount) 
        {
            account->withdraw(amount);
            cout << "Withdrawal of $" << amount << " successful from account " << accountID << "." << endl;
        }
        else 
        {
            cout << "Error: Insufficient funds in account " << accountID << "." << endl;
        }
    }
    else {
        cout << "Error: Account with ID " << accountID << " does not exist." << endl;
    }
}


Account* BankingService::getAccount(const string& accountID) {
    for (auto& account : accounts) {
        if (account.getAccountID() == accountID) {
            return &account;
        }
    }
    return nullptr;
}

const Account* BankingService::getAccount(const string& accountID) const {
    for (const auto& account : accounts) {
        if (account.getAccountID() == accountID) {
            return &account;
        }
    }
    return nullptr;
}

Customer* BankingService::getCustomerByAccountID(const std::string& accountID) {
    for (auto& customer : customers) {
        const auto& accountIDs = customer.getAccountIDs();
        if (std::find(accountIDs.begin(), accountIDs.end(), accountID) != accountIDs.end()) {
            return &customer;
        }
    }
    return nullptr;
}


const Customer* BankingService::getCustomerByAccountID(const std::string& accountID) const {
    for (const auto& customer : customers) {
        const auto& accountIDs = customer.getAccountIDs();
        if (std::find(accountIDs.begin(), accountIDs.end(), accountID) != accountIDs.end()) {
            return &customer;
        }
    }
    return nullptr;
}

void BankingService::displayAccountInfo(const string& accountID) const {
    const Account* account = getAccount(accountID);
    if (account) {
        const Customer* customer = getCustomerByAccountID(accountID);
        if (customer) {
            cout << "Customer Name: " << customer->getName() << endl;
        }
        cout << "Account Balance: $" << account->getBalance() << endl;
        cout << "Recent Transactions:" << endl;
        account->printTransactionHistory();
    }
}