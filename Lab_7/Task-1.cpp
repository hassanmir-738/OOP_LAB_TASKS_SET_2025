#include <iostream>
using namespace std;

class Display {
private:
    double lastResult;
public:
    Display(){
        lastResult= 0;
    }
    void show(double result){
        lastResult =result;
        cout<<"result: "<<result<<endl;
    }
    double getLastResult(){
        return lastResult;
    }
};
class Calculator{
private:
    Display display;
public:
    void add(double a, double b){
        double result=a+b;
        display.show(result);
    }
    void multiply(double a,double b){
        double result =a*b;
        display.show(result);
    }
    void showLastResult(){
        cout <<"Last Result: "<<display.getLastResult()<<endl;
    }
};
int main(){
    Calculator calc1;
    calc1.add(4, 4);
    calc1.multiply(2, 9);
    calc1.showLastResult();
    return 0;
}