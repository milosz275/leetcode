#include <iostream>
#include <vector>
#include <stack>

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

class BSTIterator
{
public:
    vector<TreeNode*>* node_array;
    int current_index;

    BSTIterator(TreeNode* root) : node_array(NULL), current_index(0)
    {
        stack<TreeNode*> node_stack;
        TreeNode* current = root;
        node_array = new vector<TreeNode*>{};

        while (current != nullptr || !node_stack.empty())
        {
            while (current != nullptr)
            {
                node_stack.push(current);
                current = current->left;
            }
            current = node_stack.top();
            node_stack.pop();
            node_array->push_back(current);
            current = current->right;
        }
    }

    ~BSTIterator()
    {
        if (node_array)
            delete node_array;
    }
    
    int next()
    {
        if (!node_array)
            return -1; // no array code
        int length = (int)node_array->size();
        if (length <= 0)
            return -2; // empty array code
        if (current_index >= length)
            current_index = 0; // rewind to beginning if domain is exceeded
        return (*node_array)[current_index++]->val; // return current value and increment
    }
    
    bool hasNext()
    {
        return current_index < (int)node_array->size();
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
    TreeNode* root = new TreeNode(7, new TreeNode(3), new TreeNode(15, new TreeNode(9), new TreeNode(20)));
    BSTIterator* obj = new BSTIterator(root);

    int param_1 = obj->next();
    cout << param_1 << " ";

    param_1 = obj->next();
    cout << param_1 << " ";

    bool param_2 = obj->hasNext();
    cout << param_2 << " ";

    param_1 = obj->next();
    cout << param_1 << " ";

    param_2 = obj->hasNext();
    cout << param_2 << " ";

    param_1 = obj->next();
    cout << param_1 << " ";

    param_2 = obj->hasNext();
    cout << param_2 << " ";

    param_1 = obj->next();
    cout << param_1 << " ";

    param_2 = obj->hasNext();
    cout << param_2 << endl;

    delete_tree(root);
    delete(obj);
    return 0;
}
