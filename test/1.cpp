#include<iostream>

class Base{
public:
    Base(){}
    virtual void fun1() {    std::cout << "Base" << std::endl;} 

};


class Dervied: public Base{
    virtual void fun1() {   std::cout << "Dervied" << std::endl;}
};

int main(){
    Base *P = new Dervied;

    P->fun1();
    return 0;
}