#include"bankaccount.h"
#include<iostream>
using namespace std;

void SetupAccount();
char choices(char,Account);

void Welcome()
{
    cout << "+++++++++++++++++++++++++++++++++++++++++\n";
    cout << "Welcome to Bank of Lannister\n";
    cout << "----------------------------------------\n";
    cout << "\n\n";
}

Account Create(){
    Account account;
    cout << "+++++++++++++++++++++++++++++++++++++++++\n";
    cout << "Hello and Welcome to the Bank of Lannister\n";
    cout << "Please Follow the steps to Create an Account with us\n";
    cout << "****************************************\n\n";
    account.Setup();
    cout  << "Thank you for the creation of your account heres is a summary of all the information we have of you\n";

    return account;
}

char Menu()
{
    char menuoptions; 
    cout << "\n\n\n";
    cout << "+++++++++++++++++++++++++++++++++++++++++\n";
    cout << "Welcome to the Main Menu\n";
    cout << "A: Deposit Money\n";
    cout << "B: Withdraw MOney\n";
    cout << "C: Check Amount\n";
    cout << "Z: Exit\n";
    cout << "????????????????????????????????????????\n";
    cout << ">";
    cin >> menuoptions;
    return menuoptions; 
}
Account Deposit(Account account)
{
    double amount; 
    cout << "Hello how much do you wish deposit into your Bank Account\n";
    cout << "$"; 
    cin >> amount;
    account.Deposit(amount);
    return account;
}
Account Withdraw(Account account)
{
   double amount;
   cout << "Hello how much do you wish to withdraw today\n";
   cout << "$";
   cin >> amount;
   account.Withdraw(amount);
   return account;
}

void CheckAmount(Account account)
{
    int accountnumber;
    double bankamount;
    
    accountnumber = account.GetAccountNumber();
    bankamount = account.GetBankAmount();
    cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
    cout << "Hello here is the summary of your "; 
    switch(account.GetType())
    {
        case Checking: 
                        cout << "Checking";
                        break;
    } 
    cout << " Account";
    cout << endl;
    cout << "Account Number: " << accountnumber << endl; 
    cout << "Amount within the BankAccount: " << bankamount << endl;
    account.GetName();
    cout << endl;
    cout << "##########################################\n";
}

int main()
{
    char choice; 
    Account account; 
    Welcome();
    account = Create();
    CheckAmount(account);
    while(choice != 'Z' && choice != 'z')
    {
        choice = Menu(); 
        switch(choice)
        {
            case 'A':
            case 'a':
                        account = Deposit(account);
                        break;
            case 'B':
            case 'b':
                        account = Withdraw(account);
                        break;
            case 'C':
            case 'c':
                        CheckAmount(account);
                        break;
            case 'Z':
            case 'z':
                        break;
            default:
                        cout << "Invalid Input Option\n";
                        break;
        }
    }
    return 0;
}
