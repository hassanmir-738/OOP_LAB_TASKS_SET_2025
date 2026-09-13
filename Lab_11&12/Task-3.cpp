#include <iostream>
using namespace std;
class BankAccount{
private:
    string accountHolderName;
    double balance;

public:
    static int totalAccounts;
    BankAccount(string name, double balnc){
        accountHolderName=name;
        balance=balnc;
        totalAccounts++;
    }
    void display(){
        cout<<"Account Holder: "<<accountHolderName<<endl;
        cout<<"Balance: "<<balance<<endl;
        cout<<endl;
    }
};
int BankAccount::totalAccounts=0;
int main(){
    BankAccount ac1("Shohaib", 5000);
    BankAccount ac2("Hassan", 2000);
    BankAccount ac3("fahad", 80000);

    ac1.display();
    ac2.display();
    ac3.display();
    cout<<"Total Bank Accounts Created: "<<BankAccount::totalAccounts<<endl;
    return 0;
}