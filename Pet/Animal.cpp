#include "Animal.h"
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
    if(flag == FIND_PET_EMPTY || flag == FIND_PET_SUCCE){  //为空或找到，添加
        Pet_data.push_back(pt);
        return INSERT_PET_SUCCE;
    }else if(flag == FIND_PET_FAIL){      //没找到
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
            }
        }
        return DELETE_PET_SUCCE;
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
    Pet pt;
    return pt;
}