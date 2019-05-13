// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int res= 0, last = 0, cur = 0, i = 0;
        for(; i < nums.size(); i++){
            if(i > last){
                res++;
                last = cur;
            }
            cur = max(cur, i + nums[i]);
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