#pragma once

#include "customer.h"
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>

Customer::Customer(const string& name, const string& id)
    : name(name), customerID(id) {}

std::string Customer::getName() const {
    return name;
}

std::string Customer::getID() const {
    return customerID;
}

void Customer::setName(const std::string& name) {
    this->name = name;
}

void Customer::setID(const std::string& id) {
    this->customerID = id;
}

void Customer::addAccountID(const string& accountID) {
    accountIDs.push_back(accountID);
}

const vector<string>& Customer::getAccountIDs() const {
    return accountIDs;
}

