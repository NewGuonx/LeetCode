// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    string s1, s2;
    const int n = 1000, m = 1000;
    vector<vector<int>> f(n, vector<int>(m, 0));

    // f[0] = vector<int>(m, 0);
    // for (int i = 0; i < n; i++)
    //     f[i][0] = 0;
    /*
    [0][0][0][0][0][0][0][0][0][0][0]
    [0][x][x][x][x][x][x][x][x][x][x]
    [0][x][x][x][x][x][x][x][x][x][x]
    [0][x][x][x][x][x][x][x][x][x][x]
    [0][x][x][x][x][x][x][x][x][x][x]
     */

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (s1[i - 1] == s2[i - 1])
                f[i][j] = f[i - 1][j - 1] + 1;
            else
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        }
    }
    int maxlen = f.back().back();
    return 0;
}