#include<iostream>
using namespace std;
class Employee{
    private:
    string name;
    int salary;
    public:
    void inputEmployee(){
        cout<<"Enter the name: ";
        cin>>name;
        cout<<"Enterthe salary: ";
        cin>>salary;
    }
    void displayEmployee(){
        cout<<"Name: "<<name<<endl;
        cout<<"Salary: "<<salary<<endl;
    }
};
class Developer:public Employee{
    private:
    string ProgrammingLanguage;
    public:
    void inputDeveloper(){
        inputEmployee();
        cout<<"Enter programming language: ";
        cin>>ProgrammingLanguage;
    }
    void displayDeveloper(){
        displayEmployee();
        cout<<"Programming Language: "<<ProgrammingLanguage<<endl;
    }
};
class Designer: public Employee{
    private:
    string design_tool;
    public:
    void inputDesigner(){
        inputEmployee();
        cout<<"Enter the design tool: ";
        cin>>design_tool;
    }
    void displayDesigner(){
        displayEmployee();
        cout<<"Designing Tool: "<<design_tool<<endl;
    }
};
int main(){
    Developer dev;
    Designer des;
    cout<<"\nDeveloper details: "<<endl;
    dev.inputDeveloper();
    dev.displayDeveloper();
    cout<<"\nDesignerr details: "<<endl;
    des.inputDesigner();
    des.displayDesigner();
    return 0;
}