// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
  public:
    vector<string> v;
    int time[6] = {1, 2, 4, 8, 16, 32};
    vector<string> readBinaryWatch(int num)
    {
        dfs(0, 0, 0, num);
        return v;
    }
    void dfs(int index, int h, int m, int num)
    {
        if (!num)
        {
            if (m > 59 || h > 11) return;
            char s[3];
            sprintf(s, "%02d", m);
            v.push_back(to_string(h) + ":" + s);
        }
        else
        {
            for (int i = index; i < 11; ++i)
            {
                if (i < 6)
                {
                    m += time[i];
                    dfs(i + 1, h, m, num - 1);
                    m -= time[i];
                }
                else
                {
                    h += time[i - 6];
                    dfs(i + 1, h, m, num - 1);
                    h -= time[i - 6];
                }
            }
        }
        return;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}