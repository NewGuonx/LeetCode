// author -sonaspy@outlook.com 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
            result ^= nums[i];
        return result;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    cout <<(( 0 ^ 4));
    return 0;
}