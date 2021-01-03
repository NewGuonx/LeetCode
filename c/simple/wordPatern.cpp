// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
  public:
    bool wordPattern(string pattern, string str)
    {
        string p1, p2, tmp;
        int c = 33, c1 = 33, c2 = 33;
        unordered_map<char, int> mp;
        unordered_map<string, int> mp1;
        for (auto i : pattern)
        {
            if (!mp.count(i))
            {
                mp[i] = c1;
                p1.push_back(c1++);
            }
            else
                p1.push_back(mp[i]);
        }
        stringstream ss(str);
        while (ss >> tmp)
        {
            if (!mp1.count(tmp))
            {
                mp1[tmp] = c2;
                p2.push_back(c2++);
            }
            else
                p2.push_back(mp1[tmp]);
        }
        return p1 == p2;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Solution s;
    cout << s.wordPattern("abcd", "abcd");

    return 0;
}