#include <iostream>
#include <queue>

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
    int maxLevelSum(TreeNode* root) 
    {
        if (!root)
            return 0;

        queue<pair<TreeNode*, int>> node_queue; // int represents node's level starting from 1
        node_queue.push({root, 1});

        int maximal_sum = root->val;
        int sum_level = 1;

        int current_sum = 0;
        int current_level_sum = 1;

        while (!node_queue.empty())
        {
            TreeNode* current = node_queue.front().first;
            int level = node_queue.front().second;

            if (level != current_level_sum)
            {
                if (current_sum > maximal_sum)
                {
                    maximal_sum = current_sum;
                    sum_level = current_level_sum;
                }
                current_level_sum = level;
                current_sum = current->val;
            }
            else // level == current_level_sum
                current_sum += current->val;

            node_queue.pop();
            if (current->left)
                node_queue.push({current->left, level + 1});
            if (current->right)
                node_queue.push({current->right, level + 1});
        }
        if (current_sum > maximal_sum)
        {
            maximal_sum = current_sum;
            sum_level = current_level_sum;
        }

        return sum_level;
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
    TreeNode* root = new TreeNode(1, new TreeNode(7, new TreeNode(7), new TreeNode(-8)), new TreeNode(0));
    Solution sol;
    cout << "output: " << sol.maxLevelSum(root) << endl;
    delete_tree(root);
    return 0;
}
