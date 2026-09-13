#include <iostream>
using namespace std;
class Shape{
public:
    virtual double area(){
    return 0;
    }
};
class Rectangle:public Shape{
public:
    double length, width;
    Rectangle(double l, double w){
        length= l;
        width= w;
    }
    double area(){
        return length*width;
    }
};
class Circle:public Shape{
public:
    double radius;
    Circle(double r){
        radius= r;
    }
    double area(){
        return 3.142*radius*radius;
    }
};
int main(){
    Shape *s1;

    Rectangle r1(5, 2);
    Circle c1(7);
    s1= &r1;
    cout<<"Area of rectangle: "<<s1->area()<<endl;

    s1= &c1;
    cout<<"Area of circle: "<<s1->area()<<endl;
    return 0;
}