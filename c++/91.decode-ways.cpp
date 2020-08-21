/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (24.71%)
 * Likes:    2857
 * Dislikes: 2954
 * Total Accepted:    417K
 * Total Submissions: 1.7M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 * 
 * Example 1:
 * 
 * 
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 * 
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n < 1) {
            return 0;
        }
        
        if (s[0] == '0') return 0;
        
        int dp [n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i = 1; i < n; i++) {
            int c = (s[i - 1] - '0') * 10 + s[i] - '0';
            
            if (c == 0 || (s[i] == '0' && c > 26)) {
                return 0;
            }
            
            if (c > 26 || c < 10) {
                dp[i + 1] = dp[i];
                continue;
            }  
            
            if (c == 10 || c == 20) {
                dp[i + 1] = dp[i] == dp[i - 1] ? dp[i] : dp[i - 1];
                continue;
            }
            
            dp[i + 1] = dp[i] + dp[i-1];
        }


        return dp[n];
    }
};
// @lc code=end

