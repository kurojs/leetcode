/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 *
 * https://leetcode.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (62.80%)
 * Likes:    5632
 * Dislikes: 281
 * Total Accepted:    581.2K
 * Total Submissions: 924.2K
 * Testcase Example:  '3'
 *
 * 
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 * 
 * 
 * 
 * For example, given n = 3, a solution set is:
 * 
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    void backtrack(vector<string>& ans, int n, string s, unordered_map<string, bool>& mp) {
        if (mp.find(s) != mp.end()) {
            return;
        }
        mp[s] = true;
        
        int len = s.size();
        if (len >= n * 2) {
            ans.push_back(s);
            return;
        }
        
        
        backtrack(ans, n, "()" + s, mp);
        backtrack(ans, n, s + "()", mp);
        backtrack(ans, n, "(" + s + ")", mp);
        for (int i = 0; i < len - 1; i ++) {
            if ((s[i] == '(' && s[i + 1] == ')')
                || (s[i] == ')' && s[i+1] == '(')
                || (s[i] == '(' && s[i+1] == '(')
               ) {
                string temp = s;
                backtrack(ans, n, temp.insert(i + 1, "()"), mp);
            }
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        unordered_map<string, bool> mp;
        backtrack(ans, n, "", mp);
        return ans;
    }
};
// @lc code=end

