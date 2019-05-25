// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int c = 0, last = nums[0], cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != last)
            {
                last = nums[i];
                nums[c++] = nums[i];
                cnt = 1;
            }
            else
            {
                cnt++;
                if (cnt <= 2)
                    nums[c++] = nums[i];
            }
        }
        return c;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();

    return 0;
}