#include"bankaccount.h"
#include "mysql_connection.h"
#include <mysql_driver.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

//Needed for functions, that are called inside functions that might not be in scope 
void SetupAccount();
char choices(char,Account);

int Welcome()
{
    int status;
    cout << "+++++++++++++++++++++++++++++++++++++++++\n";
    cout << "+\t" <<"Welcome to Bank of Lannister\t" << "+\n";
    cout << "+\t" << "1: Returing member\t" << "\t+\n";
    cout << "+\t" << "2: New member\t" << "\t\t+\n";
    cout << "+++++++++++++++++++++++++++++++++++++++++\n";
    cout << "\n\n";
    cout << "> ";
    cin >> status;
    
    if(status != 1 && status != 2)
    {
        cout << "ERROR: Invalid option.Please try again\n"; 
        while(status != 1 && status != 2)
        {
            cout << "> ";
            cin >> status;
        }

    }
    return status;
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
    cout << "+\t" << "D: Display Database\t" << "\t+\n"; 
    cout << "+\t" << "E: Deletion of Account\t" << "\t+\n"; 
    cout << "+\t" << "Z: Exit\t\t\t\t" << "+\n";
    cout << "+++++++++++++++++++++++++++++++++++++++++\n";
    cout << ">";
    
    cin >> menuoptions;
    return menuoptions; 
}

Account Deposit(string username,string password,Account account)
{
    double amount;
    try
    {
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;

        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("localhost", username, password);
        stmt = con -> createStatement();
        stmt->execute("USE bank");
    
    
        cout << "Hello how much do you wish deposit into your Bank Account\n";
        cout << "$"; 
    
        cin >> amount;
        account.Deposit(amount);
        
        string Aamount = to_string(account.GetBankAmount()); 
        string ANumber = to_string(account.GetAccountNumber());
        
        stmt -> execute("UPDATE ACCOUNTS SET ACCOUNTAMOUNT="+Aamount+" WHERE ACCOUNTNUMBER="+ANumber+";");
     
        delete stmt;
        delete con;

        return account;
    }
    catch(sql::SQLException &e)
    {
        cout << "ERROR\n";
        return account;
    } 
}

Account Withdraw(string username, string password, Account account)
{
   double amount;
    try
    {
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;

        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("localhost", username, password);
        stmt = con -> createStatement();
        stmt->execute("USE bank");
    
    
        cout << "Hello how much do you wish to withdraw today\n";
        cout << "$";
    
        cin >> amount;
        
        account.Withdraw(amount);
        
        string Aamount = to_string(account.GetBankAmount()); 
        string ANumber = to_string(account.GetAccountNumber());
        
        stmt -> execute("UPDATE ACCOUNTS SET ACCOUNTAMOUNT="+Aamount+" WHERE ACCOUNTNUMBER="+ANumber+";");
     
        delete stmt;
        delete con;

        return account;
    }
    catch(sql::SQLException &e)
    {
        cout << "ERROR\n";
        return account;
    } 
     
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

string quotesql( const string& s ) {
    return string("'") + s + string("'");
}

Account Returned(string username, string password, string Fname, string Lname, int ANumber)
{
    Account account;
    
    sql::Driver *driver;
    sql::Connection *con;
    sql::Statement *stmt;
    sql::ResultSet *res;

    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("localhost", username, password);
    stmt = con -> createStatement();
    stmt->execute("USE bank");
    
    res = stmt -> executeQuery("SELECT * FROM ACCOUNTS ORDER BY LASTNAME");
    while (res->next()) {
        if(Fname == res -> getString("FirstName") && Lname == res -> getString("LastName") && ANumber == res -> getInt("ACCOUNTNUMBER")){
            account.SetFirstName(res -> getString("FirstName"));
            account.SetLastName(res->getString("LASTNAME"));
            account.SetAccountNumber(res->getInt("ACCOUNTNUMBER"));
            account.SetAccountType(res->getString("ACCOUNTTYPE"));
            account.SetAccountAmount(res->getDouble("ACCOUNTAMOUNT"));
            break; 
        }
    }
    return account;
}
void PrintDatabase(string username,string password)
{

    try{ 
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;

        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("localhost", username, password);
    
        stmt = con -> createStatement();
        stmt->execute("USE bank");
        res = stmt -> executeQuery("SELECT * FROM ACCOUNTS ORDER BY LASTNAME");
        
        while (res->next()) {
            cout << "FirstName = " << res->getString("FIRSTNAME") << endl;
            cout << "LastName = " << res->getString("LASTNAME") <<  endl;
            cout << "ACCOUNT NUMBER = " << res->getInt("ACCOUNTNUMBER") << endl;
            cout << "ACCOUNT TYPE = " << res->getString("ACCOUNTTYPE") <<  endl;
            cout << "ACCOUNT AMOUNT = " << res->getDouble("ACCOUNTAMOUNT") <<  endl;
        }
        delete res;
        delete stmt;
        delete con;
        return;
    }
    catch(sql::SQLException &e)
    {
        cout << "ERROR\n";
    } 
}

void Deletion(string username,string password)
{
    int Anumber;

    cout << "Deletion of your Account please provide the account\n";
    cout << "Account Number: ";
    cin >> Anumber; 

    string ANumber = to_string(Anumber);
    try{ 
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;

        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("localhost", username, password);
        
        stmt = con -> createStatement();
        stmt->execute("USE bank");
        stmt -> execute("DELETE FROM ACCOUNTS WHERE ACCOUNTNUMBER="+ANumber+";");
        cout << "Deletion Successful Account " +ANumber+ " has been deleted\n";
        return;
    }
    catch(sql::SQLException &e)
    {
        cout << "Error\n";
    }
}

int main()
{
    string username;
    string password;

    char choice; 
    char *messageError;
    int status;
    
    string Fname;
    string Lname;
    int ANumber;
    Account account; 
    
    cout << "Please provide username and password for access\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    status = Welcome();
    if(status == 2)
        account = Create();
    else
    {
        cout << "Please provide the First name, Last name, and Account Number\n";
        cout << "FirstName: ";
        cin >> Fname;
        cout << "LastName: ";
        cin >> Lname;
        cout << "Account Number: ";
        cin >> ANumber;
        account = Returned(username,password,Fname,Lname,ANumber);
    }
    AccountSummary(account);
    
    Fname = account.GetFirstName();
    Lname = account.GetLastName();
    ANumber = account.GetAccountNumber();
    string Atype = account.GetType();
    double Aamount = account.GetBankAmount();
    
    string ANumberS = to_string(ANumber);
    string AamountS = to_string(Aamount);
    try{ 
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;

        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("localhost", username, password);
        
        stmt = con -> createStatement();
        stmt->execute("USE bank");
        stmt->execute("INSERT INTO ACCOUNTS(FIRSTNAME, LASTNAME, ACCOUNTNUMBER, ACCOUNTTYPE, ACCOUNTAMOUNT) VALUES ("+quotesql(Fname)+", "+quotesql(Lname)+", "+ANumberS+", "+quotesql(Atype)+", "+AamountS+")");
    
        delete stmt;
        delete con;
    }catch(sql::SQLException &e)
    {
        cout << "ERROR\n";
    } 
    while(choice != 'Z' && choice != 'z')
    {
        choice = Menu(); 
        switch(choice)
        {
            case 'A':
            case 'a':
                        account = Deposit(username,password,account);
                        break;
            case 'B':
            case 'b':
                        account = Withdraw(username,password,account);
                        break;
            case 'C':
            case 'c':
                        AccountSummary(account);
                        break;
            case 'D':
            case 'd':
                        PrintDatabase(username,password);
                        break;
            case 'E':
            case 'e':
                        Deletion(username,password);
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
