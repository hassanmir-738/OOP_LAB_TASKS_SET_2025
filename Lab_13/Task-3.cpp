#include <iostream>
using namespace std;
template<typename T>
class Pair{
private:
    T first, second;
public:
    Pair(T f, T s){
        first=f;
        second=s;
    }
    T getFirst(){
        return first;
    }
    T getSecond(){
        return second;
    }
    void display(){
        cout<<"First: "<<first<<" Second: "<<second<<endl;
    }
};
int main(){
    Pair<int>p1(10,80);
    Pair<double>p2(5.6, 2.3);
    Pair<string>p3("Hassan", "Mir");

    p1.display();
    p2.display();
    p3.display();
    return 0;
}