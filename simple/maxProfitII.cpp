// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int sum = 0;
        for(int i = 1; i < prices.size(); i++){
            int dist_price = prices[i] - prices[i-1];
            if(dist_price > 0) sum += dist_price;
        }
        return sum;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}