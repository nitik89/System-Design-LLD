#include<iostream>
using namespace std;

class DriveStrategy{
    public:
virtual void drive() = 0;
};

class SportyDrive :public DriveStrategy{
    public:
   void drive()  {
        cout << "Sporty driving mode" << endl;
    }
};
class HuntDrive :public DriveStrategy{
    public:
   void drive()  {
        cout << "Hunt driving mode" << endl;
    }
};
class Vehicle{
    public:
    DriveStrategy* myobj;
    Vehicle(DriveStrategy* obj){
        myobj=obj;
    }
    void driveVehicle(){
        if(myobj){
        myobj->drive();
        }
    }
};
class Car:public Vehicle{
    public:
Car():Vehicle(new SportyDrive()){

}
};
class Hunter:public Vehicle{
    public:
    Hunter():Vehicle(new HuntDrive()){

    }

};
int main(){
    
    Car myObj;
    myObj.driveVehicle();
   
}