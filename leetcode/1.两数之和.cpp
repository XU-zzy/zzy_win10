/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include<vector>
#include<tr1/unordered_map>
#include <tr1/unordered_set>
//unordered_set相同
using namespace std::tr1;
//原先的std命名空间也不能省
using namespace std;
// // @lc code=start
//暴力
// class Solution {
// public:
//     std::vector<int> twoSum(std::vector<int>& nums, int target) {
        
//         for(int i = 0;i < nums.size();i++){
//             for(int j = i + 1;j < nums.size();j++){
//                 if(nums[i] + nums[j] == target){
//                     return {i,j};
//                 }
//             }
//         }

//         return {0,0};

//     }
// };

//哈希
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        
        unordered_map<int,int>u_map;
        for(int i = 0;i < nums.size();++i){
                auto it = u_map.find(target - nums[i]);
                if(it != u_map.end()){
                    return {it->second,i};
                }
                u_map[nums[i]] = i;
        }

        return {};

    }
};

// @lc code=end

