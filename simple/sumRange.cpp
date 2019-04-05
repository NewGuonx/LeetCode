// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class NumArray
{
  public:
    NumArray(vector<int> &nums)
    {
        __sum.resize(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); i++)
            __sum[i] = nums[i - 1] + __sum[i - 1];
    }

    int sumRange(int i, int j)
    {
        return __sum[j + 1] - __sum[i];
    }

  private:
    vector<int> __sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}