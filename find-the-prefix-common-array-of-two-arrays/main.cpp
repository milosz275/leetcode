#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B)
    {
        set<int> seen;
        int n = (int)A.size();
        vector<int> prefix_common(n, 0);
        for (int i = 0; i < n; ++i)
        {
            if (!seen.empty() && seen.find(A[i]) != seen.end())
                prefix_common[i]++;
            else
                seen.insert(A[i]);
            
            if (!seen.empty() && seen.find(B[i]) != seen.end())
                prefix_common[i]++;
            else
                seen.insert(B[i]);

            if (i != 0)
                prefix_common[i] += prefix_common[i - 1];
        }
        return prefix_common;
    }
};

int main()
{
    vector<int> A = {1,3,2,4};
    vector<int> B = {3,1,2,4};
    vector<int> output = Solution().findThePrefixCommonArray(A, B);
    for (int el: output)
        cout << el << " ";
    cout << endl;
    return 0;
}
