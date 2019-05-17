// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int res, last, cur, i;
        for (i = 0, cur = 0, last = 0, res = 0; i < nums.size(); i++)
        {
            if (i > last)
            {
                res++;
                last = cur;
            }
            cur = max(cur, i + nums[i]);
        }
        return res;
    }
    bool canJump(vector<int> &nums)
    {
        if (nums.empty())
            return true;
        int leftest = nums.size() - 1;
        for (int i = nums.size() - 2; i > -1; i--)
            if (i + nums[i] >= leftest)
                leftest = i;
        return leftest == 0;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}