// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        vector<uint64_t> f(t.size() + 1);
        f[0] = 1;
        for (int i = 0; i < s.size(); ++i)
            for (int j = t.size() - 1; j > -1; --j)
                f[j + 1] += s[i] == t[j] ? f[j] : 0;
        return f[t.size()];
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}