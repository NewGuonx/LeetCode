// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
  public:
    void moveZeroes(vector<int> &nums)
    {
        stable_partition(nums.begin(), nums.end(), isZero);
    }
    bool isZero(int i){return i == 0;}
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}