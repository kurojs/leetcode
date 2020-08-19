/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 *
 * https://leetcode.com/problems/counting-bits/description/
 *
 * algorithms
 * Medium (69.56%)
 * Likes:    2868
 * Dislikes: 175
 * Total Accepted:    297K
 * Total Submissions: 426.9K
 * Testcase Example:  '2'
 *
 * Given a non negative integer number num. For every numbers i in the range 0
 * ≤ i ≤ num calculate the number of 1's in their binary representation and
 * return them as an array.
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: [0,1,1]
 * 
 * Example 2:
 * 
 * 
 * Input: 5
 * Output: [0,1,1,2,1,2]
 * 
 * 
 * Follow up:
 * 
 * 
 * It is very easy to come up with a solution with run time
 * O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a
 * single pass?
 * Space complexity should be O(n).
 * Can you do it like a boss? Do it without using any builtin function like
 * __builtin_popcount in c++ or in any other language.
 * 
 */

// @lc code=start
#define INT_SIZE 32

class Solution
{
public:
    vector<int> countBitsBruteForce(int num)
    {
        vector<int> ans;
        for (int i = 0; i <= num; i++)
        {
            int count = 0;
            for (int j = 0; j < INT_SIZE; j++)
            {
                if ((i >> j) & 1)
                {
                    count++;
                }
            }
            ans.push_back(count);
        }

        return ans;
    }

    vector<int> countBitsDPSpeedOptimize(int num)
    {
        int dp[num + 1];
        memset(dp, 0, sizeof(dp));

        vector<int> ans;
        for (int i = 0; i <= num; i++)
        {
            int count = dp[i / 2];
            count += i & 1;
            dp[i] = count;

            ans.push_back(count);
        }

        return ans;
    }

    vector<int> countBitsDPMemOptimize(int num)
    {
        vector<int> ans(num + 1, 0);
        for (int i = 0; i <= num; i++)
        {
            int count = ans[i / 2];
            count += i & 1;
            ans[i] = count;
        }

        return ans;
    }

    vector<int> countBits(int num)
    {
        return countBitsBruteForce(num);
    }
};
// @lc code=end
