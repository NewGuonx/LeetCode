// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        M = obstacleGrid.size(), N = obstacleGrid[0].size();
        if (obstacleGrid.empty() || obstacleGrid[0][0] || obstacleGrid[M - 1][N - 1])
            return 0;
        f = vector<vector<int>>(M, vector<int>(N, 0));
        f[0][0] = obstacleGrid[0][0] ? 0 : 1;
        return dfs(obstacleGrid, M - 1, N - 1);
    }

private:
    int M, N;
    vector<vector<int>> f;
    int dfs(vector<vector<int>> &grid, int x, int y)
    {
        if (x < 0 || y < 0 || grid[x][y] == 1)
            return 0;
        if (x == 0 && y == 0)
            return f[0][0];
        return f[x][y] > 0 ? f[x][y] : f[x][y] = dfs(grid, x - 1, y) + dfs(grid, x, y - 1);
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}