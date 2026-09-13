#include<iostream>
using namespace std;

class bankAccount{
    private:
    string accountNumber;
    string accountHolder;
    double balance;

    public:
    bankAccount(string An, string aH, double b){
        accountNumber = An;
        accountHolder = aH;
        balance = b;
    }
    void accountDetails(){
        cout<<"account number: "<<accountNumber<<endl;
        cout<<"account holder: "<<accountHolder<<endl;
        cout<<"bank balance: "<<balance<<endl;
    }
};
int main(){
    string An, Ah;
    double b;

    cout<<"enter account number: ";
    cin>>An;

    cout<<"enter account holder name: ";
    cin>>Ah;

    cout<<"enter bank balance: ";
    cin>>b;

    bankAccount acc(An, Ah, b);
    cout<<"\n account details: "<<endl;
    acc.accountDetails();
    return 0;
}