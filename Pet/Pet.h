#pragma once 
#ifndef _PET_H_
#define _PET_H_
// #include "main.h"
#include<iostream>
#include<fstream>
#include<cstring>
#include<list>
#include<vector>
#include<string>

class Pet
{
public:
    std::string P_number;   //���
    std::string P_name;     //����
    std::string P_weight;   //����
    std::string P_age;      //����
    std::string P_kind;     //���
    std::string P_price;    //�۸�
    std::string P_character;//�Ը�
    std::string P_state;    //״̬���Ƿ�������
public:
    Pet(){};
    Pet(std::string number):P_number(number){}
    Pet(std::string number,std::string name,std::string weight,std::string age,std::string kind,std::string price,std::string character,std::string state);
    //���ƹ���
    Pet(const Pet &other);
    //��ֵ������
    Pet& operator = (const Pet &other){
        this->P_number = other.P_number;
        this->P_name = other.P_name;
        this->P_weight = other.P_weight;
        this->P_age = other.P_age;
        this->P_kind = other.P_kind;
        this->P_price = other.P_price;
        this->P_character = other.P_character;
        this->P_state = other.P_state;
        return *this;
    }
    //���������
    friend std::ostream & operator << (std::ostream& os,const Pet& pt);
    friend std::istream & operator >> (std::istream& is,Pet& pt);
    bool operator == (Pet& pt);
    ~Pet(){};
};
#endif
