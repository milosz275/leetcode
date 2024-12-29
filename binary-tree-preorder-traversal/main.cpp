#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

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
    /**
     * Recursive function to push node values into array
     */
    void set_value(TreeNode* node, vector<int>& array)
    {
        array.push_back(node->val);
        if (node->left == NULL && node->right == NULL)
            return;
        if (node->left)
            set_value(node->left, array);
        if (node->right)
            set_value(node->right, array);
    }

    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> answer = {};
        // if (root) // recursive
        //     set_value(root, answer);
        if (root) // iterative
        {
            stack<TreeNode*> node_stack;
            node_stack.push(root);
            while (!node_stack.empty())
            {
                TreeNode* current = node_stack.top();
                node_stack.pop();
                answer.push_back(current->val);
                if (current->right)
                    node_stack.push(current->right);
                if (current->left)
                    node_stack.push(current->left);
            }
        }
        return answer;
    }
};

void delete_tree(TreeNode* root)
{
    if (root == nullptr)
        return;
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}

int main()
{
    TreeNode* root = new TreeNode(1, NULL, new TreeNode(2, new TreeNode(3, NULL, NULL), NULL));
    Solution sol;
    vector<int> preorder = sol.preorderTraversal(root);
    for (int el: preorder)
        cout << el << ", ";
    cout << endl;
    delete_tree(root);
    return 0;
}
