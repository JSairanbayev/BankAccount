#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

enum Type {
    DEPOSIT,
    WITHDRAWAL
};

class Transaction {
private:

    Type type;
    int amount;

public:
    Transaction(Type t, int a) {
        type = t;
        amount = a;
    }

    Type getType() {
        return type;
    }

    int getAmount(){
    return amount;
    }
};

class Account {
private:
    int balance;
    vector<Transaction> history;

public:
    Account() {
        balance = 0;
    }

    int getBalance() {
        return balance;
    }

    void deposit(int amount) {
        balance += amount;
        history.push_back(Transaction(DEPOSIT, amount));
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(int amount) {
        if (amount > balance) {
            cout << "Not enough money!" << endl;
        }
        else {
            balance -= amount;
            history.push_back(Transaction(WITHDRAWAL, amount));
            cout << "Withdrawn: " << amount << endl;
        }
    }
    void showHistory() {
        if (history.empty()) {
                cout << "No transactions yet." << endl;
            }
            else {
                for (int i = 0; i < history.size(); i++) {
                    if (history[i].getType() == DEPOSIT) {
                        cout << i + 1 << ". +" << history[i].getAmount() << endl;
                    }
                    else {
                        cout << i + 1 << ". - " << history[i].getAmount() << endl;
                    }
                }
            }
        }
    void saveHistory() {
        ofstream fout("history.txt");
        for (int i = 0; i < history.size(); i++) {
            if (history[i].getType() == DEPOSIT) {
                fout << "+ " << history[i].getAmount() << endl;
            }
            else {
                fout << "- " << history[i].getAmount() << endl;
            }
        }
        fout.close();
        cout << "History saved!" << endl;
    }
};

int main()
{
    Account acc;
    int choice;

    while (true) {
        cout << "\n === BankAccount ===" << endl;
        cout << "Balance: " << acc.getBalance() << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. History" << endl;
        cout << "4. Save history" << endl;
        cout << "0. Exit" << endl;
        cout << "Choose: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 1) {
            cout << "Enter amount: ";
            int amount;
            cin >> amount;
            acc.deposit(amount);
        }
        else if (choice == 2) {
            cout << "Enter amount: ";
            int amount;
            cin >> amount;
            acc.withdraw(amount);
        }
        else if (choice == 3) {
            acc.showHistory();
        }
        else if (choice == 4) {
            acc.saveHistory();
        }
        else if (choice == 0) {
            cout << "Bye!" << endl;
            break;
        }
    }

    return 0;
}