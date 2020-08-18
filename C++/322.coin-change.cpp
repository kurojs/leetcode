/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 *
 * https://leetcode.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (35.53%)
 * Likes:    4528
 * Dislikes: 142
 * Total Accepted:    437.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '[1,2,5]\n11'
 *
 * You are given coins of different denominations and a total amount of money
 * amount. Write a function to compute the fewest number of coins that you need
 * to make up that amount. If that amount of money cannot be made up by any
 * combination of the coins, return -1.
 * 
 * Example 1:
 * 
 * 
 * Input: coins = [1, 2, 5], amount = 11
 * Output: 3 
 * Explanation: 11 = 5 + 5 + 1
 * 
 * Example 2:
 * 
 * 
 * Input: coins = [2], amount = 3
 * Output: -1
 * 
 * 
 * Note:
 * You may assume that you have an infinite number of each kind of coin.
 * 
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        
        int n = coins.size();
        // create table for calculate solution from bottom up
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < n; j++) {
                if (i >= coins[j]) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};

class SolutionBacktracking {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }
        
        int n = coins.size();
        if (n < 1) {
            return -1;
        }
        unordered_map<int, int> backtracking;
        return helper(coins, amount, backtracking);
    }
    
    int helper(vector<int>& coins, int amount, unordered_map<int, int>& backtracking) {
        if (backtracking.find(amount) != backtracking.end()) {
            return backtracking[amount];
        }
        
        if (amount < 0) {
            return -1;
        }
        
        if (amount == 0) {
            return 0;
        }

        int minCoins = INT_MAX;
        int n = coins.size();
        for (int i = 0; i < n; i++) {
            if (coins[i] == amount) {
                return 1;
            }
            
            int temp = helper(coins, amount - coins[i], backtracking);
            if (temp >= 0) {
                minCoins = min(minCoins, temp + 1);            
            }
        }

        minCoins = minCoins == INT_MAX ? -1 : minCoins;
        backtracking[amount] = minCoins;
        return minCoins;
    }
};
// @lc code=end

