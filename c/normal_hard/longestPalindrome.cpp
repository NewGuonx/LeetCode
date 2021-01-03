// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        string T(2 * s.size() + 1, '#');
        for (int i = 0; i < s.size(); i++)
            T[2 * i + 1] = s[i];
        T.push_back('$');
        T = "^" + T;
        const int n = T.length();
        int arr[n], center = 0, right = 0;
        for (int i = 1; i < n; i++)
        {
            arr[i] = (right > i) ? min(right - i, arr[2 * center - i]) : 0;
            while (T[i + 1 + arr[i]] == T[i - 1 - arr[i]])
                arr[i]++;
            if (i + arr[i] > right)
            {
                center = i;
                right = i + arr[i];
            }
        }
        int pos = max_element(arr + 1, arr + n) - arr;
        return s.substr((pos - 1 - arr[pos]) / 2, arr[pos]);
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Solution s;
    cout << s.longestPalindrome("111");
    return 0;
}