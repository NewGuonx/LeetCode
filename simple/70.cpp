// author - newguo@sonaspy.cn
// coding - utf_8

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <queue>
#include <numeric>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
  public:
    int climbStairs(int n)
    {
        int c1 = 1, c2 = 2, lockc1 = 0, lockc2 = 1;
        if(n == 1)return 1;
        for (int i = 3; i <= n; i++)
        {
            if (!lockc1)
            {
                c1 = c1 + c2;
                lockc1 = 1, lockc2 = 0;
            }
            else
            {
                c2 = c1 + c2;
                lockc2 = 1, lockc1 = 0;
            }
        }
        return max(c1,c2);
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Solution s;
    cout << s.climbStairs(2);
    return 0;
}