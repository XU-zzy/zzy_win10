/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
// #include<vector>
// #include<tr1/unordered_map>
// #include <tr1/unordered_set>
// //unordered_set相同
// using namespace std::tr1;
// //原先的std命名空间也不能省
using namespace std;
// // @lc code=start
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};

// @lc code=end

