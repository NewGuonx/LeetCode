// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
  public:
    int arrangeCoins(int n)
    {
        long long row = sqrt(n);
        while(value(row) < n)
            row++;
        return value(row) == n ? row : row-1;
    }
    inline long long value(long long r)
    {
        return (r + 1) * r / 2;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Solution s;
    cout << s.arrangeCoins(1804289383);
    return 0;
}