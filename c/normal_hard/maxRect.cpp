// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        if (!m)
            return 0;
        int n = matrix[0].size();
        vector<vector<int>> heights(m, vector<int>(n + 1));
        int i, j, res = 0, tmp, k;
        for (j = 0; j < n; j++)
            heights[0][j] = matrix[0][j] - '0';
        for (i = 1; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                    heights[i][j] = 1 + heights[i - 1][j];
            }
        }
        for (k = 0; k < m; k++)
        {
            heights[k].push_back(0);
            stack<int> s;
            for (i = 0; i < heights[k].size();)
            {
                if (s.empty() || heights[k][i] > heights[k][s.top()])
                    s.push(i++);
                else
                {
                    tmp = s.top(), s.pop();
                    res = max(res, heights[k][tmp] * (s.empty() ? i : i - s.top() - 1));
                }
            }
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}