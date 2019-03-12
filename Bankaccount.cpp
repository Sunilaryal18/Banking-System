    #include "BankAccount.h"
     
    #include <string>
    #include <cstring>
     
    using namespace std;
     
    SavingAccount::SavingAccount(int accno, string fname,
       string lname, double bal)
    {
       setAccountNumber(accno);
       setFirstName(fname);
       setLastName(lname);
       setBalance(bal);
    }
     
    void SavingAccount::setAccountNumber(int accno)
    {
       accountNumber = accno;
    }
     
    void SavingAccount::setLastName(string lname)
    {
       const char* ln = lname.data();
       int len = lname.size();
       len = (len < MAX_SIZE ? len : MAX_SIZE - 1);
       strncpy(lastName, ln, len);
       lastName[len] = '\0';
    }
     
    void SavingAccount::setFirstName(string fname)
    {
       const char* fn = fname.data();
       int len = fname.size();
       len = (len < MAX_SIZE ? len : MAX_SIZE - 1);
       strncpy(firstName, fn, len);
       firstName[len] = '\0';
    }
     
    void SavingAccount::setBalance(double bal)
    {
       balance = bal;
    }
     
    int SavingAccount::getAccountNumber() const
    {
       return accountNumber;
    }
     
    string SavingAccount::getFirstName() const
    {
       return firstName;
    }
     
    string SavingAccount::getLastName() const
    {
       return lastName;
    }
     
    double SavingAccount::getBalance() const
    {
       return balance;
    }
     
    SavingAccount::~SavingAccount()
    {
    }
