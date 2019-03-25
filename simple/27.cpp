// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>
#include<stack>
#include<queue>
#include<numeric>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
  public:
    int removeElement(vector<int> &nums, int val)
    {
        nums.erase(remove(nums.begin(),nums.end(),val), nums.end());
        return nums.size();
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}