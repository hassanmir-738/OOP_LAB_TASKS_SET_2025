#include <iostream>
using namespace std;
template <typename T>
void printtwice(T b){
    cout<<b<<endl;
    cout<<b<<endl;
}
int main(){
    printtwice(80);
    printtwice(2.5);
    printtwice("Kashmir");
    return 0;
}