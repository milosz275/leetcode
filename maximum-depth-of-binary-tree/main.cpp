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

class Solution
{
public:
    int maxDepth(TreeNode* root)
    {
        if (!root)
            return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int level = 0;
        while (!q.empty())
        {
            TreeNode* t = q.front().first;
            level = max(level, q.front().second);
            q.pop();

            if (t->left)
                q.push({t->left, level + 1});
            if (t->right)
                q.push({t->right, level + 1});
        }
        return level;
    }
};

int main()
{
    TreeNode* root = new TreeNode(1, nullptr, new TreeNode(2));
    cout << "max depth: " << Solution().maxDepth(root) << '\n';
    delete root->right;
    delete root;
    return 0;
}
