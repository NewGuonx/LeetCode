// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;
        const int n = prices.size();
        vector<int> f(n, 0);
        vector<int> g(n, 0);

        for (int i = 1, valley = prices[0]; i < n; ++i)
        {
            valley = min(valley, prices[i]);
            f[i] = max(f[i - 1], prices[i] - valley);
        }
        for (int i = n - 2, peak = prices[n - 1]; i > -1; --i)
        {
            peak = max(peak, prices[i]);
            g[i] = max(g[i], peak - prices[i]);
        }
        int max_s = 0;
        for (int i = 0; i < n; ++i)
            max_s = max(max_s, f[i] + g[i]);
        return max_s;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}