#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ofstream file("students.txt");

    file<<"Name: Hassan"<<endl;
    file<<"Roll No: 2025-SET-02"<<endl;

    file<<"Name: hadi"<<endl;
    file<<"Roll No: 2025-SET-04"<<endl;

    file<<"Name: Faizan"<<endl;
    file<<"Roll No: 2025-SET-40"<<endl;
    file.close();

    ifstream readFile("students.txt");
    string line;
    cout<<"Student Details:"<<endl;
    while (getline(readFile, line)){
        cout<<line<<endl;
    }
    readFile.close();
    return 0;
}