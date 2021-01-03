// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> dict;
        for (auto &i : wordDict)
            dict.insert(i);
        vector<bool> f(s.size() + 1, 0);
        f[0] = true;
        for(int i = 1; i <= s.size(); i++)
            for(int j = i -1; j > -1; j--){
                if(f[j] && dict.count(s.substr(j, i-j))){
                    f[i] = 1;
                    break;
                }
            }
        return f.back();
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}