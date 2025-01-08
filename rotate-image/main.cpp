#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    void transpose(vector<vector<int>>& matrix)
    {
        for (int i = 0; i < (int)matrix.size(); ++i)
        {
            for (int j = i + 1; j < (int)matrix.size(); ++j)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }

    void vertical_reflection(vector<vector<int>>& matrix)
    {
        int n = (int)matrix.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n / 2; ++j)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][n - 1 - j];
                matrix[i][n - 1 - j] = tmp;
            }
        }
    }

public:
    void print(vector<vector<int>>& matrix)
    {
        for (vector<int>& row: matrix)
        {
            for (int el: row)
                cout << el << " ";
            cout << endl;
        }
    }

    void rotate(vector<vector<int>>& matrix)
    {
        transpose(matrix);
        vertical_reflection(matrix);
    }
};

int main()
{
    vector<vector<int>> matrix = {{1,2,3}, {4,5,6}, {7,8,9}};
    Solution sol;
    // sol.print(matrix);
    sol.rotate(matrix);
    sol.print(matrix);
    return 0;
}
