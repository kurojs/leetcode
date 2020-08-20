/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 *
 * https://leetcode.com/problems/missing-number/description/
 *
 * algorithms
 * Easy (51.77%)
 * Likes:    1907
 * Dislikes: 2199
 * Total Accepted:    481K
 * Total Submissions: 928.8K
 * Testcase Example:  '[3,0,1]'
 *
 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n,
 * find the one that is missing from the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,0,1]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [9,6,4,2,3,5,7,0,1]
 * Output: 8
 * 
 * 
 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant extra space complexity?
 */

// @lc code=start
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        bool check[n + 1];
        memset(check, 0, sizeof(check));

        for (int i = 0; i < n; i++)
        {
            check[nums[i]] = true;
        }

        for (int i = 0; i <= n; i++)
        {
            if (!check[i])
            {
                return i;
            }
        }

        return -1;
    }
};
// @lc code=end
