/*
 * @lc app=leetcode id=5 lang=golang
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
func longestPalindrome(s string) string {
	endLongest := 0
	currLongest := 0

	n := len(s)
	var dp [n + 1]int

	return s[:endLongest]
}

// @lc code=end
