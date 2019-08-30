// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
  public:
    bool isPalindrome(string s)
    {
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        string s1, s2;
        for (auto i : s)
        {
            if (isalnum(i))
                s1.push_back(i);
        }
        s2 = s1;
        std::reverse(s1.begin(), s1.end());
        return s2 == s1 ? true : false;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}