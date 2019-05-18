// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> res;
        if (intervals.empty())
            return res;
        sort(intervals.begin(), intervals.end(), [&](vector<int> a, vector<int> b) { return a.front() < b.front(); });
        int a1 = intervals.front()[0], a2 = intervals.front()[1];
        for (auto &it : intervals)
        {
            if (it.front() > a2)
            {
                res.push_back(vector<int>());
                res.back().push_back(a1), res.back().push_back(a2);
                a1 = it.front();
            }
            a2 = it.back() > a2 ? it.back() : a2;
        }
        res.push_back(vector<int>());
        res.back().push_back(a1), res.back().push_back(a2);
        return res;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}