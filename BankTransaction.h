    #ifndef SAVINGTRANSACTION_HEADER
    #define SAVINGTRANSACTION_HEADER
     
    #include <mysql.h>
    #include <string>
     
    class SavingAccount;
     
    using namespace std;
    class SavingTransaction
    {
    public:
       SavingTransaction(const string = "localhost",
          const string = "",
       const string = "", const string = "");
       ~SavingTransaction();
       void createAccount(SavingAccount*);
       void closeAccount(int);
       void deposit(int, double);
       void withdraw(int, double);
       SavingAccount* getAccount(int);
       void printAllAccounts();
       void message(string);
     
    private:
       MYSQL* db_conn;
    };
     
    #endif   
