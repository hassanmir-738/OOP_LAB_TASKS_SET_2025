#include <iostream>
#include <string>
using namespace std;
class Product{
protected:
    string name;
    double price;
public:
    Product(string n, double p){
        name= n;
        price= p;
    }
    void display(){
        cout<<"Name  : "<<name<<endl;
        cout<<"Price  : PKR"<<price<<endl;
    }
};
class Electronics :public Product{
private:
    int warantyYears;

public:
    Electronics(string n, double p, int wY) : Product(n, p){
        warantyYears = wY;
    }

    void display(){
        Product::display();
        cout<<"Warranty: "<< warantyYears<<" years" <<endl;
    }
};
int main(){
    Electronics item("samsung A16", 635.90, 4);
    item.display();
    return 0;
}