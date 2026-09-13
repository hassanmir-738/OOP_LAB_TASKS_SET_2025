#include<iostream>
using namespace std;
class Printer{
    public:
    void print(){
        cout<<"printing document."<<endl;
    }
};
class Scanner{
    public:
    void scan(){
        cout<<"scanning document"<<endl;
    }
};
class Photocoppier:public Printer,public Scanner{
    public:
      void photocopy(){
        cout<<"Photocopying process started."<<endl;
        print();
        scan();
      }
};
int main(){
   Photocoppier pc1;
   pc1.photocopy();
   pc1.print();
   pc1.scan();
   return 0;
}