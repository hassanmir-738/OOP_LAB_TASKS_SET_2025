#include <iostream>
using namespace std;
template<typename T>
T findmin(T a, T b){
    return (a<b)? a:b;
}
int main(){
    cout<<"Integer "<<findmin(6,17)<<endl;
    cout<<"Double "<<findmin(8.5,9.3)<<endl;
    cout<<"Character "<<findmin('A','Z')<<endl;
    return 0;
}