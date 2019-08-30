// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
  public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
            return false;
        return solve(s) == solve(t);
    }

    inline string solve(const string &s)
    {
        int init = 33;
        string res;
        unordered_map<char, int> mp;
        for (auto i : s)
        {
            if (mp.count(i))
                res.push_back(mp[i]);
            else
            {
                res.push_back(init);
                mp[i] = init++;
            }
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();

    return 0;
}