#include<stdio.h>

int (*g_pFun)(int a, int b);

//hook函数
int Max(int a,int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}
//hook函数
int Min(int a,int b){
    if(a < b){
        return a;
    }else{
        return b;
    }
}
//注册函数
int Reg_fun(int(*pFun)(int x,int y)){
    g_pFun = pFun;
    return 0;
}
int Plat(){

    int a = 10;
    int b = 15;

    int ans = g_pFun(a,b);

    printf("%d\n",ans);

    return 0;

}

int main(){
    
    Reg_fun(Min);

    Plat();

    return 0;
}
