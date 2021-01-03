// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)
using namespace std;
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> res;
        vector<vector<int>>::iterator it;
        int f = 0;
        for (it = intervals.begin(); it != intervals.end(); it++)
        {
            if (newInterval.back() < it->front())
            {
                res.push_back(newInterval);
                f = 1;
                break;
            }
            if (newInterval.front() > it->back())
            {
                res.push_back(*it);
                continue;
            }
            newInterval.front() = min(it->front(), newInterval.front());
            newInterval.back() = max(it->back(), newInterval.back());
        }
        if (!f)
            res.push_back(newInterval);
        else
            res.insert(res.end(), it, intervals.end());
        return res;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}