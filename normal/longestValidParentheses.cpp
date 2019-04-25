// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int start = -1, ans = 0, dis = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                ++dis;
            else
            {
                --dis;
                if (dis < 0)
                {
                    start = i;
                    dis = 0;
                }
                else if (dis == 0)
                    ans = max(ans, i - start);
            }
        }
        dis = 0, start = s.size();
        for (int i = s.size() - 1; i > -1; i--)
        {
            if (s[i] == ')')
                ++dis;
            else
            {
                --dis;
                if (dis < 0)
                {
                    start = i;
                    dis = 0;
                }
                else if (dis == 0)
                    ans = max(ans, start - i);
            }
        }
        return ans;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}