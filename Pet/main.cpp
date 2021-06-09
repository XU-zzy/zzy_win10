#include "Pet.h"
#include "Animal.h"
#include "Display.h"
#include<iostream>

int main(){
    
    Animal pet;

    Display dis(pet);
    dis.Display_Main_Menu();

    std::cout << "感谢使用"  << std::endl;

    return 0;
}