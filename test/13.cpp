#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main(){
    // vector<vector<int>> a;
    int n;
    cin >> n;
    // vector<int> num_init;
    // for(int i = 0;i < n;i++){
    //     int t;
    //     cin >> t;
    //     num_init.push_back(t);
    // }
    int j;
    while(n--){
        int init;
        cin >> init;
        if(init == 0){
            // vector<int> ans(0);
            // a.push_back(ans);
            cout << init;
            continue;
        }
        // }else if(init == 2){
        //     vector<int> ans;
        //     ans.push_back(0);
        //     a.push_back(ans);
        //     continue;
        // }

        stack<int> num;
        int t;
        while(init != 0){
            t = init%10;
            init = init/10;
            num.push(t);
        }

        stack<int> arr;
        int t_2;
        while(num.size() != 0){
            t_2 = num.top();
            num.pop();
            int t_3;
            if(t_2 == 0){
                arr.push(t_2);
                continue;
            }else if(t_2 == 1){
                int tt = 1;
                arr.push(tt);
                continue;
            }
            
            while(t_2 != 0){
                t_3 = t_2%2;
                t_2 = t_2/2;
                arr.push(t_3);
            }
        }
        stack<int> ans;
        while(!arr.empty()){
            int t = arr.top();
            ans.push(t);
            arr.pop();
        }

        while(1){
            if(ans.top() == 0){
                ans.pop();
            }else{
                break;
            }
        }
        int test;
        
        vector<int> b;
        while(ans.size() != 0){
            test = ans.top();
            cout << test;
            // a[j].push_back(test);
            b.push_back(test);
            ans.pop();
            
            while(ans.size() != 0  && ans.top() == test){
                ans.pop();
            }
        }
        // a.push_back(b); 
        if(n){
            cout << endl;
        }
    }

    // for(int i = 0;i < n;i++){
    //     for(int k = 0;k < a[i].size();k++){
    //         cout << a[i][k];
    //     }
    //     if(i != n-1){
    //         cout << endl;

    //     }
    // }
    return 0;
}