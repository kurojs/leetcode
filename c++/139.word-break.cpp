/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (40.12%)
 * Likes:    4716
 * Dislikes: 241
 * Total Accepted:    579.8K
 * Total Submissions: 1.4M
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 * 
 * Note:
 * 
 * 
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // Try to find min length minDict and max length maxDict of dict
        // Break string s to tokens with size between minDict and maxDict
        // Time complexity: O(Dict size) + O(string len * Dict max len - Dict min len)
        // Space complexity: O(Dict size + String length)

        int n = s.size();
        int minDict = INT_MAX;
        int maxDict = INT_MIN;
        unordered_map<string, bool> dict;
        for (int i = 0; i < wordDict.size(); i++) {
            dict[wordDict[i]] = true;    
            minDict = min(minDict, (int)wordDict[i].size());
            maxDict = max(n, (int)wordDict[i].size());
        }
        
        // can't create string with dict longer itself
        if (minDict > n) {
            return false;
        }
        
        // Create dp array to check if prev substring has found in dict
        bool dp [n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = true;

        for (int i = 0; i < n; i++) {
            for (int len = minDict; len + i <= n; len++) {
                if (dp[i] && dict.find(s.substr(i, len)) != dict.end()) {
                    dp[i + len] = true;
                }
            }
        }
        
        return dp[n];
    }
};
// @lc code=end

