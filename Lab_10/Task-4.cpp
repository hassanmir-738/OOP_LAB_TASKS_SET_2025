#include <iostream>
#include <fstream>
using namespace std;
int main(){
    ifstream sourceFile("notes.txt");
    ofstream destinationFile("copy.txt");
    string line;
    while (getline(sourceFile, line)){
        destinationFile<<line<<endl;
    }
    sourceFile.close();
    destinationFile.close();
    cout << "File is Copied Successfully."<<endl;
    return 0;
}