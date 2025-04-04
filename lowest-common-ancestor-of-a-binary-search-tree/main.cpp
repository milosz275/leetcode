#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        queue<TreeNode*> process_queue;
        process_queue.push(root);
        while (!process_queue.empty())
        {
            TreeNode* node = process_queue.front();
            process_queue.pop();

            if (node == p || node == q)
                return node;

            int a1 = min(p->val, q->val);
            int a2 = max(p->val, q->val);

            if (node->val > a1 && node->val < a2)
                return node;

            if (node->left)
                process_queue.push(node->left);
            if (node->right)
                process_queue.push(node->right);
        }
        return NULL;
    }
};
    
int main()
{
    unique_ptr<TreeNode> root(make_unique<TreeNode>(6));
    unique_ptr<TreeNode> p(make_unique<TreeNode>(2));
    unique_ptr<TreeNode> q(make_unique<TreeNode>(8));
    root->left = p.get();
    root->right = q.get();
    cout << "output: " << Solution().lowestCommonAncestor(root.get(), p.get(), q.get())->val << '\n';
    return 0;
}
