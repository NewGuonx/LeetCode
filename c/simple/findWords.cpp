// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;

class Solution
{
public:
    vector<string> findWords(vector<string> &words)
    {
        unordered_map<char, int> mp;
        int line;
        string tmp;
        vector<string> res;
        mp['q'] = 1, mp['w'] = 1, mp['e'] = 1, mp['r'] = 1, mp['t'] = 1, mp['y'] = 1, mp['u'] = 1, mp['i'] = 1, mp['o'] = 1, mp['p'] = 1,
        mp['a'] = 2, mp['s'] = 2, mp['d'] = 2, mp['f'] = 2, mp['g'] = 2, mp['h'] = 2, mp['j'] = 2, mp['k'] = 2, mp['l'] = 2,
        mp['z'] = 3, mp['x'] = 3, mp['c'] = 3, mp['v'] = 3, mp['b'] = 3, mp['n'] = 3, mp['m'] = 3;
        for (auto i : words)
        {
            bool valid = true;
            tmp = i;
            transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
            line = mp[tmp[0]];
            for (auto j : tmp)
            {
                if (mp[j] != line)
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
                res.push_back(i);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}