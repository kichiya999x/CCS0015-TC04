#include <string>

using namespace std;

class Customer {
private:
    int accountNumber;
    string name;
    double balance;

public:
    Customer(int accountNumber, string name, double balance);
    void deposit(double amount);
    void withdraw(double amount);
    double checkBalance();
    void displayInfo();
};


#include <iostream>
#include <queue>
#include "Bank.h"

// Implement the Customer class
Customer::Customer(int accountNumber, string name, double balance) {
    this->accountNumber = accountNumber;
    this->name = name;
    this->balance = balance;
}

void Customer::deposit(double amount) {
    balance += amount;
}

void Customer::withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
    } else {
        cout << "Insufficient balance.\n";
    }
}


double Customer::checkBalance() {
    return balance;
}

void Customer::displayInfo() {
    cout << "Account Number: " << accountNumber << "\n";
    cout << "Name: " << name << "\n";
    cout << "Balance: " << balance << "\n";
}

// Main program
int main() {
    queue<Customer> bankQueue;

    // Display menu and perform operations
    // ...

    return 0;
}
