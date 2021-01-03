// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if (digits.empty()) return res;
        string s;
        dfs(res, s, digits, 0);
        return res;
    }
    void dfs(vector<string> &res, string &str, string &digits, int k)
    {
        if (str.size() == digits.size())
        {
            res.push_back(str);
            return;
        }
        string tmp = mp[digits[k]];
        for (char w : tmp)
        {
            str.push_back(w);
            dfs(res, str, digits, k + 1);
            str.pop_back();
        }
        return;
    }
    unordered_map<char, string> mp{{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}