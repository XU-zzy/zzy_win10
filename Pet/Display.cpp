#include"Display.h"
#include"Animal.h"
#include"Pet.h"

//显示宠物信息
int Display::Display_Pet_Mes(Pet &pet){
    std::cout<< "宠物信息如下:"                 << std::endl;
    std::cout << "编号： " << pet.P_number      << std::endl;
    std::cout << "名称： " << pet.P_name        << std::endl;
    std::cout << "体重： " << pet.P_weight      << std::endl;
    std::cout << "年龄： " << pet.P_age         << std::endl;
    std::cout << "类别： " << pet.P_kind        << std::endl;
    std::cout << "价格： " << pet.P_price       << std::endl;
    std::cout << "性格： " << pet.P_character   << std::endl;
    std::cout << "是否已被卖出： ";
    if(pet.P_state == "Y"){
        std::cout << "是" <<  std::endl;
    }else{
        std::cout << "否" <<  std::endl;
    }
    return 0;
}

//显示主菜单
int Display::Display_Main_Menu(){
    int choice;
    do{
        std::cout<<std::endl<<"★★★【欢迎进入宠物商店管理系统！ 请选择菜单:】★★★"<<std::endl;
	    std::cout<<" \t|=========================== |"<<std::endl; 
	    std::cout<<" \t| 1.添加宠物的信息            |"<<std::endl; 
	    std::cout<<" \t| 2.删除宠物的信息            |"<<std::endl;
	    std::cout<<" \t| 3.修改宠物的信息            |"<<std::endl;
	    std::cout<<" \t| 4.查询宠物的信息            |"<<std::endl;
	    std::cout<<" \t| 5.查询所有宠物的信息         |"<<std::endl;
	    std::cout<<" \t| 6.保存文件                  |"<<std::endl;
	    std::cout<<" \t| 7.读取文件                  |"<<std::endl;
	    std::cout<<" \t| 8.退出系统                  |"<<std::endl;
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

// 添加宠物信息
int Display::Display_Insert(){
    
        Pet pt;
        std::string choice;

        std::cout << "请先输入宠物信息：" << std::endl;
        std::cout << "编号" << std::endl;
        std::cin >> pt.P_number;
        std::cout << "名称" << std::endl;
        std::cin >> pt.P_name;
        std::cout << "体重" << std::endl;
        std::cin >> pt.P_weight;
        std::cout << "年龄" << std::endl;
        std::cin >> pt.P_age;
        std::cout << "类别" << std::endl;
        std::cin >> pt.P_kind;
        std::cout << "价格" << std::endl;
        std::cin >> pt.P_price;
        std::cout << "性格" << std::endl;
        std::cin >> pt.P_character;
        //置为未卖出
        pt.P_state = 'N';

        int flag = Display_Pet_Mes(pt);
    while(1){
        std::cout << "是否确认添加(Y/N)" << std::endl;
        std::cin >> choice;

        if(choice == "Y" || choice == "y"){
            int flag = pet.Insert_Pet(pt);
            if(flag == INSERT_PET_SUCCE){
                std::cout << " 添加成功" << std::endl;
                return 1;
            }else if(flag == INSERT_PET_FAIL){
                std::cout << "编号重复，添加失败" << std::endl;
                return -1;
            }else{
                std::cout << "添加失败" << std::endl;
            }
        }else if(choice == "N" || choice == "n"){
            std::cout << "取消添加" << std::endl;
            return 0;
        }else{
            std::cout << "输入错误，请重新输入" << std::endl;
        }
    }
    return 0;
} 

//删除宠物信息
int Display::Display_Delete(){
    Pet pt;
    std::string choice;

        std::cout << "请输入要删除的宠物编号：" << std::endl;
        std::cout << "编号" << std::endl;
        std::cin >> pt.P_number;

        pt = Animal::FindMs_Pet(pt.P_number);

        Display_Pet_Mes(pt);
        while(1){
            std::cout << "是否删除这个宠物信息(Y/N)" << std::endl;
            std::cin >> choice;

            if(choice == "Y" || choice == "y"){
                if(pet.Delete_Pet(pt) == DELETE_PET_SUCCE){
                    std::cout << " 删除成功" << std::endl;
                    return 1;
                }else{
                    std::cout << "添加失败" << std::endl;
                    return -1;
                }
            }else if(choice == "N" || choice == "n"){
                std::cout << "取消删除" << std::endl;
                return 0;
            }else{
                std::cout << "输入错误，请重新输入" << std::endl;
            }
        }
    return 0;
}

//打印所有宠物信息
int Display::Display_All_Mes(){
    std::vector<Pet> P_Mes = Animal::All_me_Pet();
    if(P_Mes.empty()){
        std::cout << "宠物信息为空！" << std::endl;
    }else{
        for(auto it = P_Mes.begin();it != P_Mes.end();++it){
            Display_Pet_Mes(*it);
            std::cout << std::endl;
        }
    }
    return 0;
}

//查找宠物
int Display::Display_Search(){
    std::cout << "请输入要查找的宠物编号：" << std::endl;
    std::string choice;
    std::cin >> choice;

    Pet t = Animal::FindMs_Pet(choice);
    if(t.P_number == "-1"){
        std::cout << "编号为：" << choice << " 的宠物不存在"<< std::endl;
    }else{
        Display_Pet_Mes(t);
    }
    return 0;
}

//修改宠物信息
int Display::Display_Rwrite(){
    std::cout << "请输入要修改的宠物编号：" << std::endl;
    std::string choice;
    std::cin >> choice;

    Pet t = Animal::FindMs_Pet(choice);
    if(t.P_number == "-1"){
        std::cout << "编号为：" << choice << " 的宠物不存在"<< std::endl;
        return 0;
    }else{
        Pet pt;
        std::string choice;
        pt.P_number = t.P_number;

        std::cout << "请输入新的宠物信息：" << std::endl;
        std::cout << "名称" << std::endl;
        std::cin >> pt.P_name;
        std::cout << "体重" << std::endl;
        std::cin >> pt.P_weight;
        std::cout << "年龄" << std::endl;
        std::cin >> pt.P_age;
        std::cout << "类别" << std::endl;
        std::cin >> pt.P_kind;
        std::cout << "价格" << std::endl;
        std::cin >> pt.P_price;
        std::cout << "性格" << std::endl;
        std::cin >> pt.P_character;
        std::string Y_N;
        while(1){
            std::cout << "是否已经卖出(Y/N)" << std::endl;
            std::cin >> Y_N;
            if(Y_N == "Y" || Y_N == "N"){
                pt.P_state = Y_N;
                break;
            }else{
                std::cout << "输入有误，请重新输入" << std::endl;
                continue;
            }
        }
        std::cout << "修改后的";
        Display_Pet_Mes(pt);
        int flag = Rwrite_Pet(pt);
        if(flag == RWRITE_PET_SUCCE){
            std::cout << "修改成功" << std::endl;
        }else if(flag == RWRITE_PET_ERROR){
            std::cout << "修改失败" << std::endl;
        }
    }
    return 0;
}

//保存文件
int Display::Display_Save_File(){
    char file[FILE_MAX];
    std::string FileName;

    do{
        std::cout << "请输入要保存信息的文件名";
        std::cin>>FileName;
        if(FileName.size() > FILE_MAX){
            std::cout << "文件名过长,请重新输入" << std::endl;
            continue;
        }

        strcpy(file,FileName.c_str());
        std::ofstream F_Out(file);

        if(!F_Out){
            std::cout << "文件写入失败,检查文件名" << std::endl;
            continue;
        }else{
            std::vector<Pet>P_data = All_me_Pet();
            for(auto it = P_data.begin();it != P_data.end();++it){
                F_Out << std::endl << "编号："<<  (*it).P_number      << std::endl
                                   << "名称："<<  (*it).P_name        << std::endl
                                   << "体重："<<  (*it).P_weight      << std::endl
                                   << "年龄："<<  (*it).P_age         << std::endl
                                   << "类别："<<  (*it).P_kind        << std::endl
                                   << "价格："<<  (*it).P_price        << std::endl
                                   << "性格："<<  (*it).P_character    << std::endl
                                   << "是否已被卖出："<< (*it).P_state;
            }
            
        }
        F_Out.close();
        std::cout << "宠物信息写入文件成功" << std::endl;
        break;
    }while(1);

    return 0;
}

//读入文件
int Display::Display_Read_File(){
    char file[FILE_MAX];
    std::string FileName;

    do{
        std::cout << "请输入要读取信息的文件名";
        std::cin>>FileName;
        if(FileName.size() > FILE_MAX){
            std::cout << "文件名过长,请重新输入" << std::endl;
            continue;
        }

        strcpy(file,FileName.c_str());
        std::ifstream F_in(file);
        if(!F_in){
            std::cout << "文件名错误,请重新输入" << std::endl;
            continue;
        }else{
            while(!F_in.eof()){
                int index;
                std::string str;
                Pet pet;
                F_in>>str;
                index = str.find("：");
                pet.P_number = str.substr(index + 2);
                F_in>>str;
                index = str.find("：");
                pet.P_name = str.substr(index + 2);
                F_in>>str;
                index = str.find("：");
                pet.P_weight = str.substr(index + 2);
                F_in>>str;
                index = str.find("：");
                pet.P_age = str.substr(index + 2);
                F_in>>str;
                index = str.find("：");
                pet.P_kind = str.substr(index + 2);
                F_in>>str;
                index = str.find("：");
                pet.P_price = str.substr(index + 2);
                F_in>>str;
                index = str.find("：");
                pet.P_character = str.substr(index + 2);
                F_in>>str;
                index = str.find("：");
                pet.P_state = str.substr(index + 2);

                // Display_Pet_Mes(pet);

                Insert_Pet(pet);

            }
            std::cout << "读入宠物文件信息成功" << std::endl;
            break;
        }   
    }while (1);

    std::cout << "读入的宠物信息如下：" << std::endl;
    Display_All_Mes();
    return 0;
}