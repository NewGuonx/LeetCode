// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int one = 0, two = 0, thr = 0;
        for (auto i : nums)
        {
            two |= (i & one);
            one ^= i;
            thr = ~(one & two);
            one &= thr;
            two &= thr;
        }
        return one;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}