// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem328.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
 *
 * https://leetcode.com/problems/odd-even-linked-list/description/
 *
 * algorithms
 * Medium (55.83%)
 * Likes:    2059
 * Dislikes: 305
 * Total Accepted:    293.5K
 * Total Submissions: 525.7K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given a singly linked list, group all odd nodes together followed by the
 * even nodes. Please note here we are talking about the node number and not
 * the value in the nodes.
 * 
 * You should try to do it in place. The program should run in O(1) space
 * complexity and O(nodes) time complexity.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->4->5->NULL
 * Output: 1->3->5->2->4->NULL
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 2->1->3->5->6->4->7->NULL
 * Output: 2->3->6->7->1->5->4->NULL
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The relative order inside both the even and odd groups should remain as it
 * was in the input.
 * The first node is considered odd, the second node even and so on ...
 * The length of the linked list is between [0, 10^4].
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *next = head;
        if (!head) {
            return head;
        }

        ListNode *oddList = new ListNode(head->val);
        ListNode *evenList = head->next != nullptr ? new ListNode(head->next->val) : nullptr;
        ListNode *odd = head->next != nullptr ? head->next->next : nullptr;
        ListNode *even = odd != nullptr ? odd->next : nullptr;

        while (odd != nullptr && even != nullptr)
        {
            append(oddList, new ListNode(odd->val));
            append(evenList, new ListNode(even->val));

            odd = even->next;
            even = odd != nullptr ? odd->next : nullptr;
        }

        append(oddList, odd);
        append(evenList, even);
        append(oddList, evenList);
        return oddList;
    }

    ListNode* append(ListNode* head, ListNode* node) {
        if (!head) {
            return node;
        }

        ListNode* next = head;
        while (next->next != nullptr) {
            next = next->next;
        }

        next->next = node;
        return head;
    }

};
// @lc code=end

/*

1 -> 2 -> 3 -> 4 -> 5 -> null

odd: 1
even: 2

odd: 3
even: 4



*/