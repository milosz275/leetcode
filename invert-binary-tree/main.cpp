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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode* invertTree(TreeNode* root)
    {
        if (root == nullptr)
            return nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode* current = q.front();
            q.pop();
            TreeNode* tmp = current->left;
            current->left = current->right;
            current->right = tmp;
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
        return root;
    }
};

int main()
{

    return 0;
}
