#include<iostream>

using namespace std;

int main(){

    string  str;
    int m;
    cin >> str;
    cin >> m;
    int step = 1;
    int t_1 = 0;
    int t_2 = 0;
    for(int i = 0;i < str.size()-1;i++){
        // step = step+1;
        // step = 1;
        int flag_1 = abs(str[i] - str[i+1]);
        int flag_2 = 26-abs(str[i] - str[i+1] > 1);
        int flag = flag_1 < flag_2 ? flag_1:flag_2;
        //此时开始就需要使用魔法键
        if(i >= 0 && m > 0 && flag > 1){
            // --m;
            // step = 1;
            if(m+i < str.size()){//魔法键没用完
                step = step + m*2;
                i = i+m;
            }else if(m+i == str.size()){//魔法键刚好用完
                step = step + m*2;
                cout << step << endl;
                return 0;
            }else{//魔法键没用完
                // step = step + (str.size()-1)*2;
                step = step + m*2;
                i = i+m;
            }
            m = 0;
        }

        if(str[i] > str[i+1]){
            t_1 = str[i] - str[i+1];
            t_2 = abs(26 - t_1);
        }else if(str[i] < str[i+1]){
            t_1 = str[i+1] - str[i];
            t_2 = abs(26 - t_1);
        }else{
            t_1 = 1;
            t_2 = 0;
        }
        step = step + (t_1 < t_2 ? t_1:t_2) + 1; 
    }

    cout << step << endl;
    
    return 0; 

}