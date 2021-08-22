#include"bankaccount.h"

//Needed for functions, that are called inside functions that might not be in scope 
void SetupAccount();
char choices(char,Account);

void Welcome()
{
    cout << "+++++++++++++++++++++++++++++++++++++++++\n";
    cout << "+\t" <<"Welcome to Bank of Lannister\t" << "+\n";
    cout << "+++++++++++++++++++++++++++++++++++++++++\n";
    cout << "\n\n";
}

Account Create(){
    Account account;
    
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    cout << "+\t" <<"Hello\t" << "\t\t\t\t\t\t+\n";
    cout << "+\t" << "Please Follow the steps to Create an Account with us\t" << "+\n";
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
    
    account.Setup();
    cout  << "\nThank you for the creation of your account heres is a summary of all the information we have of you\n\n";

    return account;
}

char Menu()
{
    char menuoptions; 
    cout << "\n\n\n";
    
    cout << "+++++++++++++++++++++++++++++++++++++++++\n";
    cout << "+\t" << "Welcome to the Main Menu\t" << "+\n";
    cout << "+\t" << "A: Deposit Money\t\t" << "+\n";
    cout << "+\t" << "B: Withdraw Money\t\t" << "+\n";
    cout << "+\t" << "C: Check Amount\t\t\t" << "+\n";
    cout << "+\t" << "Z: Exit\t\t\t\t" << "+\n";
    cout << "+++++++++++++++++++++++++++++++++++++++++\n";
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

void AccountSummary(Account account)
{
    int accountnumber;
    double bankamount;
    
    accountnumber = account.GetAccountNumber();
    bankamount = account.GetBankAmount();
    string type = account.GetType(); 
    string checking = "Checkings";
    string FName = account.GetFirstName();
    string LName = account.GetLastName();

    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
    cout << "+\t" << "Hello here is the summary of your Account\t" << "\t+\n";
    cout << "+\t" << "Account Number: " << accountnumber << "\t\t\t\t\t+\n"; 
    cout << "+\t" << "Amount within the BankAccount: " << fixed << setprecision(2) << bankamount << "\t\t\t+\n";
    cout << "+\t" << "First Name: " << FName << "\t\t\t\t\t+\n";
    cout << "+\t" << "Last Name: " << LName << "\t\t\t\t\t+\n";
    cout << "+\t";
    cout << "Account Type: ";
    
    if(type == checking)
    {
       cout << "Checking";
    } 
    else
    {
        cout << "Savings";
    }
    
    cout << "\t\t\t\t\t+\n";
    cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
}

int main()
{
    char choice; 
    Account account; 
    
    Welcome();
    account = Create();
    AccountSummary(account);
    
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
                        AccountSummary(account);
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
