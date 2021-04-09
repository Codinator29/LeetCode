/*

https://leetcode.com/problems/swap-nodes-in-pairs/

Given a linked list, swap every two adjacent nodes and return its head.

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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) 
        {
            return head;
        }
        
        ListNode* current = head;
        ListNode* next = NULL, *prev = NULL;
        int k1 = 0;
        while(current != NULL && k1 < 2){
            next = current -> next;
            current -> next = prev;
            prev = current;
            current = next;
            k1++;
        }
        
        if(next != NULL) 
        {
            head -> next = swapPairs(next);
        }
        
        return prev;
    }
};