#pragma once
#include<iostream>
using namespace std;
#include "account.h"

#include <iostream>

Account::Account(const string& id, double initialBalance, string custID)
    : accountID(id), balance(initialBalance), customerID(custID) {}

std::string Account::getAccountID() const {
    return accountID;
}

double Account::getBalance() const {
    return balance;
}

void Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        addTransaction(Transaction(accountID, amount, "Deposit"));
    }
}

void Account::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        addTransaction(Transaction(accountID, amount, "Withdrawal"));
    }
}

void Account::addTransaction(const Transaction& transaction) {
    transactionHistory.push_back(transaction);
}

void Account::printTransactionHistory() const {
    for (const auto& txn : transactionHistory) {
        std::cout << "Transaction ID: " << txn.getTransactionID()
            << ", Amount: " << txn.getAmount()
            << ", Type: " << txn.getType() << std::endl;
       
    }
}

