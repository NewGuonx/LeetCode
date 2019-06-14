// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        for (int i = triangle.size() - 2; i > -1; i--)
            for (int j = 0; j < i + 1; j++)
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
        return triangle[0][0];
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    
    return 0;
}