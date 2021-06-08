#include "main.h"
#include "Pet.h"

std::vector<Animal>Pet_data;
class Animal:public Pet
{
private:
    Pet *M_pt;
public:
    Animal();
    Animal(Pet pt):M_pt(&pt){}
    ~Animal();

    int  Insert_Pet(Pet& pt);                 //添加宠物
    int  Delete_Pet(Pet& pt);                 //删除宠物
    int  Rwrite_Pet(Pet& pt);                 //修改宠物信息
    int  Find_Pet(Pet &pt);                   
    Pet& FindMs_Pet(std::string number);                 //查找宠物信息
};

Animal::Animal()
{
    this->M_pt = new Pet;
}

Animal::~Animal()
{
    delete M_pt;
}
