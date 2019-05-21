// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < nums[right])
            {
                if (nums[mid] < target && nums[right] >= target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else
            {
                if (nums[left] <= target && nums[mid] > target)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return -1;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}