// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
  public:
    int firstUniqChar(string s)
    {
        map<char, int> mp;
        for (auto i : s)
            mp[i]++;
        for (int i = 0; i < s.size(); i++)
            if (mp[s[i]] == 1)
                return i;
        return -1;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}