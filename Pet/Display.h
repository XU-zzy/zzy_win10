#pragma once
#ifndef _DISPLAY_H_
#define _DISPLAY_H_
#include"Pet.h"
#include "Animal.h"
#define FILE_MAX    256     //文件名最大长度



class Display:public Animal
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
    int Display_All_Mes();
    int Display_Save_File();
    int Display_Read_File();
    int Display_Pet_Mes(Pet &pet);
};

// extern Display::Display();

// extern Display::~Display();
#endif
