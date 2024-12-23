#include <iostream>
#include <deque>

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
    bool isPalindrome(ListNode* head)
    {
        ListNode* ptr = head;
        deque<ListNode*> queue;
        while (ptr != NULL)
        {
            queue.push_back(ptr);
            ptr = ptr->next;
        }
        // for (ListNode* node: queue)
        //     cout << "Node val: " << node->val << endl;
        while (!queue.empty())
        {
            // odd word length
            ListNode* upper = queue.front();
            ListNode* lower = queue.back();
            if (upper == lower)
                return true; // all characters are processed, only middle one left, e.g. r in waraw is both upper and lower
            
            // even word length
            if (upper->val != lower->val)
                return false;

            queue.pop_front();
            queue.pop_back();
        }
        return true; // all characters are processed, e.g. wawa
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
    ListNode* head = new ListNode(0, new ListNode(1, new ListNode(1, new ListNode(0, NULL))));
    Solution sol;
    bool result = sol.isPalindrome(head);
    if (result)
        cout << "The list is a palindrome" << endl;
    else
        cout << "The list is not a palindrome" << endl;
    delete_list(head);
    return 0;
}
