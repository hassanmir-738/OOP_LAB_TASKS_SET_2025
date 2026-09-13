#include <iostream>
using namespace std;
class Product{
protected:
    string name;
    double price;
public:
    Product(string n,double p){
        name=n;
        price=p;
    }
    void display(){
        cout<<"Product Name: "<<name<<endl;
        cout<<"Price: PKR" <<price<<endl;
    }
};
class Electronics:public Product{
private:
    string warranty;
public:
    Electronics(string n,double p,string w):Product(n, p){
        warranty= w;
    }
    void display(){
        Product::display();
        cout<<"Warranty: "<<warranty<<" Years"<< endl;
    }
};
int main(){
    cout<<"Welcome to  online shopping system."<<endl;
    Electronics computer("Laptop12", 909.56, "5");
    cout<<"Product Details"<<endl;
    computer.display();
    return 0;
}