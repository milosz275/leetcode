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
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        if (!p && !q)
            return true;
        else if ((p && !q) || (!p && q))
            return false;
        queue<pair<TreeNode*, TreeNode*>> nodes;
        nodes.push({p, q});
        while (!nodes.empty())
        {
            auto [pt, qt] = nodes.front();
            nodes.pop();
            
            if ((pt && !qt) || (!pt && qt) || pt->val != qt->val)
                return false;
            if (pt->left || qt->left)
                nodes.push({pt->left, qt->left});
            if (pt->right || qt->right)
                nodes.push({pt->right, qt->right});
        }
        return true;
    }
};

int main()
{
    TreeNode* p2 = new TreeNode(2), * p3 = new TreeNode(3);
    TreeNode* p = new TreeNode(1, p2, p3);
    TreeNode* q2 = new TreeNode(2), * q3 = new TreeNode(3);
    TreeNode* q = new TreeNode(1, q2, q3);
    cout << "is the same tree: " << Solution().isSameTree(p, q) << '\n';
    delete p2; delete p3; delete p; delete q2; delete q3; delete q;
    return 0;
}
