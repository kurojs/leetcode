// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem238.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (60.14%)
 * Likes:    5280
 * Dislikes: 434
 * Total Accepted:    570.9K
 * Total Submissions: 949.2K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an array nums of n integers where n > 1,  return an array output such
 * that output[i] is equal to the product of all the elements of nums except
 * nums[i].
 * 
 * Example:
 * 
 * 
 * Input:  [1,2,3,4]
 * Output: [24,12,8,6]
 * 
 * 
 * Constraint: It's guaranteed that the product of the elements of any prefix
 * or suffix of the array (including the whole array) fits in a 32 bit
 * integer.
 * 
 * Note: Please solve it without division and in O(n).
 * 
 * Follow up:
 * Could you solve it with constant space complexity? (The output array does
 * not count as extra space for the purpose of space complexity analysis.)
 * 
 */

// @lc code=start
#include <unordered_map>
#include <vector>
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> prefix, subfix;
        int n = nums.size();
        if (n < 1) {
            return ans;
        }

        prefix[-1] = 1;
        prefix[0] = nums[0];
        subfix[n] = 1;
        subfix[n - 1] = nums[n-1];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] * nums[i];
        }

        for (int i = n - 2; i >= 0; i--) {
            subfix[i] = subfix[i + 1] * nums[i];
        }

        for (int i = 0; i < n; i++) {
            ans.push_back(prefix[i - 1] * subfix[i + 1]);
        }

        return ans;
    }
};
// @lc code=end

