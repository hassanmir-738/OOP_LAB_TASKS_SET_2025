#include <iostream>
using namespace std;
class Distance{
private:
    int feet,inches;
public:
    Distance(int f,int i){
        feet = f;
        inches = i;
    }
    bool operator==(Distance d){
        if (feet == d.feet && inches==d.inches)
            return true;
        else
            return false;
    }
};
int main(){
    Distance d1(3, 7);
    Distance d2(2, 12);

    if(d1==d2)
        cout<<"Both distances are equal"<<endl;
    else
        cout<<"Both distances are not equal"<<endl;
    return 0;
}