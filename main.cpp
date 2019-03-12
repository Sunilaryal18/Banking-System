    #include <iostream>
    #include <sstream>
    #include <iomanip>
    #include <cstdlib>
    #include <mysql.h>
    #include "BankAccount.h"
    #include "BankTransaction.h"
    #include<stdlib.h>
    #include<windows.h>
     
    using namespace std;
     
    enum Options { PRINT = 1, NEW, WITHDRAW, DEPOSIT,
                   CLOSE, END };
     
    int mainMenu()
    {
       cout << "\n\n\n\n \t\t\t\t\tMenu Options" << endl
            << "\n\t\t\t\t1 - Print All Accounts"
            << endl << "\t\t\t\t2 - Open New Account" << endl
            << "\t\t\t\t3 - Withdraw Money From Account" << endl << "\t\t\t\t4 - Deposit Money To Account"
            << endl << "\t\t\t\t5 - Close Account" << endl
            << "\t\t\t\t6 - Cancel Transaction\t\t\t\t" << endl;
            cout<<"\n\t\t\t\t Enter Your Choice:";
       int ch;
       cin >> ch;
       return ch;
    }
     
    int main(int argc, char** argv)
    {
       SavingTransaction* bt =
          new SavingTransaction("localhost", "root","","cpp");
     
       int choice;
       int acno;
       string fname, lname;
       double bal;
       
     
       
	   while(1) {
	    	          choice = mainMenu();
          if(choice == END)
             break;
          switch(choice) {
          case PRINT:
          	system("cls");
          	cout<<"\n\n\n\n\n\t\t\t\tPrinting All Accounts. Please Wait.....\n \t\t\t\t Thankyou! for your kind patience.....";
          	Sleep(3000);
          	system("cls");
          	             bt->printAllAccounts();
          	cout<<"Press Y to go to Main Menu.\n Press N to exit." ;
          	break;
          case NEW:
          	system("cls");
          	cout<<"\n\n\n\n\n\t\t\tCreating Form To Create Account. Please Wait.....\n \t\t\t Thankyou! for your kind patience.....";
          	Sleep(3000);
          	system("cls");
          	 cout << "\nEnter Account Number: "<< endl << "->> ";
             cin >> acno;
             cout << "\n Enter First Name:"<< endl << "->> ";
             cin >> fname;
             cout << "\n Enter Last Name: "<< endl << "->> ";
             cin >> lname;
             cout << "\n Enter Balance: "<< endl << "->> ";
             cin >> bal;
             if(acno < 1) {
                cout << "Invalid account number." << "\n";
                system("cls");
                break;
             }
             bt->createAccount(new SavingAccount(acno, fname, lname,bal));
             break;
          case WITHDRAW:
          	system("cls");
          	cout<<"\n\n\n\n\n\t\t\t\tFeaching Account Details. Please Wait.....\n \t\t\t\t Thankyou! for your kind patience.....";
          	Sleep(3000);
          	system("cls");
             cout << "\nEnter Account No: "
                  << endl << "->>  ";
             cin >> acno;
             cout << "\n Enter Amount To Withdraw "
                  << endl << "->>  ";
             cin >> bal;
             system("cls");
             cout<<"\n\n\n\n\n\t\t\t\tProcessing. Please Wait.....\n \t\t\t\t Thankyou! for your kind patience.....\n";
          	Sleep(3000);
          	system("cls");
             if(bal < 0) {
                cout << "You Entered Invalid Amount." << endl;
                break;
             }
             bt->withdraw(acno, bal);
             break;
          case DEPOSIT:
          	system("cls");
          	cout<<"\n\n\n\n\n\t\t\t\tFeaching Account Details. Please Wait.....\n \t\t\t\t Thankyou! for your kind patience.....";
          	Sleep(3000);
          	system("cls");
             cout << "\nEnter account no: "
                  << endl << "->> ";
             cin >> acno;
             cout << "\nAmount To Deposit "
                  << endl << "->> ";
                  
             cin >> bal;
             cout<<"\n\n\n\n\n\t\t\t\tProcessing. Please Wait.....\n \t\t\t\t Thankyou! for your kind patience.....";
          	Sleep(3000);
          	system("cls");
             if(bal < 0) {
                cout << "You have Entered Invalid amount." << endl;
                break;
             }
             bt->deposit(acno, bal);
             break;
         case CLOSE:
         	system("cls");
             cout << "\nEnter Account Number To Close Account "
                  << endl << "->> ";
             cin >> acno;
             
             cout<<"\n\n\n\n\n\t\t\t\tProcessing. Please Wait.....\n \t\t\t\t Thankyou! for your kind patience.....";
          	Sleep(3000);
          	system("cls");
             bt->closeAccount(acno);
             break;
          default:
             cerr << "You Entered Invalid choice!" << endl;
             break;
          }
       }
       return 0;
    }
