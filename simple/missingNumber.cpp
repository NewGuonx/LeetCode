// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
  public:
    int missingNumber(vector<int> &nums)
    {
        int xOR = nums.size();
        for (int i = 0; i < nums.size(); i++)
        {
            printf("%d XOR %d = %d \n", xOR, nums[i] ^ i, xOR ^ (nums[i] ^ i));
            xOR ^= (nums[i] ^ i);
        }
        return xOR;
    }
};
;
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Solution s;
    return 0;
}