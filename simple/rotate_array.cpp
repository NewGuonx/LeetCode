// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
  public:
    void rotate(vector<int> &nums, int k)
    {
        if (k > nums.size())
            k %= nums.size();
        if (k == 0)
            return;
        vector<int> tmp;
        tmp.insert(tmp.end(), nums.end() - k, nums.end());
        tmp.insert(tmp.end(), nums.begin(), nums.end() - k);
        nums = tmp;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}