// author -sonaspy@outlook.com 
// coding - utf_8 

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#include<stack>
#include<queue>
#include<numeric>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
  public:
    int maxSubArray(vector<int> &nums)
    {
        int maxsum = -1, thissum = 0, maxNum = -2147483647, f = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
                f = 0;
            if (nums[i] > maxNum)
                maxNum = nums[i];
            thissum += nums[i];
            if (thissum > maxsum)
                maxsum = thissum;
            else if (thissum < 0)
                thissum = 0;
        }
        if (f)
            return maxNum;
        return maxsum;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();

    return 0;
}