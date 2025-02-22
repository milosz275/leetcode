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
    TreeNode* recoverFromPreorder(string traversal)
    {
        // (node, level)
        stack<pair<TreeNode*, int>> st;
        int i = 0;

        // interate through traversal string
        while (i < traversal.size())
        {
            int level = 0;

            // count the dashes to determine current level
            while (i < traversal.size() && traversal[i] == '-')
            {
                level++;
                i++;
            }

            int value = 0;

            // parse numeric value of current node
            while (i < traversal.size() && isdigit(traversal[i]))
            {
                value = value * 10 + (traversal[i] - '0');
                i++;
            }

            // allocate new node
            TreeNode* node = new TreeNode(value);
            while (!st.empty() && st.top().second >= level)
                st.pop();

            // attach node to proper place using stack
            if (!st.empty())
            {
                if (!st.top().first->left)
                    st.top().first->left = node;
                else
                    st.top().first->right = node;
            }

            // push new node to the top of the stack
            st.push({node, level});
        }

        // drop all elements of the stack to uncover the root
        while (st.size() > 1)
            st.pop();
        return st.top().first;
    }
};

void bfs_print(TreeNode* root)
{
    if (!root)
        return;
    queue<TreeNode*> q;
    q.push(root);
    cout << "[";
    while (!q.empty())
    {
        TreeNode* t = q.front();
        q.pop();
        cout << t->val << ", ";
        if (t->left)
            q.push(t->left);
        if (t->right)
            q.push(t->right);
    }
    cout << "]\n";
}

void delete_tree(TreeNode* root)
{
    if (root)
    {
        if (root->left)
            delete_tree(root->left);
        if (root->right)
            delete_tree(root->right);
        delete root;
    }
}

int main()
{
    string traversal("1-2--3--4-5--6--7");
    TreeNode* tree = Solution().recoverFromPreorder(traversal);
    bfs_print(tree);
    delete_tree(tree);
    return 0;
}
