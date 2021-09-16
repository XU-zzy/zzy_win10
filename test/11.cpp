#include<iostream>
#include<stack>
int main(){
    int n = 10,k = 10;
    int num = 0;
        for(int i = 1;i < 1000000000;i++){
            std::stack<int> st;
            int x;
            int t = i;
            
            while(t!=0){
                x = t%k;
                t = t/k;
                if(x == 1){
                    num++;
                    std::cout << "k1" << std::endl;
                }
                if(num == n){
                    std::cout << i << std::endl;
                    return 0;
                }

                std::cout << "kk" << std::endl;
            } 
            // while(!st.empty()){
            //     int x = st.top();
            //     st.pop();
            //     if(x == 1){
            //         num++;
            //         std::cout << "k1" << std::endl;
            //     }
            //     if(num == n){
            //         std::cout << i << std::endl;
            //         return 0;
            //     }
            // }
        }
        std::cout << 'k' << std::endl;
    return 0;
}