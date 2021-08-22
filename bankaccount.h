#include<iostream>
#include<stdlib.h>
#include<string>
#include<time.h>
#include<iomanip>
using namespace std;

#ifndef _BANK_H
#define _BANK_H
enum AccountType {CHECKINGS,SAVINGS};//Types of accounts allowed in the bank

class Account{
    
    public:
        Account();//Default Constructor
        Account(const Account&);//Deep Copoy Constructor 
        ~Account();//Deconstructor not needed as of yet??
        void Setup();//Inital setup of account for the bank
        double Deposit(double);
        double Withdraw(double);
        string GetFirstName();
        string GetLastName(); 
        int GetAccountNumber();
        double GetBankAmount();
        string GetType();
        void AccountOptions();//Allows for different types of accounts
    
    private:
        string FirstName;
        string LastName;
        int AccountNumber;
        AccountType type;
        double BankAmount;
};
#endif
