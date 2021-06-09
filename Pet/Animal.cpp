#include "Animal.h"

std::vector<Pet>Pet_data;

Animal::Animal()
{ 
    // this->M_pt = new Pet;
}

Animal::~Animal()
{
    // delete M_pt;
}

//查找所有宠物
std::vector<Pet>&  Animal::All_me_Pet(){
    return Pet_data;
}

//查找宠物是否存在
int Animal::Find_Pet(Pet &pt){
    //为空
    if(Pet_data.empty()){
        return FIND_PET_EMPTY;
    }

    //查找存在
    // std::vector<Animal>::iterator it;
    for(auto it = Pet_data.begin();it != Pet_data.end();++it){
        if((*it) == pt){
            return FIND_PET_SUCCE;    
        }
    }

    //不存在
    return FIND_PET_FAIL;
}

//添加宠物函数
int Animal::Insert_Pet(Pet& pt){
    int flag = Find_Pet(pt);
    Pet t = pt;
    if(flag == FIND_PET_EMPTY || flag == FIND_PET_FAIL){  //为空或没找到，添加
        Pet_data.push_back(t);
        return INSERT_PET_SUCCE;
    }else if(flag == FIND_PET_SUCCE){      //找到了，重复
        return INSERT_PET_FAIL;
    }
    return INSERT_PET_ERROR;
}

//删除宠物函数
int Animal::Delete_Pet(Pet& pt){
    int flag = Find_Pet(pt);
    if(flag == FIND_PET_SUCCE){     //找到了
        for(auto it = Pet_data.begin();it != Pet_data.end();++it){
            if((*it) == pt){
                Pet_data.erase(it);
                return DELETE_PET_SUCCE;
            }
        }
        // return DELETE_PET_SUCCE;
    }else if(flag == FIND_PET_EMPTY){   //空
        std::cout << "vector empty!" << std::endl;
        return DELETE_PET_FAIL;
    }else if(flag == FIND_PET_FAIL){    //没找到
        std::cout << "This pet is not in vector!" << std::endl;
        return DELETE_PET_FAIL;
    }
    return DELETE_PET_ERROR;
}

//修改宠物信息
int Animal::Rwrite_Pet(Pet& pt){
    if(Find_Pet(pt) != FIND_PET_SUCCE){
        std::cout << "This pet is not in vector!" << std::endl;
        return RWRITE_PET_FAIL;
    }
    for(auto it = Pet_data.begin();it != Pet_data.end();++it){
        if((*it) == pt){
            (*it) = pt;
            return RWRITE_PET_SUCCE;
        }
    }
    return RWRITE_PET_ERROR;
}

//查找宠物信息
Pet& Animal::FindMs_Pet(std::string number){
    for(auto it = Pet_data.begin();it != Pet_data.end();++it){
        if((*it).P_number == number){
            return *it;
        }
    }
    static Pet t("-1");
    return t;
}