#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream file("notes.txt");
    string line;
    int lineCount=0;
    while (getline(file, line)){
        lineCount++;
    }
    file.close();
    cout << "Total numbr of lines are: "<<lineCount<<endl;
    return 0;
}