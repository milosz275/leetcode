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
    ListNode* oddEvenList(ListNode* head)
    {
        if (!head)
            return NULL;
        list<ListNode*> odd;
        list<ListNode*> even;
        ListNode* current = head;
        bool is_odd = true;
        while (current != NULL)
        {
            if (is_odd)
                odd.push_back(current);
            else
                even.push_back(current);
            current = current->next;
            is_odd = !is_odd; 
        }
        
        current = head;
        auto it = odd.begin();
        it++;
        for (; it != odd.end(); ++it)
        {
            current->next = *it;
            current = current->next;
        }
        it = even.begin();
        for (; it != even.end(); ++it)
        {
            current->next = *it;
            current = current->next;
        }
        current->next = NULL;
        return head;
    }
};

int main()
{

    return 0;
}
