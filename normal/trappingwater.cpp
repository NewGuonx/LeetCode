// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size(), res = 0, tmp;
        vector<int> left(n, 0), right(n, 0);
        for (int i = 1; i < n; i++)
        {
            left[i] = max(left[i - 1], height[i - 1]);
            right[n - 1 - i] = max(right[n - i], height[n - i]);
        }
        for (int i = 0; i < n; i++)
        {
            tmp = min(right[i], left[i]) - height[i];
            res += tmp > 0 ? tmp : 0;
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}