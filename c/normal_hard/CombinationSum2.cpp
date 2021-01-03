
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
private:
    vector<vector<int>> ans;
    vector<int> tmp;

public:
    vector<vector<int>> combinationSum2(vector<int> &a, int target)
    {
        sort(a.begin(), a.end());
        int start = 0, end = upper_bound(a.begin(), a.end(), target) - a.begin();
        solve(a, start, end == a.size() ? end - 1 : end, target);
        return ans;
    }

private:
    void solve(vector<int> &a, int l, int r, int target)
    {
        if (target < 0)
            return;
        if (target == 0)
            ans.push_back(tmp);
        else
            for (int i = l; i <= r && a[i] <= target; i++)
            {
                if (i != l && a[i] == a[i - 1])
                    continue;
                tmp.push_back(a[i]);
                solve(a, i + 1, r, target - a[i]);
                tmp.pop_back();
            }
    }
};