// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    double myPow(double x, int n)
    {
        long long N = n;
        if (N < 0)
        {
            x = 1 / x;
            N = -N;
        }
        double ans = 1;
        double cur = x;
        for (long long i = N; i; i /= 2)
        {
            if ((i % 2) == 1)
                ans *= cur;
            cur *= cur;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}