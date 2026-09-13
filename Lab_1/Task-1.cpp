#include <iostream>
using namespace std;

struct Student{
    string first_Name;
    string last_Name;
    int roll_Number;
    float marks;

    void displayStudentInfo(){
        cout<<"Full Name: "<<first_Name<<" "<<last_Name<<endl;
        cout<<"Roll Number: "<<roll_Number<<endl;
        cout<<"Marks: " <<marks<<endl;
    }
};

int main(){   
    Student s1;
    s1.first_Name = "Hassan";
    s1.last_Name = "Ali";
    s1.roll_Number = 02;
    s1.marks = 94;
    s1.displayStudentInfo();
    return 0;
}