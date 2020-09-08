/*
 * @lc app=leetcode id=76 lang=golang
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (34.70%)
 * Likes:    4974
 * Dislikes: 342
 * Total Accepted:    426.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 *
 * Example:
 *
 *
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 *
 *
 * Note:
 *
 *
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 *
 *
 */

// @lc code=start
func minWindow(s string, t string) string {
	const MaxInt64 = 1<<63 - 1

	compareMap := func(a, b map[byte]int) bool {
		if len(a) != len(b) {
			return false
		}

		for key, val := range a {
			if val > b[key] {
				return false
			}
		}

		return true
	}

	// Count dicstinct characters int t
	reqChars := map[byte]int{}
	for i := range t {
		reqChars[t[i]]++
	}

	minLen := MaxInt64
	start := 0
	startIdx := -1
	n := len(s)
	currChars := map[byte]int{}

	for i := 0; i < n; i++ {
		if _, ok := reqChars[s[i]]; ok {
			currChars[s[i]]++

			if compareMap(reqChars, currChars) {
				for {
					currentCount, ok := currChars[s[start]]

					if !ok {
						start++
					} else if currentCount > reqChars[s[start]] {
						currChars[s[start]]--
						start++
					} else {
						break
					}
				}

				currLen := i - start + 1
				if minLen > currLen {
					minLen = currLen
					startIdx = start
				}
			}
		}
	}

	// Return answer
	if startIdx == -1 {
		return ""
	}

	return s[startIdx : startIdx+minLen]
}

// @lc code=end

