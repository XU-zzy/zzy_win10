#pragma once 
#ifndef _ANIMAL_H_
#define _ANIMAL_H_
#include "Pet.h"
#define     FIND_PET_EMPTY      0       //宠物数组为空
#define     FIND_PET_SUCCE      1       //成功查找到
#define     FIND_PET_FAIL      -1       //未成功查找到
#define     FIND_PET_ERROR     -2       //查找错误

#define     INSERT_PET_SUCCE    1       //添加成功
#define     INSERT_PET_FAIL    -1       //添加失败
#define     INSERT_PET_ERROR   -2       //添加错误

#define     DELETE_PET_SUCCE    1       //删除成功    
#define     DELETE_PET_FAIL    -1       //删除失败
#define     DELETE_PET_ERROR   -2       //删除错误

#define     RWRITE_PET_SUCCE    1       //修改成功
#define     RWRITE_PET_FAIL    -1       //修改失败
#define     RWRITE_PET_ERROR   -2       //修改错误

// std::vector<Pet>Pet_data;

class Animal:public Pet
{
private:
    // Pet *M_pt;
public:
    Animal();
    // Animal(Pet pt):M_pt(&pt){}
    ~Animal();
 
    int  Insert_Pet(Pet& pt);                 //添加宠物
    int  Delete_Pet(Pet& pt);                 //删除宠物
    int  Rwrite_Pet(Pet& pt);                 //修改宠物信息
    int  Find_Pet(Pet &pt);                   
    Pet& FindMs_Pet(std::string number);      //查找宠物信息
    std::vector<Pet>&  All_me_Pet();          //获取所有宠物信息
};

#endif