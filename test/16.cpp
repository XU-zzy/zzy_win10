#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int main(){
    long sum;
    cin >> sum;

    vector<long> ans;
    for(int i = 0;i < 100;i++){
        ans.push_back(pow(2,i));
    }

    int n = 0;

    while(1){
        if(sum == 0){
            cout << n << endl;
            return 0;
        }
        for(int i = 0;i < 100;i++){
            if(ans[i] > sum){
                sum = sum - ans[i-1];
                n++;
                i = 0;
            }else if(ans[i] == sum){                
                n++;
                cout << n << endl;
                return 0;
            }
            if(sum == 0){
                cout << n << endl;
                return 0;
            }
        }
    }
    return 0;
}