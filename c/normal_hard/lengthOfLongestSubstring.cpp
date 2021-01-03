// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        const int _MAX = 255;
        int last[_MAX];
        int start = 0;
        fill(last, last + _MAX, -1);
        int max_len = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (start <= last[s[i]])
            {
                max_len = max(i - start, max_len);
                start = last[s[i]] + 1;
            }
            last[s[i]] = i;
        }
        return max((int)s.size() - start, max_len);
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Solution s;
    cout << s.lengthOfLongestSubstring("vvvvvvv");
    return 0;
}