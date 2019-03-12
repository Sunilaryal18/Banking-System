    #ifndef SAVINGACCOUNT_HEADER
    #define SAVINGACCOUNT_HEADER
     
    #include <string>
    using 	namespace std;
     
    class SavingAccount
    {
    public:
       static const int MAX_SIZE = 30;
     
       SavingAccount(int = 0, string = "",
          string = "", double = 0.0);
       ~SavingAccount();
     
	        void setAccountNumber(int);
       void setLastName(string);
       void setFirstName(string);
       void setBalance(double);
     
       int getAccountNumber() const;
       string getFirstName() const;
       string getLastName() const;
       double getBalance() const;
     
    private:
       int accountNumber;
       char firstName[MAX_SIZE];
       char lastName[MAX_SIZE];
       double balance;
    };
     
    #endif  
