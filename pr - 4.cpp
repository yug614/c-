#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class BankAccount {
protected:
    int accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(int accNo, string name, double bal) {
        accountNumber = accNo;
        accountHolderName = name;
        balance = bal;
    }

    virtual void deposit(double amount) {
        balance += amount;
        cout << "Deposited ?" << amount << " successfully.\n";
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawn ?" << amount << " successfully.\n";
        } else {
            cout << "Insufficient funds.\n";
        }
    }

    double getBalance() const {
        return balance;
    }

    virtual void displayAccountInfo() const {
        cout << "\nAccount No: " << accountNumber
             << "\nName: " << accountHolderName
             << "\nBalance: ?" << balance << endl;
    }

    virtual void calculateInterest() {
        cout << "No interest calculation for base account.\n";
    }

    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
    double interestRate;

public:
    SavingsAccount(int accNo, string name, double bal, double rate)
        : BankAccount(accNo, name, bal), interestRate(rate) {}

    void calculateInterest() override {
        double interest = balance * (interestRate / 100.0);
        cout << "Interest Earned: ?" << interest << endl;
    }
};

class CheckingAccount : public BankAccount {
    double overdraftLimit;

public:
    CheckingAccount(int accNo, string name, double bal, double limit)
        : BankAccount(accNo, name, bal), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            cout << "Withdrawn ?" << amount << " with overdraft.\n";
        } else {
            cout << "Exceeds overdraft limit.\n";
        }
    }

    void checkOverdraft() const {
        cout << "Overdraft limit: ?" << overdraftLimit << endl;
    }
};

class FixedDepositAccount : public BankAccount {
    int term; 
    double interestRate;

public:
    FixedDepositAccount(int accNo, string name, double bal, int t, double rate)
        : BankAccount(accNo, name, bal), term(t), interestRate(rate) {}

    void calculateInterest() override {
        double interest = balance * (interestRate / 100.0) * (term / 12.0);
        cout << "FD Interest for " << term << " months: ?" << interest << endl;
    }
};

void showMenu() {
    cout << "\n--- Banking Menu ---\n";
    cout << "1. Display Account Info\n";
    cout << "2. Deposit\n";
    cout << "3. Withdraw\n";
    cout << "4. Calculate Interest\n";
    cout << "5. Exit\n";
    cout << "Choose option: ";
}

int main() {
    vector<unique_ptr<BankAccount>> accounts;

    accounts.push_back(make_unique<SavingsAccount>(1001, "yug", 5000, 4.5));
    accounts.push_back(make_unique<CheckingAccount>(1002, "Priya", 3000, 2000));
    accounts.push_back(make_unique<FixedDepositAccount>(1003, "Aman", 10000, 12, 6.5));

    int choice, index;
    double amount;

    do {
        cout << "\nAvailable Accounts:\n";
        for (size_t i = 0; i < accounts.size(); i++) {
            cout << i + 1 << ". " << typeid(*accounts[i]).name() << endl;
        }

        cout << "Select account index (1-" << accounts.size() << "): ";
        cin >> index;
        if (index < 1 || index > accounts.size()) break;

        BankAccount* acc = accounts[index - 1].get();

        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                acc->displayAccountInfo();
                break;
            case 2:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                acc->deposit(amount);
                break;
            case 3:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                acc->withdraw(amount);
                break;
            case 4:
                acc->calculateInterest();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option.\n";
        }

    } while (choice != 5);

   
}

/*
input:
Available Accounts:
1. 14SavingsAccount
2. 15CheckingAccount
3. 19FixedDepositAccount
Select account index (1-3): 1

--- Banking Menu ---
1. Display Account Info
2. Deposit
3. Withdraw
4. Calculate Interest
5. Exit
Choose option: 1

output:
Account No: 1001
Name: yug
Balance: ?5000
*/
