#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;

#ifndef _BANK_H
#define _BANK_H
enum AccountType {Checking,Saving};
class Account{
    public:
        Account(); //default constructor
        Account(const Account&);
        ~Account();
        void Setup();//Function that allows the setting up of account
        double Deposit(double);
        double Withdraw(double);
        void GetName();
        int GetAccountNumber();
        double GetBankAmount();
        AccountType GetType();
    private:
        char FirstName[30];
        char LastName[30];
        int AccountNumber;
        AccountType type;
        double BankAmount;
};
#endif
