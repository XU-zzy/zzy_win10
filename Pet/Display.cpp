#include"Display.h"

int Display::Display_Insert(){return 0;}
int Display::Display_Delete(){return 0;}
int Display::Display_Rwrite(){return 0;}
int Display::Display_Search(){return 0;}
int Display::Display_Save_File(){return 0;}
int Display::Display_Read_File(){return 0;}

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
	    // std::cout<<" \t| 5.删除宠物的信息            |"<<std::endl;
	    std::cout<<" \t| 6.保存文件                  |"<<std::endl;
	    std::cout<<" \t| 7.读取文件                  |"<<std::endl;
	    std::cout<<" \t| 8.退出系统                  |"<<std::endl;
	    std::cout<<" \t|=========================== |\n"<<std::endl;
	
        std::cin>>choice;
        switch(choice){
            // case 1: {Display_Insert();}
            // case 2: {Display_Delete();}
            // case 3: {Display_Rwrite();}
            // case 4: {Display_Search();}
            // case 5: {}
            // case 6: {Display_Save_File();}
            // case 7: {Display_Read_File();}
            // case 1: {}
            break;
        }
    }while(choice != 8);   
    
    return 0;
}



//添加宠物信息显示
// int Display::Display_Insert(){
    
//     std::cout << "请先输入宠物编号：" << std::endl;
//     std::cin >> pet;

//     if(pet.Find_pet()){

//     }

// }   