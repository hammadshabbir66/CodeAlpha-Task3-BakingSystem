#pragma once

#ifndef BANKINGSERVICE_H
#define BANKINGSERVICE_H

#include <iostream>
#include <vector>
#include <string>
#include "customer.h"
#include "account.h"
#include "transaction.h"
#include <iostream>
using namespace std;

class BankingService {
private:

    vector<Customer> customers;
    vector<Account> accounts;
    vector<Transaction> transactions;

public:
    void addCustomer(const Customer& customer);
    void addAccount(const Account& account);
    void addTransaction(const Transaction& transaction);

    void deposit(const std::string& accountID, double amount);
    void withdraw(const std::string& accountID, double amount);

    Account* getAccount(const string& accountID);
    const Account* getAccount(const string& accountID) const;
    Customer* getCustomerByAccountID(const string& accountID);
    const Customer* getCustomerByAccountID(const string& accountID)const ;
    void displayAccountInfo(const string& accountID) const;
};

#endif 
