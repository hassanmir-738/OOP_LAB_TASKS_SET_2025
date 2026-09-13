#include <iostream>
using namespace std;
class Employee{
private:
    int employeID;
    string employeName;
public:
    static string companyName;
    Employee(int id, string name){
        employeID=id;
        employeName=name;
    }
    void display(){
        cout<<"Employee ID: "<<employeID<<endl;
        cout<<"Employee Name: "<<employeName<<endl;
        cout<<"Company Name: "<<companyName<<endl;
        cout<<endl;
    }
    static void displayCompanyInfo(){
        cout<<"Company Name: "<<companyName<<endl;
    }
};
string Employee::companyName = "Software house";
int main(){
    Employee emp1(1001,"Faizan");
    Employee emp2(1002,"Soban");
    Employee emp3(1003,"Ali");

    emp1.display();
    emp2.display();
    emp3.display();

    Employee::displayCompanyInfo();
    return 0;
}