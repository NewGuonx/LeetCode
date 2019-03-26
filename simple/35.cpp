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
    int searchInsert(vector<int> &nums, int target)
    {
        int i;
        for(i = 0; i < nums.size();i++){
            if(target <= nums[i])break;
        }
        return i;

    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}