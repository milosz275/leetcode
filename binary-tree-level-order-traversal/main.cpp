#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> answer = {};
        if (root)
        {
            queue<pair<TreeNode*, int>> node_queue; // the first is the node, the second is a level
            node_queue.push({root, 0});
            while (!node_queue.empty())
            {
                TreeNode* current = node_queue.front().first;
                int level = node_queue.front().second;
                node_queue.pop();
                
                if ((int)answer.size() > level)
                    answer[level].push_back(current->val);
                else
                    answer.push_back(vector<int>{current->val});

                level++;
                if (current->left)
                    node_queue.push({current->left, level});
                if (current->right)
                    node_queue.push({current->right, level});
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
    TreeNode* root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    Solution sol;
    vector<vector<int>> answer = sol.levelOrder(root);
    for (vector<int>& array: answer)
    {
        for (int el: array)
            cout << el << " ";
        cout << endl;
    }
    delete_tree(root);
    return 0;
}
