// author - newguo@sonaspy.cn
// coding - utf_8

#include <bits/stdc++.h>

#define test() freopen("in", "r", stdin)

using namespace std;
class Solution
{
  public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int ,int> mp;
        for(auto & i : nums){
            ++mp[i];
            if(mp[i] > 1)return true;
        }
        return false;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    vector<int> v = {1,2,3,1};
    Solution s;
    cout << s.containsDuplicate(v);
    return 0;
}