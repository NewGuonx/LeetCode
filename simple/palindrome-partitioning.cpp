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
        this->ss = s;
        n = s.size();
        dfs(0);
        return ans;
    }

private:
    vector<vector<string>> ans;
    vector<string> path;
    string ss;
    int n;
    void dfs(int begin)
    {
        if (begin == n)
        {
            ans.push_back(path);
            return;
        }
        for (int i = begin; i < n; i++)
        {
            if (isPalin(begin, i))
            {
                path.push_back(ss.substr(begin, i - begin + 1));
                dfs(i + 1);
                path.pop_back();
            }
        }
    }
    bool isPalin(int lo, int hi)
    {
        while (lo < hi)
        {
            if (ss[lo] != ss[hi])
                return false;
            lo++, hi--;
        }
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}