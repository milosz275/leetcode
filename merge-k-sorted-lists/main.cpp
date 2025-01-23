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
private:
    struct Comparator
    {
        bool operator()(ListNode* A, ListNode* B)
        {
            return A->val > B->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if (lists.empty())
            return NULL;
        priority_queue<ListNode*, vector<ListNode*>, Comparator> min_heap;
        for (ListNode* head: lists)
        {
            if (head == NULL)
                continue;
            ListNode* current = head;
            while (current != NULL)
            {
                min_heap.push(current);
                current = current->next;
            }
        }
        if (min_heap.empty())
            return NULL;
        ListNode* head = min_heap.top();
        min_heap.pop();
        ListNode* current = head;
        while (!min_heap.empty())
        {
            current->next = min_heap.top();
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
