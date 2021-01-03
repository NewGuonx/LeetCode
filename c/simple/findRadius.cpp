// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
  public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        sort(heaters.begin(), heaters.end());
        int ans = 0;
        for (int i = 0; i < houses.size(); i++)
        {
            int cur = INT_MAX, hs_i = houses[i];
            auto right = lower_bound(heaters.begin(), heaters.end(), hs_i);
            if (right != heaters.end())
            {
                cur = *right - hs_i;
            }
            if (right != heaters.begin())
            {
                auto left = right - 1;
                cur = min(cur, hs_i - *left);
            }
            ans = max(cur, ans);
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}