// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
  public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int row = grid.size(), col = grid[0].size();
        int ver = 0, edg = 0;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j])
                {
                    ver++;
                    if (j < col - 1 && grid[i][j + 1])
                        edg++;
                    if (j > 0 && grid[i][j - 1])
                        edg++;
                    if (i < row - 1 && grid[i + 1][j])
                        edg++;
                    if (i > 0 && grid[i - 1][j])
                        edg++;
                }
            }
        return 4 * ver - edg;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}