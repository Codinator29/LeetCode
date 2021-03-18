/*

https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        /*if(root == nullptr)
        {
            return root;
        }
        
        if(root->left == nullptr && root->right == nullptr)
        {
            return root;
        }
        queue<Node*> q;
        int count = 1;
        q.push(root);
        
        while(!q.empty())
        {
            Node* n = q.front();
            q.pop();
            
            if(n -> left != nullptr)
                q.push(n->left);
            if(n -> right != nullptr)
                q.push(n->right);
            int i = 1;
            while(i < count)
            {
                Node *m = q.front();
                q.pop();
                
                if(m -> left != nullptr)
                    q.push(m->left);
                if(m -> right != nullptr)
                    q.push(m -> right);
                n -> next = m;
                n = m;
                i++;
            }
            
            count = count * 2;
        }
        return root;*/

       if (root == nullptr)
            return root;
        std::deque<Node *>queue(1, root);
        while (!queue.empty()) {
            int count = queue.size();
            for (int i = 0; i < count; ) {
                Node *curQNode = queue.front();
                queue.pop_front();
                if (curQNode->left) {
                    queue.push_back(curQNode->left);
                    queue.push_back(curQNode->right);
                }
                if (++i < count)
                    curQNode->next = queue.front(); 
            }
        }
        return root;
        
    }
};