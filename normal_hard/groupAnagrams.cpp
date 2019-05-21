// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        string ori;
        for (auto &s : strs)
        {
            ori = s;
            sort(s.begin(), s.end());
            mp[s].push_back(ori);
        }
        for (auto i : mp)
            res.push_back(i.second);
        return res;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    string s;
    sort(s.begin(), s.end());

    return 0;
}
