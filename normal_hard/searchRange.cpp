// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int t1 = -1, t2 = -1;
        t2 = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (!t2 || nums[t2 - 1] != target)
            return vector<int>(2, -1);
        t1 = --t2;
        while (t1 > -1 && nums[t1] == target)
            t1--;
        vector<int> res;
        res.push_back(t1), res.push_back(t2);
        return res;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}