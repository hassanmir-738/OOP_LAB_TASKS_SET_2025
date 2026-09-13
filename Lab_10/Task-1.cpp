#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ofstream writeFile("notes.txt");

    writeFile<<"I am studing in BS-Software Engineering."<<endl;
    writeFile<<"Kashmir"<<endl;
    writeFile<<"Revolution"<<endl;
    writeFile.close();

    ifstream readFile("notes.txt");
    string line;
    cout<<"File Contents:"<<endl;
    while(getline(readFile, line)){
        cout<<line<<endl;
    }
    readFile.close();

    ofstream appendFile("notes.txt",ios::app);
    appendFile<<"Name: Hassan Ali Mir"<<endl;
    appendFile<<"Roll No:2025-SET-02"<<endl;
    appendFile.close();
    cout<<"\nData will append successfully."<<endl;
    return 0;
}