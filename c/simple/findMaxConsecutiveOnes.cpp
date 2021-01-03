// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int startcount = 0, _max = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                startcount = 0;
            else
            {
                startcount++;
                _max = max(startcount, _max);
            }
        }
        return _max;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();

    return 0;
}