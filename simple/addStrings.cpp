// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
  public:
    string addStrings(string num1, string num2)
    {
        int carry = 0, now = 0, s = min(num1.size(), num2.size()), n;
        string res;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i = 0; i < s; i++)
        {
            n = (carry + num1[i] - '0' + num2[i] - '0');
            now = n % 10;
            carry = n / 10;
            res.push_back(now + '0');
        }
        for (int i = s; i < num1.size(); i++)
        {
            n = (carry + num1[i] - '0');
            now = n % 10;
            carry = n / 10;
            res.push_back(now + '0');
        }
        for (int i = s; i < num2.size(); i++)
        {
            n = (carry + num2[i] - '0');
            now = n % 10;
            carry = n / 10;
            res.push_back(now + '0');
        }
        if (carry)
            res.push_back('1');
        reverse(res.begin(), res.end());
        return res;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}