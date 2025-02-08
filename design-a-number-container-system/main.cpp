#include <bits/stdc++.h>

using namespace std;

class NumberContainers
{
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> nums; // (number, smallest index)
    unordered_map<int, int> index_to_num; // (index, number)

public:
    NumberContainers() {}
    
    void change(int index, int number)
    {
        if (index_to_num.find(index) != index_to_num.end())
        {
            int old_num = index_to_num[index];
            if (old_num != number) // mark old index as invalid
                nums[old_num].push(INT_MAX);
        }
        index_to_num[index] = number;
        nums[number].push(index);
    }
    
    int find(int number)
    {
        while (!nums[number].empty() && index_to_num[nums[number].top()] != number)
            nums[number].pop(); // remove invalid indices
        if (nums[number].empty())
            return -1;
        else
            return nums[number].top();
    }
};

int main()
{
    NumberContainers n;
    cout << n.find(10) << '\n';
    n.change(2, 10);
    n.change(1, 10);
    n.change(3, 10);
    n.change(5, 10);
    cout << n.find(10) << '\n';
    n.change(1, 20);
    cout << n.find(10) << '\n';
    return 0;
}
