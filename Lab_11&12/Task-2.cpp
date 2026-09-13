#include <iostream>
using namespace std;
class Distance{
private:
    int feet;
    int inches;
public:
    Distance(int f, int i){
        feet=f;
        inches=i;
    }
    friend void adddistance(Distance d1, Distance d2);
};
void adddistance(Distance d1, Distance d2){
    int totalfeet= d1.feet+d2.feet;
    int totalinches = d1.inches+d2.inches;
    if (totalinches >= 12){
        totalfeet +=totalinches/12;
        totalinches =totalinches%12;
    }
    cout<<"Total distance: "<<totalfeet<< " feet "<<totalinches<<"inches"<<endl;
}
int main(){
    Distance d1(4, 1);
    Distance d2(2,8);
    adddistance(d1, d2);
    return 0;
}