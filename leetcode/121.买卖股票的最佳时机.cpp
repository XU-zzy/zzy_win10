/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start

// 对方法二的另一种解释： 方法二可以看做一种动态规划，只不过对空间复杂度进行了优化。
// 考虑每次如何获取最大收益？第i天的最大收益只需要知道前i天的最低点就可以算出来了。
// 而第i天以前（包括第i天）的最低点和i-1天的最低点有关，至此我们的动态方程就出来了。
// dp[i] = min(d[i-1],prices[i])
// 其中dp[0]=prices[0],然后动态计算之后的就可以了。 
// 得到了前i天的最低点以后，只需要维护一个max用来保存最大收益就可以了。 
// 这个时候是空间复杂度O（n）的动态规划，代码如下：
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //dp[i]表示截止到i，价格的最低点是多少   dp[i]=min(dp[i-1],nums[i])
        int max = 0;
        int dp[prices.size()];
        dp[0] = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            dp[i] = (dp[i - 1] < prices[i]) ? dp[i - 1] : prices[i];
            max = (prices[i] - dp[i]) > max ? prices[i] - dp[i] : max;
        }
        return max;
    }
};
// 接着考虑优化空间，
// 仔细观察动态规划的辅助数组，其每一次只用到了dp[-1]这一个空间，
// 因此可以把数组改成单个变量dp来存储截止到第i天的价格最低点。
// 优化之后的代码就是题解中的方法二。
// @lc code=end

