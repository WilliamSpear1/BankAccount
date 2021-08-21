#include<iostream>
#include<stdlib.h>
#include<string>
#include<time.h>
using namespace std;

#ifndef _BANK_H
#define _BANK_H
enum AccountType {CHECKINGS,SAVINGS};
class Account{
    public:
        Account(); //default constructor
        Account(const Account&);
        ~Account();
        void Setup();//Function that allows the setting up of account
        double Deposit(double);
        double Withdraw(double);
        string GetFirstName();
        string GetLastName(); 
        int GetAccountNumber();
        double GetBankAmount();
        string GetType();
        void AccountOptions();
    private:
        string FirstName;
        string LastName;
        int AccountNumber;
        AccountType type;
        double BankAmount;
};
#endif
