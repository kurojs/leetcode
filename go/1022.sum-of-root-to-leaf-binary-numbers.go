/*
 * @lc app=leetcode id=1022 lang=golang
 *
 * [1022] Sum of Root To Leaf Binary Numbers
 *
 * https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/
 *
 * algorithms
 * Easy (67.23%)
 * Likes:    730
 * Dislikes: 75
 * Total Accepted:    64.8K
 * Total Submissions: 92.2K
 * Testcase Example:  '[1,0,1,0,1,0,1]'
 *
 * Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path
 * represents a binary number starting with the most significant bit.  For
 * example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent
 * 01101 in binary, which is 13.
 *
 * For all leaves in the tree, consider the numbers represented by the path
 * from the root to that leaf.
 *
 * Return the sum of these numbers.
 *
 *
 *
 * Example 1:
 *
 *
 *
 *
 * Input: [1,0,1,0,1,0,1]
 * Output: 22
 * Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 *
 *
 *
 *
 * Note:
 *
 *
 * The number of nodes in the tree is between 1 and 1000.
 * node.val is 0 or 1.
 * The answer will not exceed 2^31 - 1.
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func sumRootToLeaf(root *TreeNode) int {
	return sum(root, 0)
}

func sum(root *TreeNode, prev int) int {
	if root == nil {
		return 0
	}

	curr := (prev << 1) | root.Val
	leavesSum := sum(root.Left, curr) + sum(root.Right, curr)

	if leavesSum == 0 {
		return curr
	}
	return leavesSum
}

// @lc code=end

