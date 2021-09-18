#include<iostream>

using namespace std;

int main(){
    long long int n;
    cin >> n;
    long long int t,ans;
    t = n;
    int num = 0;
    while(n){
        ans = n%10;
        if(ans == 0){
            n = n/10;
            continue;
        }
        if(t%ans == 0){
            num++;
        }
        n = n/10;
    }

    cout << num;

    return 0;
}