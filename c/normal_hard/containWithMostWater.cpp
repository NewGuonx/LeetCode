// author -sonaspy@outlook.com 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{//most water
public:
    int maxArea(vector<int> &height)
    {
        int res = -1;
        for(int left = 0, right = height.size() - 1; left <= right;){
            int s = (right - left) * min(height[left], height[right]);
            res = max(res, s);
            if(height[left] <= height[right])
                left++;
            else right--;
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