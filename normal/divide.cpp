// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        long long a = dividend >= 0 ? dividend : -(long long)dividend;
        long long b = divisor >= 0 ? divisor : -(long long)divisor;
        long long result = 0;
        while (a >= b)
        {
            long long c = b;
            for (int i = 0; a >= c; i++, c <<= 1)
            {
                a -= c;
                result += 1 << i;
            }
        }
        return ((dividend ^ divisor) >> 31) ? (-result) : result;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Solution s;
    cout << s.divide((1 << 31) - 1, -(1 << 31));
    return 0;
}