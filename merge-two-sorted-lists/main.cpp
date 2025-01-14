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
    struct Compare
    {
        bool operator()(ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        }
    };

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (!list1 && !list2)
            return NULL;
        else if (!list1)
            return list2;
        else if (!list2)
            return list1;
        priority_queue<ListNode*, vector<ListNode*>, Compare> min_heap;
        ListNode* current = list1;
        while (current != NULL)
        {
            min_heap.push(current);
            current = current->next;
        }
        current = list2; 
        while (current != NULL)
        {
            min_heap.push(current);
            current = current->next;
        }
        ListNode* head = min_heap.top();
        min_heap.pop();
        current = head;
        while (!min_heap.empty())
        {
            current->next = min_heap.top(); // dereferencing previous order
            min_heap.pop();
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
