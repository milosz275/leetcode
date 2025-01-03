#include <iostream>
#include <vector>

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
    int length;
    vector<ListNode*>* array;

    Solution(ListNode* head)
    {
        length = 0;
        ListNode* ptr = head;
        while (ptr != NULL)
        {
            length++;
            ptr = ptr->next;
        }
        array = new vector<ListNode*>(length);
        ptr = head;
        for (int i = 0; i < length; ++i)
        {
            (*array)[i] = ptr;
            ptr = ptr->next;
        }
        srand(time(NULL));
    }

    ~Solution()
    {
        if (array)
            delete array;
    }
    
    int getRandom()
    {
        return (*array)[rand() % length]->val;
    }
};

ListNode* create_list(int n)
{
    if (n < 1)
        return NULL;
    ListNode* head = new ListNode(0, NULL);
    ListNode* ptr = head;
    for (int i = 1; i <= n; ++i)
    {
        ptr->next = new ListNode(i, NULL);
        ptr = ptr->next;
    }
    return head;
}

void print_n_randoms(Solution& sol, int n)
{
    for (int i = 1; i <= n; ++i)
        cout << "Random " << i << ": " << sol.getRandom() << endl;
    return;
}

void delete_list(ListNode* ptr)
{
    ListNode* tmp = ptr->next;
    if (tmp)
        delete_list(tmp);
    delete ptr;
}

int main()
{
    ListNode* list = create_list(30);
    Solution sol(list);
    print_n_randoms(sol, 30);
    delete_list(list);
    return 0;
}
