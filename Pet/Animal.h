#pragma once 
#ifndef _ANIMAL_H_
#define _ANIMAL_H_
#include "Pet.h"
#define     FIND_PET_EMPTY      0       //��������Ϊ��
#define     FIND_PET_SUCCE      1       //�ɹ����ҵ�
#define     FIND_PET_FAIL      -1       //δ�ɹ����ҵ�
#define     FIND_PET_ERROR     -2       //���Ҵ���

#define     INSERT_PET_SUCCE    1       //��ӳɹ�
#define     INSERT_PET_FAIL    -1       //���ʧ��
#define     INSERT_PET_ERROR   -2       //��Ӵ���

#define     DELETE_PET_SUCCE    1       //ɾ���ɹ�    
#define     DELETE_PET_FAIL    -1       //ɾ��ʧ��
#define     DELETE_PET_ERROR   -2       //ɾ������

#define     RWRITE_PET_SUCCE    1       //�޸ĳɹ�
#define     RWRITE_PET_FAIL    -1       //�޸�ʧ��
#define     RWRITE_PET_ERROR   -2       //�޸Ĵ���

// std::vector<Pet>Pet_data;

class Animal:public Pet
{
private:
    // Pet *M_pt;
public:
    Animal();
    // Animal(Pet pt):M_pt(&pt){}
    ~Animal();
 
    int  Insert_Pet(Pet& pt);                 //��ӳ���
    int  Delete_Pet(Pet& pt);                 //ɾ������
    int  Rwrite_Pet(Pet& pt);                 //�޸ĳ�����Ϣ
    int  Find_Pet(Pet &pt);                   
    Pet& FindMs_Pet(std::string number);      //���ҳ�����Ϣ
    std::vector<Pet>&  All_me_Pet();          //��ȡ���г�����Ϣ
};


#endif
