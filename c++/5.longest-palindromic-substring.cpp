/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (29.48%)
 * Likes:    7672
 * Dislikes: 563
 * Total Accepted:    1M
 * Total Submissions: 3.4M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n < 1)
        {
            return "";
        }

        if (n == 1)
        {
            return string(1, s[0]);
        }

        string substr(1, s[0]);
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                int left = i;
                int right = i + 1;
                string sub = "";

                while (left >= 0 && right < n && s[left] == s[right])
                {
                    sub = s[left] + sub + s[right];
                    left--;
                    right++;
                }

                if (sub.size() > substr.size())
                {
                    substr = sub;
                }
            }

            int left = i - 1;
            int right = i + 1;
            string sub(1, s[i]);

            while (left >= 0 && right < n && s[left] == s[right])
            {
                sub = s[left] + sub + s[right];
                left--;
                right++;
            }

            if (sub.size() > substr.size())
            {
                substr = sub;
            }
        }

        return substr;
    }

    string fewestCoins(string s)
    {
        // Count the unique chars in given string
        unordered_map<char, bool> mp;
        for (char c : s)
        {
            mp[c] = true;
        }

        int n = s.size();
        int m = mp.size();
        if (n == m)
        {
            return s;
        }

        int left = 0;
        int right = n - 1;
        while (left < right && mp.find(s[left]) == mp.end())
        {
            left++;
        }

        while (left < right && mp.find(s[right]) == mp.end())
        {
            right--;
        }

        // Find in s[left, right]
        for (int i = left; i <= right; i++)
        {
            unordered_map<char, bool> curr_mp;
            int j = 0;
            while (i + j <= right)
            {
                char cur_char = s[i + j];
                if (mp.find(cur_char) != mp.end())
                {
                    curr_mp[cur_char] = true;
                    if (curr_mp.size() == m)
                    {
                        return s.substr(i, j + 1);
                    }
                }
                j++;
            }
        }
    }
};
// @lc code=end
