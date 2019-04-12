// author - newguo@sonaspy.cn 
// coding - utf_8 

#include<bits/stdc++.h>

#define test() freopen("in","r",stdin)

using namespace std;
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums2.size(); i++)
            mp[nums2[i]] = i;
        for (int i = 0; i < nums1.size(); i++)
        {
            int flag = 0;
            int j = mp[nums1[i]];
            for (; j < nums2.size(); j++)
            {
                if (nums1[i] < nums2[j])
                {
                    nums1[i] = nums2[j];
                    flag = 1;
                    break;
                }
            }
            if (!flag)
                nums1[i] = -1;
        }
        return nums1;
    }
};
int main(int argc, char const *argv[])
{
    /* code */
    //test();
    return 0;
}