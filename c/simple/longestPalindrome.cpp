// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
  public:
    int longestPalindrome(string s)
    {
        int x[100] = {0}, odd_max = 0, even = 0, odd_sum = 0, c = 0;
        for (auto i : s)
            x[i - 'A']++;
        for (int i = 0; i < 100; i++)
        {
            if (x[i] != 0)
            {
                if (x[i] % 2 == 1 && x[i] > odd_max)
                {
                    odd_max = x[i];
                    c = i;
                }
                else if (x[i] % 2 == 0)
                    even += x[i];
            }
        }
        for (int i = 0; i < 100; i++)
        {
            if (i != c && x[i] % 2 == 1)
                odd_sum += x[i] - 1;
        }
        return odd_max + even + odd_sum;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    printf("%d",'A');
    return 0;
}