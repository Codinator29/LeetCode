/*

https://leetcode.com/problems/add-two-numbers/

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head;
        ListNode* temp;
        ListNode* prev;
        int carryOn = 0, sum;
        
        head = new ListNode();
        head -> next = temp;
        prev = head;
        while(l1 != NULL && l2 != NULL)
        {
            sum = l1 -> val + l2 -> val + carryOn;
            temp = new ListNode();
            
            if(sum > 9)
            {
                sum = sum - 10;
                carryOn = 1;
            }
            else
            {
                carryOn = 0;
            }
            
            temp -> val = sum;
            
            prev-> next = temp;
            temp = temp -> next;
            prev = prev -> next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        
        while(l1 != NULL)
        {
            sum = l1 -> val + carryOn;
            temp = new ListNode();
            
            if(sum > 9)
            {
                sum = sum - 10;
                carryOn = 1;
            }
            else
            {
                carryOn = 0;
            }
            
            temp -> val = sum;
            
            prev-> next = temp;
            temp = temp -> next;
            prev = prev -> next;
            l1 = l1 -> next;
        }
        
        while(l2 != NULL)
        {
            sum = l2 -> val + carryOn;
            temp = new ListNode();
            
            if(sum > 9)
            {
                sum = sum - 10;
                carryOn = 1;
            }
            else
            {
                carryOn = 0;
            }
            
            temp -> val = sum;
            
            prev-> next = temp;
            temp = temp -> next;
            prev = prev -> next;
            l2 = l2 -> next;
        }
        
        if(carryOn == 1)
        {
            temp = new ListNode();
            temp -> val = 1;
            prev -> next = temp;
        }

        return head -> next;
    }
};