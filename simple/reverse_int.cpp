// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#define test() freopen("in", "r", stdin)

using namespace std;

class Solution
{
  public:
    int reverse(int x)
    {
        long long r = 0,
                  t = x;
        t = x > 0 ? t : -t;
        bool negtive = x > 0 ? false : true;
        string s = to_string(t);
        ::reverse(s.begin(), s.end());
        for (int i = s.size() - 1, c = 0; i > -1; i--, c++)
            r += (s[i] - '0') * pow(10, c);
        if (r > INT32_MAX || (negtive && r > 2147483648))
            return 0;
        return negtive ? -r : r;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Solution s;
    int num;
    cin >> num;
    int i = s.reverse(num);
    cout << i;
    return 0;
}