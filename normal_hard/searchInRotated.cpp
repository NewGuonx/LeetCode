// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int lo = 0, hi = nums.size() - 1;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < nums[hi])
            {
                if (nums[mid] < target && target <= nums[hi])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
            else
            {
                if (nums[lo] <= target && target < nums[mid])
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
        }
        return -1;
    }
    //with duplicates
    bool search2(vector<int> &nums, int target)
    {
        int lo = 0, hi = nums.size();
        while (lo != hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[lo] < nums[mid])
            {
                if (nums[lo] <= target && target <= nums[mid])
                    hi = mid;
                else
                    lo = mid + 1;
            }
            else if (nums[lo] > nums[mid])
            {
                if (nums[mid] < target && target <= nums[hi - 1])
                    lo = mid + 1;
                else
                    hi = mid;
            }
            else
                lo++;
        }
        return false;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}