// author -sonaspy@outlook.com 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
  public:
    int minMoves(vector<int> &nums)
    {
        int sum = 0, min_ = *min_element(nums.begin(),nums.end());
        for(auto i : nums)
            sum += i - min_;
        return sum;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}