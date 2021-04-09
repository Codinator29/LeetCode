/*

https://leetcode.com/problems/merge-k-sorted-lists/

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto pred = [](ListNode* l1, ListNode* l2){
            return l1->val > l2->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(pred)> pq(pred);
        for(ListNode* p : lists){
            if(p) pq.push(p);
        }
        ListNode dummy(0);
        ListNode *head = &dummy;
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            head->next = new ListNode(node->val);
            head = head->next;
            if(node->next) pq.push(node->next);
        }
        return dummy.next;
    }
};