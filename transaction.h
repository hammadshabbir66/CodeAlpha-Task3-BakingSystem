#pragma once

#ifndef TRANSACTION_H
#define TRANSACTION_H
#include<iostream>
using namespace std;
#include <string>

class Transaction {
private:
    std::string transactionID;
    double amount;
    std::string type; // "Deposit" or "Withdrawal"
public:
    Transaction(const string& id, double amount, const string& type);

    string getTransactionID() const;
    double getAmount() const;
    string getType() const;
};

#endif

