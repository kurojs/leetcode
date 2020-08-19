/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (48.35%)
 * Likes:    2353
 * Dislikes: 103
 * Total Accepted:    397.3K
 * Total Submissions: 821.5K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
 * ⁠ [15,7]
 * ]
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        
        unordered_map<int, vector<int>> tree;
        int level = buildTree(root, 0, tree);
        for (int i = 0; i < level; i++) {
            vector<int> row = tree[i];
            vector<int> zigzag;
            if (i % 2 == 0) {
                for (int j = 0; j < row.size(); j++) {
                    zigzag.push_back(row[j]);
                }
            } else {
                for (int j = row.size() - 1; j >= 0; j--) {
                    zigzag.push_back(row[j]);
                }
            }
            
            ans.push_back(zigzag);
        }
        
        return ans;
    }
    
    int buildTree(TreeNode* node, int level, unordered_map<int, vector<int>>& tree) {
        if (!node) {
            return level;
        }
        
        if (tree.find(level) == tree.end()) {
            tree[level] = vector<int>();
        }
        tree[level].push_back(node->val);
        
        return max(buildTree(node->left, level + 1, tree), buildTree(node->right, level + 1, tree));
    }
};
// @lc code=end

