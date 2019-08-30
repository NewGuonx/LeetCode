// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
struct node
{
    int i, j, val;
    node(int i, int j, int val) : i(i), j(j), val(val) {}
    bool cmp(const node &b) const { return val < b.val; }
};
int I, J, n;
vector<vector<int>> f, H;
vector<node> v;
inline void solve(int i, int j)
{
    if (i < 0 || j < 0 || i >= n || j >= n)
        return;
    if (H[I][J] < H[i][j])
        f[i][j] = max(f[i][j], f[I][J] + 1);
}
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cin >> n;
    f = vector<vector<int>>(n, vector<int>(n, 1));
    H = f;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> H[i][j];
            v.push_back(node(i, j, H[i][j]));
        }
    sort(v.begin(), v.end());
    for (auto &it : v)
    {
        I = it.i, J = it.j;
        solve(I - 1, J), solve(I + 1, J), solve(I, J - 1), solve(I, J + 1);
    }
    return 0;
}