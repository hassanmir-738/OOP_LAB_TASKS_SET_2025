#include <iostream>
using namespace std;
class Hospitalstaf{
protected:
    string staffName;
public:
    Hospitalstaf(string name){
        staffName=name;
    }
    virtual void performDuty()=0;
};
class Doctor :public Hospitalstaf{
public:
    Doctor(string name):Hospitalstaf(name){}
    void performDuty(){
        cout<<staffName <<"doctor is treating patients." << endl;
    }
};
class Nurse:public Hospitalstaf{
public:
    Nurse(string name):Hospitalstaf(name){}
    void performDuty(){
        cout<<staffName<<"Nurse taking care of pateints."<<endl;
    }
};
class Receptionist:public Hospitalstaf{
public:
    Receptionist(string name):Hospitalstaf(name){}
    void performDuty(){
        cout<<staffName<<"Reciptionist is managing appointments.."<<endl;
    }
};
int main(){
    Doctor d1("Farhad");
    Nurse n1("Haseeb");
    Receptionist r1("mohsin");

    d1.performDuty();
    n1.performDuty();
    r1.performDuty();
    return 0;
}