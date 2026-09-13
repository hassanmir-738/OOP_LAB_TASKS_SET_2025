#include<iostream>
using namespace std;

class Rectangle{
    private:
    float length;
    float width;

    public:
    Rectangle(){
        length = 1.0;
        width = 1.0;
    }
    Rectangle(float l, float w){
        length = l;
        width = w;
    } 
    Rectangle(float sq){
        length = sq;
        width = sq;
    }
    float area(){
        return length * width;
    }

    void display(){
        cout<<"lenght: "<<length<<endl;
        cout<<"width: "<<width<<endl;
        cout<<"area: "<<area()<<endl;
    }
};
int main(){
    Rectangle R1;
    Rectangle R2(5,3); 
    Rectangle R3(4);

    cout <<"\nRectangle R1: "<<endl;
    R1.display();

    cout <<"\nRectangle R2: "<<endl;
    R2.display();

    cout<<"\nRectangle R3 square: "<<endl;
    R3.display();

    return 0;
}