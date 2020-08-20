/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (42.63%)
 * Likes:    5108
 * Dislikes: 115
 * Total Accepted:    402K
 * Total Submissions: 942.6K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 * 
 * Example:
 * 
 * 
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4 
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4. 
 * 
 * Note: 
 * 
 * 
 * There may be more than one LIS combination, it is only necessary for you to
 * return the length.
 * Your algorithm should run in O(n^2) complexity.
 * 
 * 
 * Follow up: Could you improve it to O(n log n) time complexity?
 * 
 */

// @lc code=start
class Solution
{
public:
    // O(n*n) Solution
    int simpleDP(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
        {
            return n;
        }

        int dp[n + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        dp[1] = 1;

        int maxLen = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            dp[i] = max(dp[i], 1);
            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
    }

    int lengthOfLIS(vector<int> &nums)
    {
        return simpleDP(nums);
    }
};
// @lc code=end
