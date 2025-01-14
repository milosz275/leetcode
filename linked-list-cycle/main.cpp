#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* create_list(const vector<int>& array, int pos)
{
    if (array.size() == 0)
        return NULL;
    ListNode* head = new ListNode(array[0]);
    ListNode* current = head;
    ListNode* cycling_node = NULL;
    for (int i = 1; i < (int)array.size(); ++i)
    {
        current->next = new ListNode(array[i]);
        current = current->next;
        if (i == pos)
            cycling_node = current;
    }
    if (pos == 0)
        current->next = head;
    else
        current->next = cycling_node;
    return head;
}

void print_list(ListNode* head)
{
    ListNode* current = head;
    set<ListNode*> visited;
    while (current != NULL)
    {
        if (visited.find(current) != visited.end())
            break;
        visited.insert(current);
        cout << current->val << endl;
        current = current->next;
    }
    if (current) // if cycle exists
        cout << "next in cycle: " << current->val << endl;
}

void delete_list(ListNode* head, set<ListNode*>* handled = NULL)
{
    bool created = false;
    if (!handled)
    {
        handled = new set<ListNode*>;
        created = true;
    }
    handled->insert(head);
    if (handled->find(head->next) == handled->end() && head->next)
        delete_list(head->next, handled);
    delete head;
    if (created)
        delete handled;
}

class Solution
{
public:
    /**
     * Check if the list has a cycle using set<ListNode*>
     */
    bool has_cycle_2(ListNode* head)
    {
        ListNode* current = head;
        set<ListNode*> visited;
        while (current != NULL)
        {
            if (visited.find(current) != visited.end())
                return true;
            visited.insert(current);
            current = current->next;
        }
        return false;
    }

    /**
     * Check if the list has a cycle using fast and slow pointers
     */
    bool hasCycle(ListNode* head)
    {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != NULL)
        {
            slow = slow->next;

            fast = fast->next;
            if (fast == NULL)
                return false;

            fast = fast->next;

            if (slow == fast)
                return true;
        }
        return false;
    }
};

int main()
{
    vector<int> input = {3,2,0,-4};
    int pos = 1;
    ListNode* head = create_list(input, pos);
    print_list(head);

    cout << "Does the list contain a cycle? " << Solution().hasCycle(head) << endl;

    delete_list(head);
    return 0;
}
