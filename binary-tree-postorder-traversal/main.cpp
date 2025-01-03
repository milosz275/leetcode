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
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> answer = {};
        if (root)
        {
            stack<TreeNode*> node_stack;
            stack<TreeNode*> output_stack;
            node_stack.push(root);
            while (!node_stack.empty())
            {
                TreeNode* current = node_stack.top();
                node_stack.pop();
                output_stack.push(current);
                if (current->left)
                    node_stack.push(current->left);
                if (current->right)
                    node_stack.push(current->right);
            }
            while (!output_stack.empty())
            {
                answer.push_back(output_stack.top()->val);
                output_stack.pop();
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
    TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5, new TreeNode(6), new TreeNode(7))), new TreeNode(3, NULL, new TreeNode(8, new TreeNode(9), NULL)));
    Solution sol;
    vector<int> preorder = sol.postorderTraversal(root);
    for (int el: preorder)
        cout << el << ", ";
    cout << endl;
    delete_tree(root);
    return 0;
}
