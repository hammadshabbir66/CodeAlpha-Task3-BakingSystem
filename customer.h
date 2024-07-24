#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include<iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <vector>

class Customer {
private:
    string name;
    string customerID;
    vector<string> accountIDs;

public:
    Customer(const string& name, const string& id);

    string getName() const;
    string getID() const;

    void setName(const string& name);
    void setID(const string& id);

    void addAccountID(const string& accountID);
    const vector<string>& getAccountIDs() const;

};

#endif
