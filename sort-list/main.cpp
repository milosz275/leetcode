#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void print_list(ListNode* head)
{
    ListNode* ptr = head;
    while (ptr != NULL)
    {
        cout << "value: " << ptr->val << endl;
        ptr = ptr->next;
    }
    return;
}

void delete_list(ListNode* ptr)
{
    ListNode* tmp = ptr->next;
    if (tmp)
        delete_list(tmp);
    delete ptr;
}

class Solution
{
public:
    ListNode* merge(ListNode* head_left, ListNode* head_right)
    {
        // base case
        if (head_left == NULL)
            return head_right;
        else if (head_right == NULL)
            return head_left;
        
        // recursive
        if (head_left->val < head_right->val)
        {
            head_left->next = merge(head_left->next, head_right);
            return head_left;
        }
        else
        {
            head_right->next = merge(head_right->next, head_left);
            return head_right;
        }
    }

    ListNode* sortList(ListNode* head)
    {
        if (!head)
            return NULL;

        // base case
        if (head->next == NULL)
            return head;

        // recursive case
        ListNode* middle = head; // slow
        ListNode* middle_prev = head;
        ListNode* right = head; // fast

        while (right->next != NULL)
        {
            middle_prev = middle;
            middle = middle->next;
            if (right->next->next)
                right = right->next->next;
            else
                right = right->next;
        }
        middle_prev->next = NULL;

        ListNode* head_left = sortList(head);
        ListNode* head_right = sortList(middle);
        head_left = merge(head_left, head_right);
        return head_left;
    }
};

int main()
{
    ListNode* head = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3, NULL))));
    Solution sol;
    head = sol.sortList(head);
    print_list(head);
    delete_list(head);
    return 0;
}
