#include <iostream>
using namespace std;
class Box1{
private:
    int length;
public:
    Box1(int l){
        length=l;
    }
    friend void displayLength(Box1 b);
};
void displayLength(Box1 b){
    cout << "Length of Box1: "<<b.length<<endl;
}
int main(){
    Box1 b1(30);
    displayLength(b1);
    return 0;
}