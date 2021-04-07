/*

https://leetcode.com/problems/merge-two-sorted-lists

Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* curr = dummyNode;

        if(l1 == NULL){
            return l2;
        }

        if(l2 == NULL){
            return l1;
        }

        while(l1 != NULL && l2 != NULL){
            if(l1 -> val <= l2 -> val){
                curr -> next = l1;
                curr = l1;
                l1 = l1 -> next;
            }

            else{
                curr -> next = l2;
                curr = l2;
                l2 = l2 -> next;
            }
        }

        if(l1 != NULL){
            curr -> next = l1;
        }

        if(l2 != NULL){
            curr -> next = l2;
        }

        return dummyNode -> next;
        }
};