// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
  public:
    int findNthDigit(int n)
    {
        if (n < 10)
            return n; //step 1
        long long length = 0, cnt = 9, i = 1;
        for (; length + cnt * i < n; ++i)
        { //step 2
            length += cnt * i;
            cnt *= 10;
        } //step 3
        long long num = pow(10, i - 1) - 1 + (n - length + 1) / i;
        return to_string(num)[(n - length - 1) % i] - '0';
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Solution s;
    cout << s.findNthDigit(19238);
    return 0;
}