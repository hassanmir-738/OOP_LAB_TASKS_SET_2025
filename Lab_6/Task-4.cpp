#include <iostream>
using namespace std;
class Device{
protected:
    string *deviceName;
    int *deviceID;
public:
    Device(string n, int id){
        deviceName= new string(n);
        deviceID= new int(id);
    }
    virtual ~Device(){
        cout<<"device constructor is called."<<endl;
        delete deviceName;
        delete deviceID;
    }
};
class Sensor:public Device{
private:
    string *sensorType;
    double *sensorValue;
public:
    Sensor(string n, int id, string type, double value): Device(n, id){
        sensorType= new string(type);
        sensorValue= new double(value);
    }
    ~Sensor(){
        cout<<"sensor destructor called."<<endl;
        delete sensorType;
        delete sensorValue;
    }
};

int main(){
    Device *obj = new Sensor("deviceA", 309, "temperature", 38.5);
    delete obj;
    return 0;
}