#include<iostream>
#include<stdlib.h>
#include<string>
#include<time.h>
#include<iomanip>
using namespace std;

#ifndef _BANKACCOUNT_H
#define _BANKACCOUNT_H

enum AccountType {
    CHECKING, 
    SAVINGS
};                                  //Types of accounts allowed in the bank

class Account{
    
    public:
        Account                 ();               //Default Constructor
        Account                 (const Account&); //Deep Copy Constructor 
        ~Account                ();               //Deconstructor not needed as of yet??
        void   Setup            ();               //Inital setup of account for the bank
        double Deposit          (double);
        double Withdraw         (double);
        string GetFirstName     ();
        string GetLastName      (); 
        int    GetAccountNumber ();
        double GetBankAmount    ();
        string GetType          ();
        void   SetFirstName     (string firstName);
        void   SetLastName      (string lastName);
        void   SetAccountNumber (int accountNumber);
        void   SetAccountType   (string accountType);
        void   SetAccountAmount (double accountAmount);
        void   AccountCreation  ();
        void   AccountOptions   (); //Allows for different types of accounts
    
    private:
        string      firstName;
        string      lastName;
        int         accountNumber;
        AccountType accountType;
        double      accountAmount;
};
#endif