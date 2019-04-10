// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
  public:
    bool repeatedSubstringPattern(string s)
    {
        if (s.empty())
            return false;
        vector<int> indexList;
        auto c = s[0];
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == c && s.size() % i == 0)
                indexList.push_back(i);
        }

        for (auto idx : indexList)
        {
            if (isValidSubstring(s, idx))
                return true;
        }
        return false;
    }
    bool isValidSubstring(const string &s, int index)
    {
        for (int j = index; j < s.size(); j++)
            if (s[j] != s[j % index])
                return false;
        return true;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}