// author -sonaspy@outlook.com
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
  public:
    bool isUgly(int num)
    {
        if (num < 2)
            return false;
        int nums[3] = {2, 3, 5};
        while (num)
        {
            if(num == 1) break;
            bool f = false;
            for (int i = 0; i < 3; i++)
            {
                if (num % nums[i] == 0)
                {
                    f = true;
                    num /= nums[i];
                    break;
                }
            }
            if(!f)return false;
        }
        return true;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    Solution s;
    cout << s.isUgly(6);
    return 0;
}