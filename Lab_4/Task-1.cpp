#include<iostream>
using namespace std;

class Employee{
    private:
    int id;
    string name;
    float salary;

    public:
    Employee(){
        id = 0;
        name = "not asigned";
        salary = 0.0;
    }
    void displayDetails(){
        cout<<"employee id: "<<id<<endl;
        cout<<"employee name: "<<name<<endl;
        cout<<"employee salary: "<<salary<<endl;
    }
};

int main(){
    Employee e1;
    cout<<"Employee Details: "<<endl;
    e1.displayDetails();
    return 0;
}