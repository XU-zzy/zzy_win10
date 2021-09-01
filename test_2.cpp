#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int num,x,y;
    cin >> num >> x >> y;
    
    vector<int>    sum(num);
    for(int i = 0;i < num;i++){
        int t;
        cin >> t;
        sum[i] = t;
    }
    sort(sum.begin(),sum.end());
    if(2*x > num || 2*y < num)    cout << -1;
    
    if(x + y >= num){
        cout << sum[x - 1];
    }else{
        cout << sum[num - y - 1];
    }
    return 0;
}
// 对数据进行排序，排完了按需要的数量输出就行了
// #include<iostream>
// #include<queue>
// #include<vector>
// #include<algorithm>
// using namespace std;
// class Solution{
// public:
//     int sore(int n, int x, int y, vector<int> nums){
//         if(2*x > n || n > 2*y)return -1;
//         sort(nums.begin(), nums.end());
//         if(x+y >= n){
//             return nums[x-1];
//         }else{
//             return nums[n-y-1];
//         }
//     }
// };
// int main(){
//     int n, x, y;
//     cin>>n>>x>>y;
//     vector<int> nums(n);
//     for(int i = 0; i<n; i++){
//         int temp;
//         cin>>temp;
//         nums[i] = temp;
//     }
//     int res = Solution().sore(n, x, y, nums);
//     cout<<res;
//     return 0;
// }