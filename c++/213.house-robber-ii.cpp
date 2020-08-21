/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 *
 * https://leetcode.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (36.48%)
 * Likes:    1881
 * Dislikes: 52
 * Total Accepted:    180.9K
 * Total Submissions: 495.7K
 * Testcase Example:  '[2,3,2]'
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed. All houses at this place are
 * arranged in a circle. That means the first house is the neighbor of the last
 * one. Meanwhile, adjacent houses have security system connected and it will
 * automatically contact the police if two adjacent houses were broken into on
 * the same night.
 * 
 * Given a list of non-negative integers representing the amount of money of
 * each house, determine the maximum amount of money you can rob tonight
 * without alerting the police.
 * 
 * Example 1:
 * 
 * 
 * Input: [2,3,2]
 * Output: 3
 * Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money
 * = 2),
 * because they are adjacent houses.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money =
 * 3).
 * Total amount you can rob = 1 + 3 = 4.
 * 
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        // Because we can take both the first and the last house
        // Create two array for each one
        // And just take the bigger amount
        
        int n = nums.size();
        if (n < 1) {
            return 0;
        }
        
        if (n == 1) {
            return nums[0];
        }
        
        // Store max money can take for this house
        int dp [n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 0;
        dp[1] = nums[0];
        
        for (int i = 1; i < n - 1; i++) {
            dp[i + 1] = max(dp[i], nums[i] + dp[i-1]);
        }
        
        int maxMoney = dp[n-1];
        memset(dp, 0, sizeof(dp));
        nums[0] = 0;
        dp[0] = 0;
        dp[1] = nums[0];
        
        for (int i = 1; i < n; i++) {
            dp[i + 1] = max(dp[i], nums[i] + dp[i-1]);
        }
        
        return max(maxMoney, dp[n]);
    }
};
// @lc code=end

