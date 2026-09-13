#include <iostream>
using namespace std;
template<typename T>
class Calculator{
private:
    T a, b;
public:
    Calculator(T x, T y){
        a=x;
        b=y;
    }
    T add(){
        return a+b;
    }
    T subtract(){
        return a-b;
    }
    T multiply(){
        return a*b;
    }
};
int main(){
    Calculator<int> c1(10, 5);

    cout<<"Int add: "<< c1.add()<<endl;
    cout<<"Int subtract: "<<c1.subtract()<<endl;
    cout<<"Int multiply: "<<c1.multiply()<<endl;

    Calculator<double>c2(4.9, 2.8);

    cout<<"Double Add: "<<c2.add()<<endl;
    cout<<"Double Subtract: "<<c2.subtract()<<endl;
    cout<<"Double Multiply: "<<c2.multiply()<<endl;
    return 0;
}