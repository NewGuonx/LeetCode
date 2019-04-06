// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

class Solution
{
  public:
    bool isPerfectSquare(int num)
    {
        if (!num)
            return false;
        int lo = 1, hi = 46340;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (mid * mid < num)
                lo = mid + 1;
            else if (mid * mid > num)
                hi = mid - 1;
            else
                return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Solution s;
    return 0;
}