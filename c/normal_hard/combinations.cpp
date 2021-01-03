// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        this->n = n, this->k = k;
        dfs(1, 0);
        return this->res;
    }

private:
    vector<int> path;
    vector<vector<int>> res;
    int n, k;
    void dfs(int start, int cur)
    {
        if (cur == k)
            res.push_back(path);
        for (int i = start; i <= n; i++)
        {
            path.push_back(i);
            dfs(i + 1, cur + 1);
            path.pop_back();
        }
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}