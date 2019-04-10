// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
  public:
    int numberOfBoomerangs(vector<pair<int, int>> &points)
    {
        int dis, _sum = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < points.size(); i++)
        {
            mp.clear();
            for (int j = 0; j < points.size(); j++)
            {
                if (i != j)
                {
                    dis = cal_dis(points, i, j);
                    mp[dis]++;
                }
            }
            for (auto j : mp)
            {
                int times = j.second;
                _sum += (times > 1 ? times * (times - 1) : 0);
            }
        }
        return _sum;
    }
    inline int cal_dis(vector<pair<int, int>> &points, int i, int j)
    {
        return pow(abs(points[i].first - points[j].first), 2) + pow(abs(points[i].second - points[j].second), 2);
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}