// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int __size = nums.size();
        for (int i = 0; i < __size; ++i)
        {
            while (0 < nums[i] && nums[i] <= __size && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for (int i = 0; i < __size; ++i)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return __size + 1;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}