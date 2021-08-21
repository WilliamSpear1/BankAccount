#include "bankaccount.h"
using namespace std;

Account::Account()
{
    strcpy(FirstName, "  ");
    strcpy(LastName, "  ");
    AccountNumber = 0;
    BankAmount = 0.0;
}
Account::~Account()
{
    strcpy(FirstName, "  ");
    strcpy(LastName, "  ");
    AccountNumber = 0;
    BankAmount = 0.0;
}
Account::Account(const Account& A)
{
   AccountNumber = A.AccountNumber;
   for(int i = 0; i < strlen(FirstName); i++){
        FirstName[i] = A.FirstName[i]; 
   } 
   for(int i = 0; i < strlen(LastName); i++){
        LastName[i] = A.LastName[i]; 
   } 
   BankAmount = A.BankAmount;
   type = A.type;
}
void Account::Setup(){
    char answer[20];

    AccountNumber = rand() % 1000;
    cout << "What type of account do you want: ";
    cin.getline(answer,20);
    for(int i = 0; i < strlen(answer);i++)
    {
        if(answer[0] == 'S' && answer[0] == 's')
        {
            type = Checking;
        }
        else if(answer[0] == 'C' && answer[0] == 'c')
        {
            type = Saving;
        }
    }
    
    cout << "Enter first name: ";
    cin.ignore();
    cin.getline(FirstName,30);
   
    cout << "Enter last name: ";
    cin.ignore();
    cin.getline(LastName,30);
   
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
void Account::GetName(){
    cout << "FirstName: "<< FirstName << endl;
    cout << "LastName: " << LastName << endl;
}
int Account::GetAccountNumber(){
   return AccountNumber;
}
double Account::GetBankAmount(){
   return BankAmount; 
}
AccountType Account::GetType(){
    return type;
}
