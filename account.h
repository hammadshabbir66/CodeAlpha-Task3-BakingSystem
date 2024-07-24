#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<iostream>
using namespace std;
#include <string>
#include <vector>
#include "transaction.h"

class Account {
private:
    string accountID;
    double balance;
    string customerID;
    vector<Transaction> transactionHistory;
public:
    Account(const string& id, double initialBalance,string customerID);

    std::string getAccountID() const;
    double getBalance() const;
    string getCustomerID() const { return customerID; }
    void deposit(double amount);
    void withdraw(double amount);

    void addTransaction(const Transaction& transaction);
    void printTransactionHistory() const;
};

#endif 
