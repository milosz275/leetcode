#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class FindElements
{
private:
    unordered_map<int, bool> tree;

public:
    FindElements(TreeNode* root)
    {
        if (!root)
            return;
        queue<pair<TreeNode*, int>> q; // (node, value)
        q.push({root, 0});
        while (!q.empty())
        {
            auto [node, current_val] = q.front();
            q.pop();

            tree[current_val] = true;
            if (node->left)
                q.push({node->left, 2 * current_val + 1});
            if (node->right)
                q.push({node->right, 2 * current_val + 2});
        }
    }
    
    bool find(int target)
    {
        return tree[target];
    }
};

int main()
{
    
    return 0;
}
