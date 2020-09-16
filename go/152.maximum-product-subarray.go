/*
 * @lc app=leetcode id=152 lang=golang
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (31.74%)
 * Likes:    5030
 * Dislikes: 174
 * Total Accepted:    387.3K
 * Total Submissions: 1.2M
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find the contiguous subarray within an array
 * (containing at least one number) which has the largest product.
 *
 * Example 1:
 *
 *
 * Input: [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 *
 *
 * Example 2:
 *
 *
 * Input: [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 *
 */

// @lc code=start
func maxProduct(nums []int) int {
	maxProduct, minProduct := nums[0], nums[0]
	ans := maxProduct

	for _, n := range nums[1:] {
		if n < 0 {
			maxProduct, minProduct = minProduct, maxProduct
		}

		if p := maxProduct * n; n > p {
			maxProduct = n
		} else {
			maxProduct = p
		}

		if p := minProduct * n; n < p {
			minProduct = n
		} else {
			minProduct = p
		}

		if maxProduct > ans {
			ans = maxProduct
		}
	}

	return ans
}

// @lc code=end

