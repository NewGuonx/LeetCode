// author -sonaspy@outlook.com 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
  public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        int maxtime = -1,maxnum;
        for(auto i: nums){
            mp[i]++;
            if(mp[i] > maxtime){
                maxtime = mp[i];
                maxnum = i;
            }
        }
        return maxnum;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}