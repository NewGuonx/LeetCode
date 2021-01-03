// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
vector<int> a;
int n, target;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n >> target;
    a = vector<int>(n + 1);
    vector<vector<int>> f(target + 1, vector<int>(n + 1, 0));
    f[0] = vector<int>(n + 1, 1);
    /*
    int ways(int w, int k)
    {
        if (w == 0)
            return 1;
        if (w < 0 || k <= 0)
            return 0;
        return ways(w, k - 1) + ways(w - a[k], k - 1);
    }
    f[w][k] 前k个凑出w的方法
                choose or not
    0    [1][1][1][1][1][1][1][1][1][1][1]
    1    [0][0][y][0][0][0][0][0][0][0][0]
    2    [0][0][0][0][0][0][0][0][0][0][0]
    3    [0][0][0][0][0][0][0][0][0][0][0]
    4    [0][0][x][t][0][0][0][0][0][0][0]
    
     */

    for (int w = 1; w <= target; w++)
    {
        for (int k = 1; k <= n; k++)
        {
            f[w][k] = f[w][k - 1];
            if (w - a[k] >= 0)
                f[w][k] += f[w - a[k]][k - 1];
        }
    }
    int ans = f.back().back();

    return 0;
}