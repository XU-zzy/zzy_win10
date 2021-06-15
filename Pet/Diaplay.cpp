#include"Display.h"
#include"Animal.h"
#include"Pet.h"

//��ʾ������Ϣ
int Display::Display_Pet_Mes(Pet &pet){
    std::cout<< "������Ϣ����:"                 << std::endl;
    std::cout << "��ţ� " << pet.P_number      << std::endl;
    std::cout << "���ƣ� " << pet.P_name        << std::endl;
    std::cout << "���أ� " << pet.P_weight      << std::endl;
    std::cout << "���䣺 " << pet.P_age         << std::endl;
    std::cout << "��� " << pet.P_kind        << std::endl;
    std::cout << "�۸� " << pet.P_price       << std::endl;
    std::cout << "�Ը� " << pet.P_character   << std::endl;
    std::cout << "�Ƿ��ѱ������� ";
    if(pet.P_state == "Y"){
        std::cout << "��" <<  std::endl;
    }else{
        std::cout << "��" <<  std::endl;
    }
    return 0;
}

//��ʾ���˵�
int Display::Display_Main_Menu(){
    int choice;
    do{
        std::cout<<std::endl<<"�����ӭ��������̵����ϵͳ�� ��ѡ��˵�:������"<<std::endl;
	    std::cout<<" \t|=========================== |"<<std::endl; 
	    std::cout<<" \t| 1.��ӳ������Ϣ            |"<<std::endl; 
	    std::cout<<" \t| 2.ɾ���������Ϣ            |"<<std::endl;
	    std::cout<<" \t| 3.�޸ĳ������Ϣ            |"<<std::endl;
	    std::cout<<" \t| 4.��ѯ�������Ϣ            |"<<std::endl;
	    std::cout<<" \t| 5.��ѯ���г������Ϣ         |"<<std::endl;
	    std::cout<<" \t| 6.�����ļ�                  |"<<std::endl;
	    std::cout<<" \t| 7.��ȡ�ļ�                  |"<<std::endl;
	    std::cout<<" \t| 8.�˳�ϵͳ                  |"<<std::endl;
	    std::cout<<" \t|=========================== |\n"<<std::endl;
	
        std::cin>>choice;
        switch(choice){
            case 1: {Display_Insert();      continue;}
            case 2: {Display_Delete();      continue;}
            case 3: {Display_Rwrite();      continue;}
            case 4: {Display_Search();      continue;}
            case 5: {Display_All_Mes();     continue;}
            case 6: {Display_Save_File();   continue;}
            case 7: {Display_Read_File();   continue;}
            // case 1: {}
            break;
        }
    }while(choice != 8);   
    
    return 0;
}

// ��ӳ�����Ϣ
int Display::Display_Insert(){
    
        Pet pt;
        std::string choice;

        std::cout << "�������������Ϣ��" << std::endl;
        std::cout << "���" << std::endl;
        std::cin >> pt.P_number;
        std::cout << "����" << std::endl;
        std::cin >> pt.P_name;
        std::cout << "����" << std::endl;
        std::cin >> pt.P_weight;
        std::cout << "����" << std::endl;
        std::cin >> pt.P_age;
        std::cout << "���" << std::endl;
        std::cin >> pt.P_kind;
        std::cout << "�۸�" << std::endl;
        std::cin >> pt.P_price;
        std::cout << "�Ը�" << std::endl;
        std::cin >> pt.P_character;
        //��Ϊδ����
        pt.P_state = 'N';

        int flag = Display_Pet_Mes(pt);
    while(1){
        std::cout << "�Ƿ�ȷ�����(Y/N)" << std::endl;
        std::cin >> choice;

        if(choice == "Y" || choice == "y"){
            int flag = pet.Insert_Pet(pt);
            if(flag == INSERT_PET_SUCCE){
                std::cout << " ��ӳɹ�" << std::endl;
                return 1;
            }else if(flag == INSERT_PET_FAIL){
                std::cout << "����ظ������ʧ��" << std::endl;
                return -1;
            }else{
                std::cout << "���ʧ��" << std::endl;
            }
        }else if(choice == "N" || choice == "n"){
            std::cout << "ȡ�����" << std::endl;
            return 0;
        }else{
            std::cout << "�����������������" << std::endl;
        }
    }
    return 0;
} 

//ɾ��������Ϣ
int Display::Display_Delete(){
    Pet pt;
    std::string choice;

        std::cout << "������Ҫɾ���ĳ����ţ�" << std::endl;
        std::cout << "���" << std::endl;
        std::cin >> pt.P_number;

        pt = Animal::FindMs_Pet(pt.P_number);

        Display_Pet_Mes(pt);
        while(1){
            std::cout << "�Ƿ�ɾ�����������Ϣ(Y/N)" << std::endl;
            std::cin >> choice;

            if(choice == "Y" || choice == "y"){
                if(pet.Delete_Pet(pt) == DELETE_PET_SUCCE){
                    std::cout << " ɾ���ɹ�" << std::endl;
                    return 1;
                }else{
                    std::cout << "���ʧ��" << std::endl;
                    return -1;
                }
            }else if(choice == "N" || choice == "n"){
                std::cout << "ȡ��ɾ��" << std::endl;
                return 0;
            }else{
                std::cout << "�����������������" << std::endl;
            }
        }
    return 0;
}

//��ӡ���г�����Ϣ
int Display::Display_All_Mes(){
    std::vector<Pet> P_Mes = Animal::All_me_Pet();
    if(P_Mes.empty()){
        std::cout << "������ϢΪ�գ�" << std::endl;
    }else{
        for(auto it = P_Mes.begin();it != P_Mes.end();++it){
            Display_Pet_Mes(*it);
            std::cout << std::endl;
        }
    }
    return 0;
}

//���ҳ���
int Display::Display_Search(){
    std::cout << "������Ҫ���ҵĳ����ţ�" << std::endl;
    std::string choice;
    std::cin >> choice;

    Pet t = Animal::FindMs_Pet(choice);
    if(t.P_number == "-1"){
        std::cout << "���Ϊ��" << choice << " �ĳ��ﲻ����"<< std::endl;
    }else{
        Display_Pet_Mes(t);
    }
    return 0;
}

//�޸ĳ�����Ϣ
int Display::Display_Rwrite(){
    std::cout << "������Ҫ�޸ĵĳ����ţ�" << std::endl;
    std::string choice;
    std::cin >> choice;

    Pet t = Animal::FindMs_Pet(choice);
    if(t.P_number == "-1"){
        std::cout << "���Ϊ��" << choice << " �ĳ��ﲻ����"<< std::endl;
        return 0;
    }else{
        Pet pt;
        std::string choice;
        pt.P_number = t.P_number;

        std::cout << "�������µĳ�����Ϣ��" << std::endl;
        std::cout << "����" << std::endl;
        std::cin >> pt.P_name;
        std::cout << "����" << std::endl;
        std::cin >> pt.P_weight;
        std::cout << "����" << std::endl;
        std::cin >> pt.P_age;
        std::cout << "���" << std::endl;
        std::cin >> pt.P_kind;
        std::cout << "�۸�" << std::endl;
        std::cin >> pt.P_price;
        std::cout << "�Ը�" << std::endl;
        std::cin >> pt.P_character;
        std::string Y_N;
        while(1){
            std::cout << "�Ƿ��Ѿ�����(Y/N)" << std::endl;
            std::cin >> Y_N;
            if(Y_N == "Y" || Y_N == "N"){
                pt.P_state = Y_N;
                break;
            }else{
                std::cout << "������������������" << std::endl;
                continue;
            }
        }
        std::cout << "�޸ĺ��";
        Display_Pet_Mes(pt);
        int flag = Rwrite_Pet(pt);
        if(flag == RWRITE_PET_SUCCE){
            std::cout << "�޸ĳɹ�" << std::endl;
        }else if(flag == RWRITE_PET_ERROR){
            std::cout << "�޸�ʧ��" << std::endl;
        }
    }
    return 0;
}

//�����ļ�
int Display::Display_Save_File(){
    char file[FILE_MAX];
    std::string FileName;

    do{
        std::cout << "������Ҫ������Ϣ���ļ���";
        std::cin>>FileName;
        if(FileName.size() > FILE_MAX){
            std::cout << "�ļ�������,����������" << std::endl;
            continue;
        }

        strcpy(file,FileName.c_str());
        std::ofstream F_Out(file);

        if(!F_Out){
            std::cout << "�ļ�д��ʧ��,����ļ���" << std::endl;
            continue;
        }else{
            std::vector<Pet>P_data = All_me_Pet();
            for(auto it = P_data.begin();it != P_data.end();++it){
                F_Out << std::endl << "��ţ�"<<  (*it).P_number      << std::endl
                                   << "���ƣ�"<<  (*it).P_name        << std::endl
                                   << "���أ�"<<  (*it).P_weight      << std::endl
                                   << "���䣺"<<  (*it).P_age         << std::endl
                                   << "���"<<  (*it).P_kind        << std::endl
                                   << "�۸�"<<  (*it).P_price        << std::endl
                                   << "�Ը�"<<  (*it).P_character    << std::endl
                                   << "�Ƿ��ѱ�������"<< (*it).P_state;
            }
            
        }
        F_Out.close();
        std::cout << "������Ϣд���ļ��ɹ�" << std::endl;
        break;
    }while(1);

    return 0;
}

//�����ļ�
int Display::Display_Read_File(){
    char file[FILE_MAX];
    std::string FileName;

    do{
        std::cout << "������Ҫ��ȡ��Ϣ���ļ���";
        std::cin>>FileName;
        if(FileName.size() > FILE_MAX){
            std::cout << "�ļ�������,����������" << std::endl;
            continue;
        }

        strcpy(file,FileName.c_str());
        std::ifstream F_in(file);
        if(!F_in){
            std::cout << "�ļ�������,����������" << std::endl;
            continue;
        }else{
            while(!F_in.eof()){
                int index;
                std::string str;
                Pet pet;
                F_in>>str;
                index = str.find("��");
                pet.P_number = str.substr(index + 2);
                F_in>>str;
                index = str.find("��");
                pet.P_name = str.substr(index + 2);
                F_in>>str;
                index = str.find("��");
                pet.P_weight = str.substr(index + 2);
                F_in>>str;
                index = str.find("��");
                pet.P_age = str.substr(index + 2);
                F_in>>str;
                index = str.find("��");
                pet.P_kind = str.substr(index + 2);
                F_in>>str;
                index = str.find("��");
                pet.P_price = str.substr(index + 2);
                F_in>>str;
                index = str.find("��");
                pet.P_character = str.substr(index + 2);
                F_in>>str;
                index = str.find("��");
                pet.P_state = str.substr(index + 2);

                // Display_Pet_Mes(pet);

                Insert_Pet(pet);

            }
            std::cout << "��������ļ���Ϣ�ɹ�" << std::endl;
            break;
        }   
    }while (1);

    std::cout << "����ĳ�����Ϣ���£�" << std::endl;
    Display_All_Mes();
    return 0;
}
