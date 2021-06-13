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
    
    int Display_Main_Menu();            //显示主菜单
    int Display_Insert();               //添加宠物信息
    int Display_Delete();               //删除宠物信息
    int Display_Rwrite();               //修改宠物信息
    int Display_Search();               //查找宠物信息
    int Display_All_Mes();              //显示所有宠物信息
    int Display_Save_File();            //保存文件
    int Display_Read_File();            //读取文件
    int Display_Pet_Mes(Pet &pet);      //显示输入的宠物信息
};

#endif