// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int j = -1, i, remain = 0, sum = 0;
        for (i = 0; i < gas.size(); i++)
        {
            remain += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if (remain < 0)
            {
                remain = 0;
                j = i;
            }
        }
        return sum >= 0 ? j + 1 : -1;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}