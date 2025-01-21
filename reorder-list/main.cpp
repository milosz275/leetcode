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
    void reorderList(ListNode* head)
    {
        if (head == nullptr)
            return;
        deque<int> val_deque;
        ListNode* current = head->next;
        while (current != nullptr)
        {
            val_deque.push_back(current->val);
            current = current->next;
        }
        current = head;
        while (!val_deque.empty())
        {
            current->next = new ListNode(val_deque.back());
            val_deque.pop_back();
            current = current->next;
            if (!val_deque.empty())
            {
                current->next = new ListNode(val_deque.front());
                val_deque.pop_front();
                current = current->next;
            }
        }
        current->next = nullptr;
        return;    
    }
};

int main()
{

    return 0;
}
