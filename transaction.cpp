#pragma once
// Transaction.cpp
#include "transaction.h"
#include<iostream>
using namespace std;

Transaction::Transaction(const string& id, double amount, const string& type)
    : transactionID(id), amount(amount), type(type) {}

std::string Transaction::getTransactionID() const {
    return transactionID;
}

double Transaction::getAmount() const {
    return amount;
}

std::string Transaction::getType() const {
    return type;
}
