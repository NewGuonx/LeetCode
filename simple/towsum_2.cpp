// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
  public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        vector<int> res;
        unordered_map<int, int> mp;
        for (int i = 0; i < numbers.size() ; i++)
            mp[numbers[i]] = i;
        for (int i = 0; i < numbers.size(); i++)
        {
            int dis = target - numbers[i];
            if ( mp.count(dis) && mp[dis] != i)
            {
                res.push_back(i + 1);
                res.push_back(mp[dis] + 1);
                break;
            }
        }
        return res;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}