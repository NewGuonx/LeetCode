// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
  public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size(); i++){
            if(!mp.count(nums[i]))
                mp[nums[i]] = i;
            else{
                if(i - mp[nums[i]] <= k)
                    return true;
                else mp[nums[i]] = i;
            }
        }
        return false;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}