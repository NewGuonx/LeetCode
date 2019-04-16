// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    int myAtoi(string str)
    {
        int num = 0, sign = 1, n = str.length(), i = 0;
        while (str[i] == ' ' && i < n)
            i++;
        if (str[i] == '+')
            i++;
        else if (str[i] == '-')
        {
            sign = -1;
            i++;
        }
        for (; i < n; i++)
        {
            if (str[i] < '0' || str[i] > '9')
                break;
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && (str[i] - '0') > 7))
                return sign == -1 ? INT_MIN : INT_MAX;
            num = num * 10 + (str[i] - '0');
        }
        return num * sign;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Solution s;
    cout << s.myAtoi("214748364677");
    return 0;
}