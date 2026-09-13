#include<iostream>
#include<string>
using namespace std;

class Product{
    private:
    string name;
    double price = 0;
    int quantity = 0;

    public:
    void setName(string n){
        if(n==""){
            cout<<"error! name cannot be empty";
        }
        else{
            name = n;
        }
    }
    void setPrice(double p){
        if(p <= 0){
            cout<<"error. Price must be greater than zero."<<endl;
        }
        else{
            price = p;
        }
    }
    void setQuantity(int q){
        if(q<0){
            cout<<"error! quantity cannot be in negative."<<endl;
        }
        else{
            quantity = q;
        }
    }
    string getName(){
        return name;
    }
    double getPrice(){
        return price;
    }
    int getQuantity(){
        return quantity;
    }
};
int main(){
    Product p;

    //now we use valid values
    // p.setName("");
    // p.setPrice(-34);
    // p.setQuantity(-3);

    // now we use valid values
    p.setName("book1");
    p.setPrice(4000);
    p.setQuantity(9);

    cout<<"\nProduct: "<<p.getName()<<endl;
    cout<<"Pkr: "<<p.getPrice()<<endl;
    cout<<"Quantity: "<<p.getQuantity()<<endl;
    return 0;
}