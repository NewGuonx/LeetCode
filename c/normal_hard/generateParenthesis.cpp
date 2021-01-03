// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string s;
        if (n)
            gen(n, s, res, 0, 0);
        return res;
    }
    void gen(int &n, string &path, vector<string> &res, int l, int r)
    {
        if (l == n)
        {
            string s(path);
            res.push_back(s.append(n - r, ')'));
            return;
        }
        path.push_back('(');
        gen(n, path, res, l + 1, r);
        path.pop_back();
        if (r < l)
        {
            path.push_back(')');
            gen(n, path, res, l, r + 1);
            path.pop_back();
        }
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}