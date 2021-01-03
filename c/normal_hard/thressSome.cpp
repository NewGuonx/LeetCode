// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        if (nums.size() < 3)
            return res;
        int i, j, k;
        sort(nums.begin(), nums.end());
        for (i = 0; i < nums.size() - 2; i++)
        {
            if(i > 0 && nums[i] == nums[i-1] )continue;
            int target = -nums[i];
            for (j = i + 1; j < nums.size() - 1; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                k = lower_bound(nums.begin() + j + 1, nums.end(), target - nums[j]) - nums.begin();
                if (k == nums.size() || nums[k] != target - nums[j])
                    continue;
                else
                    res.push_back({nums[i], nums[j], nums[k]});
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