// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        const int m = word1.size();
        const int n = word2.size();
        int f[n + 1][m + 1], i, j;
        for (i = 0; i < n + 1; i++)
            f[i][0] = i;
        for (i = 0; i < m + 1; i++)
            f[0][i] = i;
        for (i = 1; i < n + 1; i++)
        {
            for (j = 1; j < m + 1; j++)
            {
                int mn = min(f[i - 1][j], f[i][j - 1]);
                f[i][j] = word1[i - 1] == word2[j - 1] ? f[i - 1][j - 1] : min(mn, f[i - 1][j - 1]) + 1;
            }
        }
        return f[n][m];
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}