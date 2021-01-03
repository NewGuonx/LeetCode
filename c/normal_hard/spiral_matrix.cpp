// author -sonaspy@outlook.com
// coding - utf8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        if (!matrix.size())
            return res;
        int bx = 0, ex = matrix.size() - 1, i, j, by = 0, ey = matrix[0].size() - 1;
        while (true)
        {
            for (j = by; j <= ey; j++)
                res.push_back(matrix[bx][j]);
            if (++bx > ex)
                break;
            for (i = bx; i <= ex; i++)
                res.push_back(matrix[i][ey]);
            if (by > --ey)
                break;
            for (j = ey; j >= by; j--)
                res.push_back(matrix[ex][j]);
            if (bx > --ex)
                break;
            for (i = ex; i >= bx; i--)
                res.push_back(matrix[i][by]);
            if (++by > ey)
                break;
        }
        return res;
    }
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n));
        if (!n)
            return matrix;
        int num = 1, bx = 0, by = 0, ex = n - 1, ey = n - 1, i, j;
        while (true)
        {
            for (j = by; j <= ey; j++)
                matrix[bx][j] = num++;
            if (++bx > ex)
                break;
            for (i = bx; i <= ex; i++)
                matrix[i][ey] = num++;
            if (by > --ey)
                break;
            for (j = ey; j >= by; j--)
                matrix[ex][j] = num++;
            if (bx > --ex)
                break;
            for (i = ex; i >= bx; i--)
                matrix[i][by] = num++;
            if (++by > ey)
                break;
        }
        return matrix;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}