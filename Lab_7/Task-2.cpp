#include <iostream>
using namespace std;
class Calculator{
public:
    double add(double a, double b){
        return a+b;
    }
    double multiply(double a, double b){
        return a*b;
    }
};
class Student{
private:
    string name;
    Calculator *calculator1;
public:
    Student(string n, Calculator *calc){
        name =n;
        calculator1 =calc;
    }

    void performAddition(double a,double b){
        double result=calculator1->add(a, b);
        cout<<name<<"get addition result: "<<result<<endl;
    }
    void performMultiplication(double a, double b){
        double result=calculator1->multiply(a, b);
        cout<<name<<"get multiplication result: "<<result<<endl;
    }
};
int main(){
    Calculator sharedCalculator1;
    Student std1("absar", &sharedCalculator1);
    Student std2("hadi", &sharedCalculator1);

    std1.performAddition(2, 9);
    std2.performMultiplication(4, 7);
    return 0;
}