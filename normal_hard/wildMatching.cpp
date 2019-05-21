// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        return isMatch(s.c_str(), p.c_str());
    }

private:
    bool isMatch(const char *s, const char *p)
    {
        bool sta = false;
        const char *str, *ptr;
        for (str = s, ptr = p; *str != '\0'; str++, ptr++)
        {
            switch (*ptr)
            {
            case '?':
                break;
            case '*':
                sta = true;
                s = str, p = ptr;
                while (*p == '*')
                    p++;
                if (*p == '\0')
                    return true;
                str = s - 1, ptr = p - 1;
                break;
            default:
                if (*str != *ptr)
                {
                    if (!sta)
                        return false;
                    s++, str = s - 1, ptr = p - 1;
                }
                break;
            }
        }
        while(*ptr == '*')ptr++;
        return (*ptr == '\0');
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}