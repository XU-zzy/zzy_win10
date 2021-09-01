/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> char_set;

        int left = 0,right = 0,num = 0;
        for(;left < s.size();++left){
            while(right < s.size() && !char_set.count(s[right])){
                char_set.insert(s[right]);
                num = max(num,right-left+1);
                ++right;
            }
            char_set.erase(s[left]);
        }
        return num;
    }
};
// @lc code=end

