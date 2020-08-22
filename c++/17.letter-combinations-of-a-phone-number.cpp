/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 *
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (46.88%)
 * Likes:    4198
 * Dislikes: 431
 * Total Accepted:    640.2K
 * Total Submissions: 1.4M
 * Testcase Example:  '"23"'
 *
 * Given a string containing digits from 2-9 inclusive, return all possible
 * letter combinations that the number could represent.
 * 
 * A mapping of digit to letters (just like on the telephone buttons) is given
 * below. Note that 1 does not map to any letters.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * Note:
 * 
 * Although the above answer is in lexicographical order, your answer could be
 * in any order you want.
 * 
 */

// @lc code=start
class Solution {
    unordered_map<char, vector<string>> keys;

public:
    Solution() {
        keys['1'] = {};
        keys['2'] = {"a", "b", "c"};
        keys['3'] = {"d", "e", "f"};
        keys['4'] = {"g", "h", "i"};
        keys['5'] = {"j", "k", "l"};
        keys['6'] = {"m", "n", "o"};
        keys['7'] = {"p", "q", "r", "s"};
        keys['8'] = {"t", "u", "v"};
        keys['9'] = {"w", "x", "y", "z"};
        keys['0'] = {" "};
    }

    vector<string> bructeForce(string digits) {
        vector<string> ans;
        
        for (char c : digits) {
            if (ans.size() == 0) {
                for (string s : keys[c]) {
                    ans.push_back(s);
                }
                continue;
            }
            
            vector<string> temp;
            for (string s : keys[c]) {
                for (string a : ans) {
                    temp.push_back(a + s);
                }
            }
            ans = temp;
        }
        
        return ans;
    }

    vector<string> letterCombinations(string digits) {
        return bructeForce(digits);
    }
};
// @lc code=end

