#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        if (matrix.empty() || matrix[0].empty()) return {};

        int m = (int)matrix.size(), n = (int)matrix[0].size();
        vector<int> answer;
        answer.reserve(m * n);

        int left = 0, right = n - 1, top = 0, bottom = m - 1;
        while (left <= right && top <= bottom)
        {
            for (int j = left; j <= right; ++j)
                answer.push_back(matrix[top][j]);
            ++top;

            for (int i = top; i <= bottom; ++i)
                answer.push_back(matrix[i][right]);
            --right;

            if (top <= bottom)
            {
                for (int j = right; j >= left; --j)
                    answer.push_back(matrix[bottom][j]);
                --bottom;
            }

            if (left <= right)
            {
                for (int i = bottom; i >= top; --i)
                    answer.push_back(matrix[i][left]);
                ++left;
            }
        }

        return answer;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    vector<int> answer = Solution().spiralOrder(matrix);
    for (int element: answer)
        cout << element << " ";
    cout << endl;
    return 0;
}
