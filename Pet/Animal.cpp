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

//�������г���
std::vector<Pet>&  Animal::All_me_Pet(){
    return Pet_data;
}

//���ҳ����Ƿ����
int Animal::Find_Pet(Pet &pt){
    //Ϊ��
    if(Pet_data.empty()){
        return FIND_PET_EMPTY;
    }

    //���Ҵ���
    // std::vector<Animal>::iterator it;
    for(auto it = Pet_data.begin();it != Pet_data.end();++it){
        if((*it) == pt){
            return FIND_PET_SUCCE;    
        }
    }

    //������
    return FIND_PET_FAIL;
}

//��ӳ��ﺯ��
int Animal::Insert_Pet(Pet& pt){
    int flag = Find_Pet(pt);
    Pet t = pt;
    if(flag == FIND_PET_EMPTY || flag == FIND_PET_FAIL){  //Ϊ�ջ�û�ҵ������
        Pet_data.push_back(t);
        return INSERT_PET_SUCCE;
    }else if(flag == FIND_PET_SUCCE){      //�ҵ��ˣ��ظ�
        return INSERT_PET_FAIL;
    }
    return INSERT_PET_ERROR;
}

//ɾ�����ﺯ��
int Animal::Delete_Pet(Pet& pt){
    int flag = Find_Pet(pt);
    if(flag == FIND_PET_SUCCE){     //�ҵ���
        for(auto it = Pet_data.begin();it != Pet_data.end();++it){
            if((*it) == pt){
                Pet_data.erase(it);
                return DELETE_PET_SUCCE;
            }
        }
        // return DELETE_PET_SUCCE;
    }else if(flag == FIND_PET_EMPTY){   //��
        std::cout << "vector empty!" << std::endl;
        return DELETE_PET_FAIL;
    }else if(flag == FIND_PET_FAIL){    //û�ҵ�
        std::cout << "This pet is not in vector!" << std::endl;
        return DELETE_PET_FAIL;
    }
    return DELETE_PET_ERROR;
}

//�޸ĳ�����Ϣ
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

//���ҳ�����Ϣ
Pet& Animal::FindMs_Pet(std::string number){
    for(auto it = Pet_data.begin();it != Pet_data.end();++it){
        if((*it).P_number == number){
            return *it;
        }
    }
    static Pet t("-1");
    return t;
}
