#pragma once
#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include"Pet.h"
#include "Animal.h"

class Display:public Pet
{
private:
    Animal pet;
public:
    Display(){};
    Display(Animal &pt):pet(pt){}
    ~Display(){};
    
    int Display_Main_Menu();
    int Display_Insert();
    int Display_Delete();
    int Display_Rwrite();
    int Display_Search();
    int Display_Save_File();
    int Display_Read_File();
};

// extern Display::Display();

// extern Display::~Display();
#endif