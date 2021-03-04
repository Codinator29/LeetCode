/*
https://leetcode.com/problems/odd-even-linked-list/

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

*/
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
    ListNode *cur, *second, *next, *nextNext;
    if (head == nullptr || head->next == nullptr || head->next->next == nullptr) return head;

    second = head->next;
    cur = head;

    while (cur->next != nullptr) {
        next = cur->next;
        nextNext = nullptr;
        
        if (next->next != nullptr) {
            nextNext = next->next;
            next->next = nextNext->next;
        }

        cur->next = nextNext;
        if (nextNext != nullptr) cur = nextNext;
    }

    cur->next = second;
    return head;
    }
};