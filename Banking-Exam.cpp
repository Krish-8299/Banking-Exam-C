#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string name;
    int accountNumber;
    double balance;

public:
    BankAccount(string accName, int accNumber, double initialBalance) {
        name = accName;
        accountNumber = accNumber;
        balance = initialBalance;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "₹" << amount << " deposited successfully.\n";
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!\n";
        } else {
            balance -= amount;
            cout << "₹" << amount << " withdrawn successfully.\n";
        }
    }

    void display() {
        cout << "\nAccount Holder: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: ₹" << balance << "\n";
    }
};

int main() {
    string name;
    int accNo;
    double initialBalance;

    cout << "Welcome to Simple Bank System\n";
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter account number: ";
    cin >> accNo;
    cout << "Enter initial balance: ₹";
    cin >> initialBalance;

    BankAccount myAccount(name, accNo, initialBalance);

    int choice;
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Check Balance\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                double amount;
                cout << "Enter amount to deposit: ₹";
                cin >> amount;
                myAccount.deposit(amount);
                break;
            }
            case 2: {
                double amount;
                cout << "Enter amount to withdraw: ₹";
                cin >> amount;
                myAccount.withdraw(amount);
                break;
            }
            case 3:
                myAccount.display();
                break;
            case 4:
                cout << "Thank you for banking with us!\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}