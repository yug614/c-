#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;
    string ownerName;

public:
    
    BankAccount(string accNumber, string name, double initialBalance) {
        accountNumber = accNumber;
        ownerName = name;
        balance = initialBalance;
    }

    
    void credit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Credited " << amount << " to the account.\n";
        } else {
            cout << "Invalid credit amount.\n";
        }
    }

    
    void debit(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Debited " << amount << " from the account.\n";
        } else {
            cout << "Invalid or insufficient funds for debit.\n";
        }
    }

   
    void displayBalance() const {
        cout << "Account Holder: " << ownerName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

int main() {
    
    BankAccount myAccount("1234567890", "yug ginoya", 1000.0);

    
    myAccount.displayBalance();
    myAccount.credit(500);
    myAccount.debit(200);
    myAccount.displayBalance();


}
/*
output:
Account Holder: yug ginoya
Account Number: 1234567890
Current Balance: 1000
Credited 500 to the account.
Debited 200 from the account.
Account Holder: yug ginoya
Account Number: 1234567890
Current Balance: 1300
*/
