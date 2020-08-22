/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (63.67%)
 * Likes:    4201
 * Dislikes: 108
 * Total Accepted:    638.8K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    void backtrack(int pos,
                   vector<int> &nums,
                   vector<vector<int>> &ans,
                   vector<int> per,
                   string key,
                   unordered_map<string, bool> &mp)
    {

        if (mp.find(key) != mp.end())
        {
            return;
        }
        mp[key] = true;

        int n = nums.size();
        if (per.size() == n)
        {
            ans.push_back(per);
            return;
        }

        if (pos >= n)
        {
            return;
        }

        for (int i = 0; i <= per.size(); i++)
        {
            vector<int> temp = per;
            temp.insert(temp.begin() + i, nums[pos]);
            backtrack(pos + 1, nums, ans, temp, key.insert(i, to_string(nums[pos])), mp);
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        if (nums.size() == 0)
        {
            return ans;
        }

        unordered_map<string, bool> mp;
        vector<int> per = {nums[0]};
        backtrack(1, nums, ans, per, to_string(nums[0]), mp);
        return ans;
    }
};
// @lc code=end
