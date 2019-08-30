
// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}

class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> tmp;

public:
    void solve(vector<int> &candidates, int remain_, int l, int r)
    {
        if (remain_ < 0 || l > r)
            return;
        if (remain_ == 0)
            ans.push_back(tmp);
        else
            for (int i = l; i <= r; i++)
            {
                tmp.push_back(candidates[i]);
                solve(candidates, remain_ - candidates[i], i, r);
                tmp.pop_back();
            }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        solve(candidates, target, 0, candidates.size() - 1);
        return ans;
    }
};