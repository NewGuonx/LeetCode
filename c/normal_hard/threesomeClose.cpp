// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int res = 0, flag = 0;
        int i, j, k, ta, tb;
        sort(nums.begin(), nums.end());
        for (i = 0; i < nums.size() - 2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            ta = target - nums[i];
            for (j = i + 1; j < nums.size() - 1; j++)
            {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                tb = ta - nums[j];
                int tmpres;
                k = lower_bound(nums.begin() + j + 1, nums.end(), tb) - nums.begin();
                if (k == nums.size())
                    k--;
                if (nums[k] == tb)
                {
                    return target;
                }
                else if (k - 1 != j && abs(tb - nums[k - 1]) < abs(tb - nums[k]))
                {
                    tmpres = nums[k - 1] + nums[i] + nums[j];
                }
                else
                {
                    tmpres = nums[k] + nums[i] + nums[j];
                }
                if (!flag)
                {
                    res = tmpres;
                    flag = 1;
                }
                else if (abs(tmpres - target) < abs(res - target))
                {
                    res = tmpres;
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
    Solution s;
    int b[] = {1, 1, 0, 1};
    vector<int> v(b, b + 4);
    cout << s.threeSumClosest(v, -100);
    return 0;
}