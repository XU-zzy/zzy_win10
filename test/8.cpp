#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>

using namespace std;

int main(){
    int n;
    cin >> n;

    unordered_set<int,int,int>    sum(0);
    vector<int> x(n);

    for(int i = 0;i < n;i++){
        cin >> x[i];
    }

    sort(x.begin(),x.end());
    // auto it = x.begin();
    // for(int i = 0;i < n;i++){
    //     cout << *it++;
    // }

    int num = 0;
    for(int i = 0;i < n-2;i++){
        for(int j = i+1;j < n-1;j++){
            for(int k = j+1;k < n;k++){
                if(x[k] < x[j] + x[i]){
                    if(x[k] == x[i] == x[j])    continue;
                    // num++;
                    vector<int> t = {x[k],x[i],x[j]};
                    sort(t.begin(),t.end());
                    sum.insert({t[0],t[1],t[2]});
                }
            }
        }
    }

    cout << sum.size();
}