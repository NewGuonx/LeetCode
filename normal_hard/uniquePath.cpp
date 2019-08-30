// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        //_m = m, _n = n;
        //return solve(1, 1);
        return C(m + n - 2, min(m - 1, n - 1));
    }

private:
    // int64_t _m, _n;
    int64_t fac(int64_t n, int64_t start = 1)
    {
        int64_t ret = 1;
        for (int i = start; i <= n; i++)
            ret *= i;
        return ret;
    }
    int64_t C(int64_t n, int64_t k)
    {
        if (k == 0)
            return 1;
        if (k == 1)
            return n;
        return fac(n, n - k + 1) / fac(k);
    }
    // int64_t solve(int64_t now_m, int64_t now_n)
    // {
    //     if (now_m == _m && now_n == _n)
    //         return 1;
    //     else if (now_m > _m || now_n > _n)
    //         return 0;
    //     return solve(now_m + 1, now_n) + solve(now_m, now_n + 1);
    // }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();

    return 0;
}