// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int maxprofit = 0, thismax = 0, startcount = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            int dist = prices[i] - prices[i - 1];
            thismax += dist;
            if (thismax > maxprofit)
                maxprofit = thismax;
            else if (thismax < 0)
                thismax = 0;
        }
        return maxprofit;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}