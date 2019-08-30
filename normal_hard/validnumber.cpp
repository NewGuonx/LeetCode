// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    bool isNumber(string s)
    {
        const char *ss = s.c_str();
        char *end;
        strtod(ss, &end);
        if (end == ss)
            return false;
        for (; *end; ++end)
            if (!isspace(*end))
                return false;
        return true;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    string s;
    cin >> s;
    Solution S;
    cout << S.isNumber(s);
    return 0;
}