#include<iostream>
#include<cstdlib>
int main(){
    std::string str("1000");
    char t_1 = '1';
    char t_0 = '0';
    // int ans = stoi(str);
    // std::cout << ans << std::endl;
    // if(str[0] == t){
    //     std::cout << str[0] << std::endl;
    // }
    if(str[0] == t_0){
        str[0] = t_1;
    }
    for(size_t i = 1;i < str.size();i++){
        if(str[i] == t_0){
            str[i] = t_1;
            // std::cout << "k" << std::endl;
        }else{
            break;
        }
    }
    // std::cout << str << std::endl;
    return 0;
}