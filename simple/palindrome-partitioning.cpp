// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        if (s.empty())
            return ans;
        this->tmp_s = s;
        n = s.size();
        dfs(0);
        return ans;
    }

private:
    vector<vector<string>> ans;
    vector<string> path;
    string tmp_s;
    int n;
    void dfs(int cur)
    {
        if (cur == n)
        {
            ans.push_back(path);
            return;
        }
        for (int walk = cur; walk < n; walk++)
        {
            if (isPalin(cur, walk))
            {
                path.push_back(tmp_s.substr(cur, walk - cur + 1));
                dfs(walk + 1);
                path.pop_back();
            }
        }
    }
    bool isPalin(int lo, int hi)
    {
        while (lo < hi)
        {
            if (tmp_s[lo] != tmp_s[hi])
                return false;
            lo++, hi--;
        }
        return true;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}