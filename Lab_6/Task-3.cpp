#include <iostream>
using namespace std;
class File{
public:
    File(){
        cout<<"file is opened"<<endl;
    }
    ~File(){
        cout << "file is closed" <<endl;
    }
};
class Textfile:public File{
public:
    Textfile(){
        cout<<"TextFile is opened" <<endl;
    }
    ~Textfile(){
        cout<<"TextFile is  closed."<<endl;
    }
};
int main(){
    Textfile t1;
    return 0;
}