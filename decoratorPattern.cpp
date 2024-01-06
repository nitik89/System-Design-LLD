#include<iostream>
using namespace std;

class Coffee{
    public:
    virtual double cost()=0;
};
class BaseCoffee:public Coffee{
public:
double cost(){
return 10.0;
}
};

class MilkCoffee:public Coffee{
    BaseCoffee* obj;
    public:
    MilkCoffee(BaseCoffee* obj){
        this->obj=obj;
    }

    double cost(){
        return obj->cost()+5.0;
    }
};
class ColdCoffee:public Coffee{
    MilkCoffee* obj;
    public:
    ColdCoffee(MilkCoffee* obj){
        this->obj=obj;
    }
    double cost(){
        return obj->cost()+10.0;
    }
};
int main(){
    BaseCoffee cf;
    MilkCoffee milkcoffee(&cf);
    ColdCoffee ccf(&milkcoffee);
    cout<<ccf.cost();
    return 0;

}