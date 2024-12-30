#include <iostream>
#include <vector>
#include <stack>

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
    void print_list(ListNode* head)
    {
        int i = 1;
        ListNode* ptr = head;
        while (ptr != NULL)
        {
            std::cout << i << ": " << ptr->val << std::endl;
            ptr = ptr->next;
            i++;
        }
    }

    ListNode* create_list(ListNode* ptr, vector<int>& nums)
    {
        ListNode* last_ptr = ptr;

        if (last_ptr == NULL)
            last_ptr = new ListNode(nums[0]);
        else
            last_ptr->next = new ListNode(nums[0]);

        ListNode* head = last_ptr;

        while (last_ptr->next != NULL)
            last_ptr = last_ptr->next;
        
        for (int i = 1; i < (int)nums.size(); ++i)
        {
            last_ptr->next = new ListNode(nums[i]);
            last_ptr = last_ptr->next;
        }
        last_ptr->next = NULL;

        return head;
    }

    void delete_element(ListNode* element)
    {
        while (element != nullptr)
        {
            ListNode* temp = element;
            element = element->next;
            delete temp;
        }
    }

    void delete_list(ListNode* head)
    {
        delete_element(head);
    }

    ListNode* reverseList(ListNode* head)
    {
        if (head == NULL)
            return NULL;
        ListNode* ptr = head;
        stack<ListNode*> ptrs;
        while (ptr != NULL)
        {
            ptrs.push(ptr);
            ptr = ptr->next;
        }
        ListNode* new_head = ptr = ptrs.top();
        ptrs.pop();
        while (!ptrs.empty())
        {
            ptr->next = ptrs.top();
            ptrs.pop();
            ptr = ptr->next;
        }
        ptr->next = NULL;
        return new_head;
    }
};

int main()
{
    ListNode* head = NULL;
    vector<int> nums = { 1, 2, 3, 4, 5 };
    Solution solution;
    head = solution.create_list(head, nums);
    head = solution.reverseList(head);
    solution.print_list(head);
    solution.delete_list(head);
    return 0;
}
