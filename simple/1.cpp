// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <unordered_map>
#include <vector>
#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        vector<int> ans, nums = {-1, -2, -3, -4, -5};
        int target = -8;
        for (int i = 0; i < nums.size(); i++)
            mp[nums[i]] = i;
        for (int i = 0; i < nums.size(); i++)
        {
            const int another_num = target - nums[i];
            if (mp.count(another_num) && mp[another_num] != i)
            {
                ans.push_back(i);
                ans.push_back(mp[another_num]);
                break;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}