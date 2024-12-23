#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    int hIndex(vector<int>& citations)
    {
        int length = (int)citations.size();
        if (length == 0)
            return 0;

        // h-index (f) = max { i e N : f(i) >= i }
        // we cannot use binary search due to list being not sorted. sorting and using binary search would consume more complexity than O(n)
        // let's use a vector to count citations i in count[i], so that when 2,2 will be saved to citation[2] = 2

        vector<int> count(length + 1, 0);
        for (int citation : citations)
        {
            if (citation >= length)
                count[length]++; // citation counts larger than length are stored in a last field of array
            else
                count[citation]++;
        }

        // for (int i = 0; i < length + 1; ++i)
        //     cout << "count[" << i << "]: " << count[i] << endl;

        int total = 0;
        // starting from last field ensures only-entries-bigger-than-length are handled properly in the first place
        for (int i = length; i >= 0; --i)
        {
            total += count[i];
            if (total >= i)
                return i;
        }

        return 0;
    }
};

int main()
{
    // vector<int> array = {3, 0, 6, 1, 5};
    // vector<int> array = {11, 15};
    vector<int> array = {1, 2, 0};
    Solution sol;
    cout << "h-index: " << sol.hIndex(array) << endl;
    return 0;
}
