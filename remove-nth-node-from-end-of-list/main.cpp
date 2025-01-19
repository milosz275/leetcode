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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        // two pointers
        ListNode* current = head;
        ListNode* remove_next = head; // (n - 1)th from the end

        // move n steps ahead to maintain wanted gap
        for (int i = 0; i < n; ++i)
        {
            if (current == nullptr)
                return head; // n is larger than the length of the list
            current = current->next;
        }

        // n matching list length - removing head
        if (current == nullptr)
        {
            ListNode* removed = head;
            head = head->next;
            delete removed;
            return head;
        }

        // move pointer window to the end of the list
        while (current->next != nullptr)
        {
            current = current->next;
            remove_next = remove_next->next;
        }

        // remove the nth node from the end
        ListNode* removed = remove_next->next;
        remove_next->next = remove_next->next->next;
        removed->next = nullptr;
        delete removed;

        return head;
    }
};

void delete_list(ListNode* ptr)
{
    ListNode* tmp = ptr->next;
    if (tmp)
        delete_list(tmp);
    delete ptr;
}

int main()
{
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    head = Solution().removeNthFromEnd(head, 2);
    delete_list(head);
    return 0;
}
