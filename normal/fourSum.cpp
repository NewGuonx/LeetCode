// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        if (nums.size() < 3)
            return res;
        int i, j, k, p, ta1, ta2, ta3;
        sort(nums.begin(), nums.end());
        for (i = 0; i < nums.size() - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            ta1 = target - nums[i];
            for (j = i + 1; j < nums.size() - 2; j++)
            {
                // if (j > i + 1 && nums[j] == nums[j - 1])
                //     continue;
                ta2 = ta1 - nums[j];
                for (k = j + 1; k < nums.size() - 1; k++)
                {
                    // if (k > j + 1 && nums[k] == nums[k - 1])
                    //     continue;
                    ta3 = ta2 - nums[k];
                    p = lower_bound(nums.begin() + k + 1, nums.end(), ta3) - nums.begin();
                    if (p == nums.size() || nums[p] != ta3)
                        continue;
                    else
                        res.push_back({nums[i], nums[j], nums[k], nums[p]});
                }
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