#include<iostream>
using namespace std;
class Voter{
    public:
    string name;
    int age;

    void getData();
    bool isEligible();
};
 void Voter::getData(){
    cout<<"Enter Name :";
    cin>>name;
    cout<<"Enter age :";
    cin>>age;
 }
  bool Voter::isEligible(){
    if(age>=18)
    return true;
    else 
    return false;
  }

  int main(){
    Voter v;
    v.getData();
    if (v.isEligible())
        cout<<"You are Eligible for casting vote"<<endl;
    else
        cout<<"You are not Eligible for casting vote";
        return 0;
  }