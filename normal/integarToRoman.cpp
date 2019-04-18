// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    string intToRoman(int num)
    {
        const int radix[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        const string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string ans;
        for(int i = 0; num > 0 ; ++i){
            for(int count = num / radix[i]; count > 0;--count)
                ans += symbols[i];
            num %= radix[i];
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Solution s;
    cout << s.intToRoman(100);
    return 0;
}