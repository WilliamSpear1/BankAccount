#include "bankaccount.h"
using namespace std;

Account::Account(){
    BankAmount = 0.0;
}

//Deconstructor empty for now could possibly be used down the road
Account::~Account(){}

//Copy Constructor 
Account::Account(const Account& A)
{
    AccountNumber = A.AccountNumber;
    FirstName = A.FirstName; 
    LastName = A.LastName; 
    BankAmount = A.BankAmount;
    type = A.type;
}

//Initalization of the account 
void Account::Setup(){
    char answer;
    srand(time(NULL));

    //Random Account number for each account
    AccountNumber = rand() % 1000 + 1;
    
    cout << "What type of account do you want [C for checking,S for saving]: ";
    cin >> answer;
    answer = toupper(answer);
    if( answer = 'C')
    {
        type = CHECKINGS;
    }else if(answer = 'S')
    {
        type = SAVINGS;
    } 
    
    cout << "Enter first name: ";
    cin >> FirstName;

    cout << "Enter last name: ";
    cin >> LastName; 
   
}

double Account::Deposit(double amount){
    BankAmount = BankAmount + amount;
    cout << "Amount: " << amount << " has been successfully added to your account\n";
    cout << "Thank you" << endl;
    return BankAmount; 
}

double Account::Withdraw(double amount){
    if(amount > BankAmount)
    {
        cout << "Error: " << amount << " is greater then what is inside bank account\n";
        return 0; 
    }
    BankAmount = BankAmount - amount;
    cout << "Thank you" << " the amount of " << amount << " has been successfully withdrawn from your account\n";
    return BankAmount;
}

string Account::GetFirstName(){
       return FirstName;
}

string Account::GetLastName(){
    return LastName;
}

int Account::GetAccountNumber(){
   return AccountNumber;
}

double Account::GetBankAmount(){
   return BankAmount; 
}

string Account::GetType(){
    string answer;
    if(type == CHECKINGS)
    {
        answer = "Checkings";
    } 
    else if(type == SAVINGS)
    {
        answer = "Savings";
    }
    return answer;
}
