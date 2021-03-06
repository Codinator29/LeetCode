/*

https://leetcode.com/problems/kth-smallest-element-in-a-bst/

Given the root of a binary search tree, and an integer k, return the kth (1-indexed) smallest element in the tree.

*/

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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0; 
        TreeNode* res = kthSmallest(root, count, k);
        return res->val;
    }
    
TreeNode* kthSmallest(TreeNode* root, int& count, int k) 
{ 
    // base case 
    if (root == NULL) 
        return NULL; 
  
    // search in left subtree 
    TreeNode* left = kthSmallest(root->left, count, k); 
  
    // if k'th smallest is found in left subtree, return it 
    if (left != NULL) 
        return left; 
  
    // if current element is k'th smallest, return it 
    count++; 
    if (count == k) 
        return root; 
  
    // else search in right subtree 
    return kthSmallest(root->right, count, k); 
}  
};