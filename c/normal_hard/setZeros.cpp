// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        const int m = matrix.size(), n = matrix[0].size();
        vector<bool> row(m, false), col(n, false);
        int i, j;
        for (i = 0; i < m; i++)
            for (j = 0; j < n; j++)
                if (!matrix[i][j])
                    row[i] = col[j] = true;
        for (i = 0; i < m; i++)
            if (row[i])
                fill(&matrix[i][0], &matrix[i][0] + n, 0);
        for (j = 0; j < n; j++)
            if (col[j])
                for (i = 0; i < m; i++)
                    matrix[i][j] = 0;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}