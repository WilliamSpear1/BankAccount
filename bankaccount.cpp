#include "bankaccount.h"
Account::Account(){
    accountAmount = 0.0;
}

//Deconstructor empty for now could possibly be used down the road
Account::~Account()
{}

Account::Account(const Account& account)
{
    accountNumber = account.accountNumber;
    firstName     = account.firstName; 
    lastName      = account.lastName; 
    accountAmount = account.accountAmount;
    type          = account.type;
}

void Account::AccountOptions(){
    char answer;
    
    cout << "+++++++++++++++++++++++++++++++++++++++++\n";
    cout << "+\t" <<"Different Account Opotions" << "\t+\n";
    cout << "+\t" <<"C: Checking Account" << "\t\t+\n";
    cout << "+\t" << "S: Savings Account" << "\t\t+\n";
    cout << "+++++++++++++++++++++++++++++++++++++++++\n";
    cout << "Please choose an Account type from the menu\n";
    cout << ">";
    cin >> answer;
    
    switch(answer){
        case 'C':
        case 'c':
                type = CHECKING;
                break;
        case 'S':
        case 's':
                type = SAVINGS;
                break;
        default: 
                cout << "Invaild Option" << endl;
                cout << "Set to Default Type: Checking" << endl;
                type = CHECKING;
                break;
    }
}

void Account::Setup(){
    char answer;
    double amount = GetBankAmount(); 

    srand(time(NULL));                  //inital seed for randomization

    accountNumber = rand() % 1000 + 1;  //Random Account number for each account
    
    AccountOptions();
    
    cout << "Enter first name: ";
    cin >> firstName;

    cout << "Enter last name: ";
    cin >> lastName; 
}

double Account::Deposit(double amount){
    accountAmount = accountAmount + amount;
    cout << "Amount:$ " << amount << " has been successfully added to your account\n";
    cout << "Thank you" << endl;
    return accountAmount; 
}

double Account::Withdraw(double amount){
    if(amount > accountAmount)
    {
        cout << "Error:$" << amount << " is greater then what is inside bank account\n";
        return 0; 
    }

    accountAmount = accountAmount - amount;
    cout << "Thank you" << " the amount of $" << amount << " has been successfully withdrawn from your account\n";
    
    return accountAmount;
}

string Account::GetFirstName  () { return firstName;     }
string Account::GetLastName   () { return lastName;      }
int Account::GetAccountNumber () { return accountNumber; }
double Account::GetBankAmount () { return accountAmount; }

string Account::GetType(){
    string answer;

    if(type == CHECKING)
    {
        answer = "Checking";
    } 
    else if(type == SAVINGS)
    {
        answer = "Savings";
    }

    return answer;
}

void  Account::SetFirstName    (string Fname) { firstName = firstName;         }
void Account::SetLastName      (string Lname) { lastName = lastName;           }
void Account::SetAccountNumber (int ANumber)  { accountNumber = accountNumber; }

void Account::SetAccountType(string type)
{
    if(type == "Checking")
        type = CHECKING;
    else if(type == "Saving")
        type = SAVINGS;

}

void Account::SetAccountAmount (double accountAmount) { accountAmount = accountAmount; }