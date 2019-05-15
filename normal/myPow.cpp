// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    double _myPow(double x, int n)
    {
        if (!n)
            return 1.0;
        double num;
        if (n % 2)
        {
            num = _myPow(x, n / 2);
            return num * num * x;
        }
        num = _myPow(x, n / 2);
        return num * num;
    }
    double myPow(double x, int n)
    {
        double res = _myPow(x, n);
        return n < 0 ? 1 / res : res;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}