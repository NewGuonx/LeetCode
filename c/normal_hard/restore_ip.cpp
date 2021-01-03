// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        this->s = s;
        dfs(0);
        return res;
    }

private:
    vector<string> res, ips;
    string s;
    void dfs(int walk)
    {
        if (ips.size() == 4 && walk == s.size())
        {
            res.push_back(ips[0] + '.' + ips[1] + '.' + ips[2] + '.' + ips[3]);
            return;
        }
        if (s.size() - walk > (4 - ips.size()) * 3 || s.size() - walk < 4 - ips.size())
            return;
        int num = 0;
        for (int i = walk; i < walk + 3; i++)
        {
            num = num * 10 + (s[i] - '0');
            if (num < 0 || num > 255)
                continue;
            ips.push_back(s.substr(walk, i + 1 - walk));
            dfs(i + 1);
            ips.pop_back();
            if (num == 0)
                break;
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}