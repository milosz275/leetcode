#include <bits/stdc++.h>

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

class Solution
{
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (!head || k == 1) return head;
        
        // new list to reconstruct the reversed k-groups
        list<ListNode*> new_list;
        
        // k-sized stack for reversing groups
        stack<ListNode*> s;
        
        ListNode* ptr = head;
        bool stop = false;
        while (1)
        {
            // skipping k times to establish if full k-sized group is present
            ListNode* fast = ptr;
            for (int i = 0; i < k; ++i)
            {
                if (fast == nullptr)
                {
                    stop = true;
                    break;
                }
                fast = fast->next;
            }
            if (stop)
                break;

            // pushing k-sized group to stack
            for (int i = 0; i < k; ++i)
            {
                s.push(ptr);
                ptr = ptr->next;
            }

            // emptying stack into new list
            while (!s.empty())
            {
                new_list.push_back(s.top());
                s.pop();
            }
        }

        // append the rest normally
        while (ptr != nullptr)
        {
            new_list.push_back(ptr);
            ptr = ptr->next;
        }

        // reconstruct the list from head
        head = new_list.front();
        new_list.pop_front();
        ptr = head;
        for (ListNode* node: new_list)
        {
            ptr->next = node;
            ptr = ptr->next;
        }
        ptr->next = nullptr;
        return head;
    }
};
    
void print_tree(ListNode* head)
{
    ListNode* ptr = head;
    while (ptr != nullptr)
    {
        cout << ptr->val << ' ';
        ptr = ptr->next;
    }
    cout << '\n';
}

void delete_tree(ListNode* head)
{
    stack<ListNode*> s;
    ListNode* ptr = head;
    while (ptr != nullptr)
    {
        s.push(ptr);
        ptr = ptr->next;
    }
    while (!s.empty())
    {
        ptr = s.top();
        s.pop();
        delete ptr;
    }
}

int main()
{
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    print_tree(head);
    head = Solution().reverseKGroup(head, 2);
    print_tree(head);
    delete_tree(head);
    return 0;
}
