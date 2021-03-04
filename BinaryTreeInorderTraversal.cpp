/*

https://leetcode.com/problems/binary-tree-inorder-traversal/

Given the root of a binary tree, return the inorder traversal of its nodes' values.

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        
        inorderTraversal(root, result);
        return result;
    }
    
    void inorderTraversal(TreeNode* node, vector<int> &result)
    {
        if(node == NULL)
        {
            return;
        }
        
        inorderTraversal(node->left, result);
        result.push_back(node->val);
        inorderTraversal(node->right, result);
    }
};