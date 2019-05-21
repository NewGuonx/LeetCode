#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        m = grid.size(), n = grid[0].size();
        this->f = vector<vector<int>>(m, vector<int>(n, -1));
        return dfs(grid, m - 1, n - 1);
    }

private:
    int m, n;
    vector<vector<int>> f;
    int dfs(const vector<vector<int>> &grid, int x, int y)
    {
        if (x < 0 || y < 0)
            return INT_MAX;
        if (x == 0 && y == 0)
            return grid[0][0];
        return min(get(grid, x - 1, y), get(grid, x, y - 1)) + grid[x][y];
    }
    int get(const vector<vector<int>> &grid, int x, int y)
    {
        if (x < 0 || y < 0)
            return INT_MAX;
        if (f[x][y] >= 0)
            return f[x][y];
        return f[x][y] = dfs(grid, x, y);
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}