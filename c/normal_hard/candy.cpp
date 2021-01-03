// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size(), inc, i;
        vector<int> f(n, 0);
        for (i = 1, inc = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])
                f[i] = max(f[i], inc++);
            else
                inc = 1;
        }
        for (i = n - 2, inc = 1; i > -1; i--)
        {
            if (ratings[i] > ratings[i + 1])
                f[i] = max(f[i], inc++);
            else
                inc = 1;
        }
        return accumulate(f.begin(), f.end(), n);
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}