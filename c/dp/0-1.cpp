// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
vector<int> w, d;
int n, m;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n >> m;
    w = vector<int>(n + 1);
    d = vector<int>(n + 1);
    vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));
    f[0] = vector<int>(n + 1, 1);
    /*
    
    f[i][j] = 前i个物品 总体积不超过j max价值总和

                    体积 M
    c    [0][0][0][0][0][0][0][0][0][0][0]
    h    [0][0][y][0][0][0][0][0][0][0][0]
 N  o    [0][0][0][0][0][0][0][0][0][0][0]
    o    [0][0][0][0][0][0][0][0][0][0][0]
    s    [0][0][x][t][0][0][0][0][0][0][0]
    e    [0][0][0][0][0][0][0][0][0][0][0]

     */
     
    int ans = f.back().back();

    return 0;
}